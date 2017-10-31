#include "GameController.h"

GameController::GameController(QQmlApplicationEngine* engine) : m_engine(engine),
    m_isPlayer1Turn(true),
    m_currentGameState(CONTINUE),
    m_currentGameMode(MODE_NONE),
    m_networkConnection(NULL),
    m_isAllowSendData(false),
    m_gameTitle(strGameTitle){
    m_engine->rootContext()->setContextProperty("gameGridViewModel", & m_gameModel.m_gameGridViewModel);
    m_engine->rootContext()->setContextProperty("listGameReplay",&m_gameModel.m_listViewReplayModel);
}

GameController::~GameController() {
    if(m_networkConnection){
        delete m_networkConnection;
    }
}

bool GameController::isPlayer1Turn() const {
    return m_isPlayer1Turn;
}

void GameController::setIsPlayer1Turn(bool isPlayer1Turn){
    m_isPlayer1Turn = isPlayer1Turn;
    emit isPlayer1TurnChanged();
}

int GameController::currentGameState() const {
    return m_currentGameState;
}

void GameController::setCurrentGameState(int currentGameState){
    m_currentGameState = currentGameState;
    emit isCurrentGameStateChanged();
}

int GameController::currentGameMode() const {
    return m_currentGameMode;
}

void GameController::setCurrentGameMode(int currentGameMode) {
    m_currentGameMode = currentGameMode;
    emit isCurrentGameModeChanged();
}

bool GameController::isAllowSendData() const {
    return m_isAllowSendData;
}

void GameController::setIsAllowSendData(bool isAllowSendData) {
    m_isAllowSendData = isAllowSendData;
}

QString GameController::gameTitle() const {
    return m_gameTitle;
}

void GameController::setGameTitle(const QString &gameTitle) {
    m_gameTitle = gameTitle;
    emit isGameTitleChanged();
}


void GameController::clickedGameCell(int index) {

    if(currentGameMode() == MODE_NONE || (currentGameMode() == MODE_ONLINE && !isAllowSendData())) {
        return; // diable click when no game mode selected
    }

    if(m_gameModel.m_gameGridViewModel.getGameBoardCellAtIndex(index).text() == strBlank){

        m_gameModel.m_gameGridViewModel.updateGameBoardCell(index, m_isPlayer1Turn);

        QString gameBoard[SIZE_GAME][SIZE_GAME];
        m_gameModel.convertListModelToTwoDimensons(gameBoard);

        auto row = index/SIZE_GAME;
        auto col = index - row*SIZE_GAME;
        Move move(row,col);

        // only save turn on offline mode
        if(currentGameMode() == MODE_OFFLINE){
            if(m_isPlayer1Turn){
                m_gameModel.arrPlayer[PLAYER1].addMoveToList(move);
            } else {
                m_gameModel.arrPlayer[PLAYER2].addMoveToList(move);
            }
        }

        setCurrentGameState(checkGameState(gameBoard,move));
        setIsPlayer1Turn(!m_isPlayer1Turn);

        // check mode is online and next turn is player 2 to send data
        if(currentGameMode() == MODE_ONLINE){
            if(m_networkConnection){
                QString message = QString::number(move.getRow()) + "." + QString::number(move.getCol()); // encode player move
                m_networkConnection->sendMessage(message);
                setIsAllowSendData(false);
            }
        }

        // check game continue and mode is offline to save this game
        if(currentGameState() != CONTINUE && currentGameMode() == MODE_OFFLINE){
            saveGamePlayeToJsonFile(m_gameModel.arrPlayer);
        }
    }
}

void GameController::clickedBtnReset(){

    // check if current mode not equal NONE to reset game
    if(currentGameMode() != MODE_NONE){
        qDebug() << "Reset";
        m_gameModel.resetGame();
        setIsPlayer1Turn(true);
        setCurrentGameState(CONTINUE);
        setCurrentGameMode(MODE_NONE);
        setIsAllowSendData(false);
        setGameTitle(strGameTitle);
        if(m_networkConnection){
            delete m_networkConnection;
            m_networkConnection = NULL;
        }
    }
}

void GameController::clickedBtnUndo(){
    if(currentGameMode() != MODE_OFFLINE) return; // only undo if mode game is offline

    qDebug() << "Undo";
    int id = 0;
    Move undoMove;
    if(m_isPlayer1Turn){
        // if next turn is Player 1. mean previous turn is player 2. so remove player 2's move
        if(m_gameModel.arrPlayer[PLAYER2].listMove().count() > 0){
            undoMove = m_gameModel.arrPlayer[PLAYER2].listMove().at(m_gameModel.arrPlayer[PLAYER2].listMove().count()-1);
            id = undoMove.getRow() * SIZE_GAME + undoMove.getCol();
            m_gameModel.arrPlayer[PLAYER2].removeMoveFromList(m_gameModel.arrPlayer[PLAYER2].listMove().count()-1);
        } else {
            return;
        }
    } else {
        if(m_gameModel.arrPlayer[PLAYER1].listMove().count() > 0){
            undoMove = m_gameModel.arrPlayer[PLAYER1].listMove().at(m_gameModel.arrPlayer[PLAYER1].listMove().count()-1);
            id = undoMove.getRow() * SIZE_GAME + undoMove.getCol();
            m_gameModel.arrPlayer[PLAYER1].removeMoveFromList(m_gameModel.arrPlayer[PLAYER1].listMove().count()-1);
        } else {
            return;
        }
    }

    // set true to allow undo move
    m_gameModel.m_gameGridViewModel.updateGameBoardCell(id,true,true);
    setIsPlayer1Turn(!m_isPlayer1Turn);
}

void GameController::moveItemInModel(int fromID, int toID){
    m_gameModel.m_gameGridViewModel.moveCellInGameBoard(fromID,toID);
}

void GameController::selectGameToReplay() {
    setCurrentGameMode(MODE_REPLAY);
    m_gameModel.initListGameReplay();
}

void GameController::startOfflineGame(QString strPlayer1Name, QString strPlayer2Name) {
    setCurrentGameMode(MODE_OFFLINE);
    m_gameModel.arrPlayer[PLAYER1].setName(strPlayer1Name);
    m_gameModel.arrPlayer[PLAYER2].setName(strPlayer2Name);
}

void GameController::startVsComGame() {
    setCurrentGameMode(MODE_VSCOMPUTER);
}

void GameController::startOnlineGame(QString ipAddress, QString port) {
    setCurrentGameMode(MODE_ONLINE);
    if((ipAddress == "") | (port == "") ){
        m_networkConnection = new ServerConnection();

        QString gameTitle = m_networkConnection->ipAddress() + " - " + QString::number(m_networkConnection->port());
        setGameTitle(gameTitle);
    } else {
        m_networkConnection = new ClientConnection();
        m_networkConnection->setUpWithIpAndPort(ipAddress,port.toInt());

        setIsAllowSendData(true);
    }

    // connect signal to game controller when current message changed
    connect(m_networkConnection,&NetworkConnection::isCurrentMessageChanged,this,&GameController::makeMoveIfMessageChanged);
}

void GameController::replaySelectedGame(int gameIndex)
{
    GameReplay selectedGameReplay = m_gameModel.m_listViewReplayModel.getGameReplayAtIndex(gameIndex);
    for(int index=0; index < (int)selectedGameReplay.arrPlayer[PLAYER1].listMove().size(); index++){
        Move move = selectedGameReplay.arrPlayer[PLAYER1].listMove().at(index);
        int indexOfMove = move.getRow() * SIZE_GAME + move.getCol();
        //        QTest::qWait(500);
        clickedGameCell(indexOfMove);
        if(index < (int)selectedGameReplay.arrPlayer[PLAYER2].listMove().size()){
            move = selectedGameReplay.arrPlayer[PLAYER2].listMove().at(index);
            indexOfMove = move.getRow() * SIZE_GAME + move.getCol();
            //            QTest::qWait(500);
            clickedGameCell(indexOfMove);
        }
    }
}

int GameController::checkGameState(QString gameBoard[SIZE_GAME][SIZE_GAME], Move move){
    int countSameNeighbour = 0;
    int direction = LEFT;
    Move currentMove = move;

    while(countSameNeighbour < WIN_RULE-1){
        if(findNeighbour(gameBoard,currentMove, direction) == 1){
            countSameNeighbour++;
        } else {
            switch (direction){
                case LEFT: case LEFT_UP: case UP: case RIGHT_UP:
                    direction = direction + 4; // change to opposite direction
                    break;
                case RIGHT: case RIGHT_DOWN: case DOWN:
                    direction = direction - 3; // reset to opposite direction and increase direction by 1
                    countSameNeighbour = 0;
                    break;
                case LEFT_DOWN: // final direction, no other choice
                    // check game is draw here
                    for(int row=0;row <SIZE_GAME;row++){
                        for(int col=0;col <SIZE_GAME;col++){
                            if(gameBoard[row][col] == strBlank)
                                return CONTINUE;
                        }
                    }
                    return DRAW;
                    break;
                default:
                    return CONTINUE;
                    break;
            }
            currentMove = move;
        }
    }

    if(gameBoard[move.getRow()][move.getCol()] == strX){
        return PLAYER1_WIN;
    } else if(gameBoard[move.getRow()][move.getCol()] == strO){
        return PLAYER2_WIN;
    }

    return DRAW; // default draw

}

int GameController::findNeighbour(QString gameBoard[SIZE_GAME][SIZE_GAME], Move &move, int direction){
    // left
    if(direction == LEFT && move.getCol() -1 >= 0){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()][move.getCol()-1]){
            move.setCol(move.getCol() -1);
            return 1;
        }
    }

    // right
    if(direction == RIGHT && move.getCol() + 1 < SIZE_GAME){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()][move.getCol()+1]){
            move.setCol(move.getCol() +1);
            return 1;
        }
    }

    // up
    if(direction == UP && move.getRow() -1 >= 0){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()-1][move.getCol()]){
            move.setRow(move.getRow() -1);
            return 1;
        }
    }

    // down
    if(direction == DOWN && move.getRow() + 1 < SIZE_GAME){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()+1][move.getCol()]){
            move.setRow(move.getRow() + 1);
            return 1;
        }
    }

    // left up
    if(direction == LEFT_UP && move.getRow() - 1 >= 0 && move.getCol() - 1 >= 0){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()-1][move.getCol()-1]){
            move.setRow(move.getRow() - 1);
            move.setCol(move.getCol() - 1);
            return 1;
        }
    }

    // left down
    if(direction == LEFT_DOWN && move.getRow() + 1 < SIZE_GAME && move.getCol() - 1 >= 0){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()+1][move.getCol()-1]){
            move.setRow(move.getRow() + 1);
            move.setCol(move.getCol() - 1);
            return 1;
        }
    }
    //switch (checkGameState(arrMatrix)) {

    // right down
    if(direction == RIGHT_DOWN && move.getRow() + 1 < SIZE_GAME && move.getCol() + 1 < SIZE_GAME){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()+1][move.getCol()+1]){
            move.setRow(move.getRow() + 1);
            move.setCol(move.getCol() + 1);
            return 1;
        }
    }

    // right up
    if(direction == RIGHT_UP && move.getRow() - 1 >= 0 && move.getCol() + 1 < SIZE_GAME){
        if(gameBoard[move.getRow()][move.getCol()] == gameBoard[move.getRow()-1][move.getCol()+1]){
            move.setRow(move.getRow() - 1);
            move.setCol(move.getCol() + 1);
            return 1;
        }
    }

    return 0;
}

// save player data to json to replay
void GameController::saveGamePlayeToJsonFile(Player arrPlayer[NUMBER_PLAYER]) {
    // load json use QFile
    //    QFile file(nameFileSaveGame);

    //    // open file to read
    //    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;

    //    QTextStream in(&file);

    //    const char* arrInputFromFile = in.readAll().toStdString().c_str();

    // load json use ifstream
    ifstream file( nameFileSaveGame.toStdString().c_str());
    stringstream buffer;

    if(file)
    {
        buffer << file.rdbuf();
        file.close();
    }

    Document document,tmpDocument;
    document.Parse(buffer.str().c_str());


    // create a temp document and push it back to current document.
    tmpDocument.SetArray();
    for(int indexPlayer=0; indexPlayer<NUMBER_PLAYER; indexPlayer++){
        Value objPlayerValue(kObjectType);
        Value listMove(kArrayType);
        for(int indexMove=0; indexMove<(int)arrPlayer[PLAYER1].listMove().size(); indexMove++){
            if(indexMove<(int)arrPlayer[indexPlayer].listMove().size()){
                Value objMove(kObjectType);
                Move tmpMove = arrPlayer[indexPlayer].listMove().at(indexMove);
                objMove.AddMember("row", tmpMove.getRow(),tmpDocument.GetAllocator());
                objMove.AddMember("col", tmpMove.getCol(),tmpDocument.GetAllocator());
                listMove.PushBack(objMove,document.GetAllocator());
            }
        }

        // save name
        Value keyName("name", tmpDocument.GetAllocator());
        Value valueName(arrPlayer[indexPlayer].name().toStdString().c_str(), tmpDocument.GetAllocator());
        objPlayerValue.AddMember(keyName,valueName,tmpDocument.GetAllocator());

        // save list move
        objPlayerValue.AddMember("listMove",listMove,tmpDocument.GetAllocator());

        // push back to temp document
        tmpDocument.PushBack(objPlayerValue,tmpDocument.GetAllocator());
    }

    // push back to root document
    document.PushBack(tmpDocument,tmpDocument.GetAllocator());
    StringBuffer strbuf;
    PrettyWriter<StringBuffer> writer(strbuf);
    document.Accept(writer);

    // open file use QFile to read write and truncate to clear file before write
    //    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) return;
    //    QTextStream out(&file);
    //    out << strbuf.GetString();
    //    file.close();

    // write to file use ofstream
    ofstream out(nameFileSaveGame.toStdString().c_str());
    out << strbuf.GetString();
    out.close();
}

void GameController::makeMoveIfMessageChanged() {
    if(m_networkConnection){
        Move receivedMove = m_networkConnection->convertCurrentMessageToMove();
        int index = receivedMove.getRow() * SIZE_GAME + receivedMove.getCol();

        //        clickedGameCell(index);
        m_gameModel.m_gameGridViewModel.updateGameBoardCell(index, m_isPlayer1Turn);

        QString gameBoard[SIZE_GAME][SIZE_GAME];
        m_gameModel.convertListModelToTwoDimensons(gameBoard);

        auto row = index/SIZE_GAME;
        auto col = index - row*SIZE_GAME;
        Move move(row,col);
        setCurrentGameState(checkGameState(gameBoard,move));
        setIsPlayer1Turn(!m_isPlayer1Turn);
        setIsAllowSendData(true);
    }
}

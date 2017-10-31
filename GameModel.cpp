#include "GameModel.h"

GameModel::GameModel() {
    // init gridview model
    initGameGridViewModel();
}

void GameModel::resetGame(){
    m_gameGridViewModel.removeAllCellInGameBoard();
    initGameGridViewModel();
}

void GameModel::initGameGridViewModel(){
    for(int i =0; i<100; i++){
        m_gameGridViewModel.addGameBoardCell(GameBoardCell(strBlank));
    }
}

void GameModel::convertListModelToTwoDimensons(QString gameBoard[SIZE_GAME][SIZE_GAME]){
    for(int i=0; i<m_gameGridViewModel.rowCount(); i++){
        auto row = i/SIZE_GAME;
        auto col = i - row*SIZE_GAME;
        gameBoard[row][col] = m_gameGridViewModel.getGameBoardCellAtIndex(i).text();
    }
}

void GameModel::initListGameReplay() {
    m_listViewReplayModel.clearListGameReplay(); // clear data before load file

    // load json use QFile
    //    QFile file(nameFileSaveGame);

    //    // open file to read
    //    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //        qDebug()<<file.errorString();
    //        return;
    //    }

    //    QTextStream in(&file);

    //    const char* arrInputFromFile = in.readAll().toStdString().c_str();

    //    file.flush();
    //    file.close();

    // load file use ifstream
    ifstream file(nameFileSaveGame.toStdString().c_str());
    stringstream buffer;

    if(file)
    {
        buffer << file.rdbuf();
        file.close();
    }

    Document document;
    document.Parse(buffer.str().c_str());
    if(document.Size() > 0){
        for(int idDoc=0; idDoc<(int)document.Size(); idDoc++){
            GameReplay tmpGameReplay;
            for (int indexPlayer=0; indexPlayer<2; indexPlayer++){
                tmpGameReplay.arrPlayer[indexPlayer].setName(document[idDoc][indexPlayer]["name"].GetString());

                // cast player move
                for (SizeType indexMove = 0; indexMove < document[idDoc][indexPlayer]["listMove"].Size(); indexMove++){
                    Move tmpMove = Move();
                    tmpMove.setRow(document[idDoc][indexPlayer]["listMove"][indexMove]["row"].GetInt());
                    tmpMove.setCol(document[idDoc][indexPlayer]["listMove"][indexMove]["col"].GetInt());
                    tmpGameReplay.arrPlayer[indexPlayer].addMoveToList(tmpMove);
                }
            }

            if(tmpGameReplay.arrPlayer[PLAYER1].name() == "") {
                tmpGameReplay.arrPlayer[PLAYER1].setName("undefined");
            }

            if(tmpGameReplay.arrPlayer[PLAYER2].name() == "") {
                tmpGameReplay.arrPlayer[PLAYER2].setName("undefined");
            }

            tmpGameReplay.setTitle(tmpGameReplay.arrPlayer[PLAYER1].name() + " vs "
                                   + tmpGameReplay.arrPlayer[PLAYER2].name());
            m_listViewReplayModel.addGameReplayToList(tmpGameReplay);
        }
    }
}

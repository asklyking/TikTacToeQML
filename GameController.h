#ifndef TIKTACTOE_H
#define TIKTACTOE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QTest>

#include <fstream>
#include <sstream>
#include <cstring>

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include "GameGridViewModel.h"
#include "GameModel.h"
#include "Constants.h"
#include "Utils.h"
#include "Move.h"
#include "NetworkConnection.h"
#include "ClientConnection.h"
#include "ServerConnection.h"
#include "Player.h"

using namespace rapidjson;
using namespace std;

class GameController : public QObject {

        Q_OBJECT
    public:
        GameController(QQmlApplicationEngine* engine);
        ~GameController();

        Q_PROPERTY(bool isPlayer1Turn READ isPlayer1Turn WRITE setIsPlayer1Turn NOTIFY isPlayer1TurnChanged)
        Q_PROPERTY(int currentGameState READ currentGameState WRITE setCurrentGameState NOTIFY isCurrentGameStateChanged)
        Q_PROPERTY(int currentGameMode READ currentGameMode WRITE setCurrentGameMode NOTIFY isCurrentGameModeChanged)
        Q_PROPERTY(QString gameTitle READ gameTitle WRITE setGameTitle NOTIFY isGameTitleChanged)

        Q_INVOKABLE void clickedGameCell(int index);
        Q_INVOKABLE void clickedBtnReset();
        Q_INVOKABLE void clickedBtnUndo();
        Q_INVOKABLE void moveItemInModel(int fromID, int toID);
        Q_INVOKABLE void replaySelectedGame(int gameIndex);
        Q_INVOKABLE void selectGameToReplay();
        Q_INVOKABLE void startOfflineGame(QString strPlayer1Name, QString strPlayer2Name);
        Q_INVOKABLE void startVsComGame();
        Q_INVOKABLE void startOnlineGame(QString ipAddress, QString port);

        int checkGameState(QString gameBoard[SIZE_GAME][SIZE_GAME],Move move);
        int findNeighbour(QString gameBoard[SIZE_GAME][SIZE_GAME],Move& move,int direction);

        bool isPlayer1Turn() const;
        void setIsPlayer1Turn(bool isPlayer1Turn);

        int currentGameState() const;
        void setCurrentGameState(int currentGameState);

        int currentGameMode() const;
        void setCurrentGameMode(int currentGameMode);

        bool isAllowSendData() const;
        void setIsAllowSendData(bool isAllowSendData);

        QString gameTitle() const;
        void setGameTitle(const QString &gameTitle);

        void saveGamePlayeToJsonFile(Player arrPlayer[NUMBER_PLAYER]);

    signals:
        void isPlayer1TurnChanged();
        void isCurrentGameStateChanged();
        void isCurrentGameModeChanged();
        void isGameTitleChanged();

    public slots:
        void makeMoveIfMessageChanged();

    private:
        QQmlApplicationEngine* m_engine;
        GameModel m_gameModel;
        bool m_isPlayer1Turn;
        int m_currentGameState;
        int m_currentGameMode;
        NetworkConnection* m_networkConnection;
        bool m_isAllowSendData;
        QString m_gameTitle;
};

#endif // TIKTACTOE_H

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>

#include <fstream>
#include <sstream>
#include <cstring>

#include "GameGridViewModel.h"
#include "Player.h"
#include "Constants.h"
#include "Utils.h"
#include "Move.h"
#include "ListViewReplayModel.h"

#include "rapidjson/document.h"

using namespace rapidjson;
using namespace std;

class GameModel : public QObject {
        Q_OBJECT
    public:
        GameModel();

        GameGridViewModel m_gameGridViewModel;
        ListViewReplayModel m_listViewReplayModel;
        Player arrPlayer[NUMBER_PLAYER]; // set up 2 players

        void resetGame();
        void initGameGridViewModel();
        void convertListModelToTwoDimensons(QString gameBoard[SIZE_GAME][SIZE_GAME]); // convert grid model to 2 dimensional array

        void initListGameReplay();

    signals:
        void isListObjectMenuChanged();
};

#endif // GAMEMODEL_H

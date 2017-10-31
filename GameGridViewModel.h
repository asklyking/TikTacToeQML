#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QDebug>
#include <Constants.h>

class GameBoardCell {
    private:
        QString m_text;
    public:
        GameBoardCell();
        GameBoardCell(const QString &text);
        QString text() const;
        void setText(const QString &text);
};

class GameGridViewModel : public QAbstractListModel {
        Q_OBJECT
    private:
        QList<GameBoardCell> m_listGameCell;

    public:
        enum GameBoardModelRoles {
            TextRole = Qt::UserRole + 1
        };

        GameGridViewModel(QObject *parent = 0);

        void addGameBoardCell(const GameBoardCell &gameboard_cell);
        bool updateGameBoardCell(int index,const bool isPlayer1Turn, const bool isUndo = false);
        bool moveCellInGameBoard(int fromID, int toID);
        bool removeAllCellInGameBoard();
        GameBoardCell getGameBoardCellAtIndex(int index) const;

        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role) const;

    protected:
        QHash<int, QByteArray> roleNames() const;

    signals:
        //    dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
};

#endif // GAMEBOARDMODEL_H

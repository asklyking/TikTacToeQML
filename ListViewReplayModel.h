#ifndef LISTVIEWREPLAYMODEL_H
#define LISTVIEWREPLAYMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <Player.h>
#include "Constants.h"
#include "Utils.h"

class GameReplay{
    public:
        GameReplay();
        QString title() const;
        void setTitle(const QString &title);

        Player arrPlayer[NUMBER_PLAYER];

    private:
        QString m_title;
};

class ListViewReplayModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        enum GameReplayRoles {
            TitleRole = Qt::UserRole + 1
        };

        explicit ListViewReplayModel(QObject *parent = 0);

        QVariant data(const QModelIndex &index, int role) const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QHash<int, QByteArray> roleNames() const;

        void addGameReplayToList(const GameReplay gameReplay);
        void clearListGameReplay();
        GameReplay getGameReplayAtIndex(int index) const;
    signals:

    public slots:

    private:
        QList<GameReplay> m_listGameReplay;
};

#endif // LISTVIEWREPLAYMODEL_H

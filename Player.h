#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <Move.h>

class Player
{
    private:
        bool m_isPlayFirst;
        QString m_name;
        QVector<Move> m_listMove;

    public:
        Player();
        bool isPlayFirst() const;
        void setIsPlayFirst(bool value);
        QVector<Move> listMove() const;
        void setListMove(const QVector<Move> &value);
        void addMoveToList(const Move move);
        void removeMoveFromList(int index);
        QString name() const;
        void setName(const QString &name);
};

#endif // PLAYER_H

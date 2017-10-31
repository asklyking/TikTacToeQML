#include "ListViewReplayModel.h"

GameReplay::GameReplay() : m_title("")
{

}

QString GameReplay::title() const
{
    return m_title;
}

void GameReplay::setTitle(const QString &title)
{
    m_title = title;
}

ListViewReplayModel::ListViewReplayModel(QObject *parent) : QAbstractListModel(parent)
{

}

QVariant ListViewReplayModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row() >= rowCount()){
        return QVariant();
    }

    if(role == TitleRole){
        return m_listGameReplay.at(index.row()).title();
    }

    return QVariant();
}

int ListViewReplayModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listGameReplay.count();
}

QHash<int, QByteArray> ListViewReplayModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "game_title";
    return roles;
}

void ListViewReplayModel::addGameReplayToList(const GameReplay gameReplay)
{
    beginInsertColumns(QModelIndex(),rowCount(),rowCount());
    m_listGameReplay.push_back(gameReplay);
    endInsertRows();
}

void ListViewReplayModel::clearListGameReplay()
{
    beginRemoveRows(QModelIndex(),0,rowCount());
    m_listGameReplay.clear();
    endRemoveRows();
}

GameReplay ListViewReplayModel::getGameReplayAtIndex(int index) const
{
    return m_listGameReplay.at(index);
}

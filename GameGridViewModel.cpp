#include "GameGridViewModel.h"

// GameBoard Cell

GameBoardCell::GameBoardCell() : m_text(QString("")){

}

GameBoardCell::GameBoardCell(const QString &text): m_text(text){
}

QString GameBoardCell::text() const{
    return m_text;
}

void GameBoardCell::setText(const QString &text){   
    if(m_text != text){
        m_text = text;
    }
}



// GameBoard Model

GameGridViewModel::GameGridViewModel(QObject *parent) : QAbstractListModel(parent){
}

void GameGridViewModel::addGameBoardCell(const GameBoardCell &gameboard_cell){
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_listGameCell << gameboard_cell;
    endInsertRows();
}

bool GameGridViewModel::updateGameBoardCell(int index,const bool isPlayer1Turn, bool isUndo){
    GameBoardCell tmpCell;
    if(isUndo){
        //reset cell at index to blank
        m_listGameCell[index].setText(strBlank);
    }else {
        //set text X,O
        m_listGameCell[index].setText(isPlayer1Turn ? strX : strO);
    }

    dataChanged(GameGridViewModel::index(index),GameGridViewModel::index(index));

    return true;
}

bool GameGridViewModel::moveCellInGameBoard(int fromID, int toID){
    if (fromID == toID) return true;
    if (fromID < toID){
        m_listGameCell.swap(fromID,toID);
        dataChanged(index(fromID),index(toID));
    }
    else {
        m_listGameCell.swap(toID,fromID);
        dataChanged(index(toID),index(fromID));
    }
    return true;
}

bool GameGridViewModel::removeAllCellInGameBoard(){
    beginRemoveRows(QModelIndex(),0,rowCount()-1);
    m_listGameCell.clear();
    endRemoveRows();
    return true;
}

GameBoardCell GameGridViewModel::getGameBoardCellAtIndex(int index) const
{
    return m_listGameCell.at(index);
}

int GameGridViewModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return m_listGameCell.count();
}

QVariant GameGridViewModel::data(const QModelIndex &index, int role) const{
    if(index.row()<0 || index.row()>m_listGameCell.count()){
        return QVariant();
    }

    if(role == TextRole){
        return m_listGameCell.at(index.row()).text();
    }

    return QVariant();
}

QHash<int, QByteArray> GameGridViewModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TextRole] = "text";
    return roles;
}

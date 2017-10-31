#include "Player.h"


Player::Player(){

}

QString Player::name() const{
    return m_name;
}

void Player::setName(const QString &name){
    m_name = name;
}


bool Player::isPlayFirst() const{
    return m_isPlayFirst;
}

void Player::setIsPlayFirst(bool value){
    m_isPlayFirst = value;
}

QVector<Move> Player::listMove() const{
    return m_listMove;
}

void Player::setListMove(const QVector<Move> &value){
    m_listMove = value;
}

void Player::addMoveToList(const Move move){
    m_listMove.push_back(move);
}

void Player::removeMoveFromList(int index){
    m_listMove.removeAt(index);
}

#include "Move.h"

Move::Move(): m_row(-1),m_col(-1){

}

Move::Move(int row,int col) : m_row(row),m_col(col){

}

void Move::setRow(int row){
    this->m_row = row;
}

void Move::setCol(int col){
    this->m_col = col;
}

int Move::getRow(){
    return this->m_row;
}

int Move::getCol(){
    return this->m_col;
}

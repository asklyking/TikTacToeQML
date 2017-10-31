#ifndef MOVE_INCLUDED
#define MOVE_INCLUDED

// save location of player's choice
class Move {
    private:
        int m_row;
        int m_col;
    public:
        Move();
        Move(int row,int col);
        void setRow(int row);
        void setCol(int col);

        int getRow();
        int getCol();
};

#endif // MOVE_INCLUDED

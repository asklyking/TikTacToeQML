#ifndef UTILS_H
#define UTILS_H

// define direction
enum DIRECTION {
    LEFT                = 0,
    LEFT_UP             = 1,
    UP                  = 2,
    RIGHT_UP            = 3,
    RIGHT               = 4,
    RIGHT_DOWN          = 5,
    DOWN                = 6,
    LEFT_DOWN           = 7
};

// define game state
enum GAME_STATE {
    PLAYER2_WIN = -1,
    DRAW        = 0,
    PLAYER1_WIN = 1,
    CONTINUE    = 99
};

// define game mode
enum GAME_MODE {
    MODE_NONE       = -1,
    MODE_OFFLINE    = 0,
    MODE_ONLINE     = 1,
    MODE_VSCOMPUTER = 2,
    MODE_REPLAY     = 3
};

// define player order
enum PLAYER_ORDER {
    PLAYER1 = 0,
    PLAYER2
};

#endif // UTILS_H

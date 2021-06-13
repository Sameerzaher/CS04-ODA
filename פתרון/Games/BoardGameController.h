#ifndef BoardGameController_H
#define BoardGameController_H

#include "Board.h"
class BoardGameController {
    public:
        void play();
    private:
        void move(Board* game);
        void XOGame();
        void GetTheRabbitGame();
};

#endif
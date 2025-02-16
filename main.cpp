#include "SnakeLogic.h"

int main(int argc, const char *argv[])
{
    Snake a_snake(15, 10);
    a_snake.face = Snake::EAST;
    a_snake.cells.push_back(0);
    a_snake.cells.push_back(1);
    a_snake.cells.push_back(2);

    SnakeLogic game(a_snake);
    game.setup(100);
    game.loop();
    std::cout << "GAME OVER\n";

    return 0;
}
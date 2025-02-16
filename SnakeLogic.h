//: SnakeLogic.h
#ifndef SNAKELOGIC_H
#define SNAKELOGIC_H
#include <iostream>
#include <list>
#include "kb_helper.h"
#include "Snake.h"

class SnakeLogic
{
public:
    std::list<int> field, blanks;
    Snake snake;
    int score, food_cell, max_delay_ms;

    SnakeLogic(Snake s) : snake(s), score(0), max_delay_ms(500)
    {
        int shape = snake.max_x * snake.max_y;
        // filing 0...shape
        do
        {
            field.push_back(shape);
        } while (shape-- > 0);
    }

    void make_new_food()
    {
        // clear old field on previous calculation
        blanks.clear();
        int i = 0;

        do
        {
            if (!snake.having(i))
            {
                blanks.push_back(i);
            }
        } while (i++ < field.size());

        std::list<int>::iterator it = blanks.begin();
        // go to a random blank cell
        advance(it, rand() & blanks.size());
        // assign new food position
        food_cell = *(it);
    }

    void get_input()
    {
        // 10ms for keyboard
        unsigned int waited_MS = 0, input_wait_MS = 10;

        do
        {
            // keyboard hit
            if (__khbit())
            {
                // get keyboard input
                switch (__getch())
                {
                case 'a':
                case 'A':
                    snake.set_face(Snake::WEST);
                    break;
                case 's':
                case 'S':
                    snake.set_face(Snake::SOUTH);
                    break;
                case 'd':
                case 'D':
                    snake.set_face(Snake::EAST);
                    break;
                case 'w':
                case 'W':
                    snake.set_face(Snake::NORTH);
                    break;
                case 'X':
                    snake.is_alive = 0;
                    break;
                default:
                    break;
                }
            }
            delay_ms(input_wait_MS);
            waited_MS += input_wait_MS;
        } while (waited_MS < max_delay_ms);
    }
    void update_data()
    {
        if (snake.move_and_check(food_cell))
        {
            make_new_food();
            score++;
            if (max_delay_ms > 50)
            {
                max_delay_ms -= 5;
            }
        }
    }
    void re_draw()
    {
        clear_src();
        std::cout << "Snake CPP: a-left, s-down, d-right, w-up, X-exit\n";

        int field_cell = 0, width = snake.max_x;
        do
        {
            if (field_cell % width == 0)
            {
                std::cout << " ~]";
            }
            std::cout << (field_cell == food_cell ? " @ " : snake.head() == field_cell ? " o "
                                                        : snake.having(field_cell)     ? " x "
                                                                                       : " - ");
            if (++field_cell % width == 0)
            {
                std::cout << "[~\n";
            }
        } while (field_cell < field.size());
        std::cout << "\n"
                  << "Score: " << score << "\n";
    }
    void loop()
    {
        while (snake.is_alive)
        {
            get_input();
            update_data();
            re_draw();
        }
    }
    void setup(int delay_ms)
    {
        // randomise the seed
        srand((unsigned int)time(0));

        max_delay_ms = delay_ms;
        make_new_food();
    }
};
#endif
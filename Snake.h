//: Snake.h

#ifndef SNAKE_H
#define SNAKE_H
#include <list>

class Snake
{
public:
    enum Face
    {
        EAST = 1,
        NORTH,
        WEST,
        SOUTH
    };

    int max_x, max_y, is_alive;
    Face face;

    std::list<int> cells;
    Snake() : max_x(15), max_y(10), is_alive(1) {}
    Snake(int max_x, int max_y) : max_x(max_x), max_y(max_y), is_alive(1) {}
    int having(int a_cell)
    {
        return this->cells.end() != find(cells.begin(), cells.end(), a_cell);
    }
    void set_face(Face new_face)
    {
        if (2 != abs(new_face - face))
        {
            face = new_face;
        }
    }
    int head()
    {
        return this->cells.back();
    }

    int next_head()
    {
        int x = this->head() % max_x, y = this->head() / max_x;

        if (EAST == face)
        {
            x = max_x <= x + 1 ? 0 : x + 1;
        }
        else if (WEST == face)
        {
            x = x <= 0 ? max_x - 1 : x - 1;
        }
        else if (NORTH == face)
        {
            y = y <= 0 ? max_y - 1 : y - 1;
        }
        else if (SOUTH == face)
        {
            y = max_y <= y + 1 ? 0 : y + 1;
        }
        return y * max_x + x;
    }

    int move_and_check(int food_cell)
    {
        int next = next_head();

        if (having(next))
        {
            is_alive = 0;
            return 0;
        }
        cells.push_back(next);
        if (food_cell != next)
        {
            cells.pop_front();
            return 0;
        }
        return 1;
    }
};
#endif
# Snake Game in C++

A classic Snake game implementation using C++ with console-based graphics.

## Project Structure

- `main.cpp` - Entry point of the game
- `Snake.h` - Snake class definition with movement and collision logic
- `SnakeLogic.h` - Game logic implementation including food generation and game loop
- `SnakeLogic.cpp` - Implementation of game mechanics

## Game Features

- Snake movement in four directions (EAST, WEST, NORTH, SOUTH)
- Food generation at random positions
- Score tracking
- Increasing difficulty (speed increases as score goes up)
- Collision detection with walls and self

## Controls

- Arrow keys to change snake direction
- Game ends when snake collides with wall or itself

## Technical Details

### Snake Class
- Maintains snake position using a linked list of cells
- Handles movement and growth mechanics
- Collision detection logic

### SnakeLogic Class
- Game loop implementation
- Food generation algorithm
- Input handling
- Score management
- Dynamic difficulty adjustment

## Building the Game

```bash
g++ main.cpp SnakeLogic.cpp -o snake_game
```

## Running the Game

```bash
./snake_game
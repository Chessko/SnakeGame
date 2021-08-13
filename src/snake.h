#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake
{
public:
  enum class Direction
  {
    kUp,
    kDown,
    kLeft,
    kRight
  };

  // Constructor
  Snake(int grid_width, int grid_height, std::vector<SDL_Point> *borderPtr, std::vector<SDL_Point> *obstaclesPtr)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        border(borderPtr),
        obstacles(obstaclesPtr) {}

  // Methods
  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y);

  // Attributes
  Direction direction = Direction::kUp;
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  std::vector<SDL_Point> *border;
  std::vector<SDL_Point> *obstacles;

private:
  // Methods
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  // Attributes
  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
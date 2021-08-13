#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "colors.h"

class Game
{
public:
  // Constructor
  Game(std::size_t grid_width, std::size_t grid_height, int mode, Colors colorObject);

  // Methods
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void setBoarder(std::size_t grid_width, std::size_t grid_height);
  void setObstacles(std::size_t grid_width, std::size_t grid_height);

  // Attributes
  std::vector<SDL_Point> border;
  std::vector<SDL_Point> obstacles;
  Colors colObj;

private:
  // Methods
  void PlaceFood();
  void Update();

  // Attribtues
  int mode;
  int score{0};
  Snake snake;
  SDL_Point food;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif
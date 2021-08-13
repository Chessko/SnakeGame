#include "game.h"
#include <iostream>
#include <sstream>
#include "SDL.h"
#include "colors.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, int m, Colors colorObject)
    : snake(grid_width, grid_height, &border, &obstacles),
      engine(dev()),
      random_w(1, static_cast<int>(grid_width - 2)),
      random_h(1, static_cast<int>(grid_height - 2)),
      mode(m),
      colObj(colorObject)
{

  // Set border and obstacles
  if (m == 0)
  {
    setBoarder(grid_width, grid_height);
    setObstacles(grid_width, grid_height);
  }
  PlaceFood();
}

void Game::setBoarder(std::size_t gridWidth, std::size_t gridHeight)
{
  SDL_Point borderCell;
  for (int i = 0; i < (int)gridHeight; i++)
  {
    // left border
    borderCell = {0, i};
    border.push_back(borderCell);

    // right border
    borderCell = {(int)gridWidth - 1, i};
    border.push_back(borderCell);
  }
  for (int i = 0; i < (int)gridWidth; i++)
  {
    // top border
    borderCell = {i, 0};
    border.push_back(borderCell);

    // bottom border
    borderCell = {i, (int)gridHeight - 1};
    border.push_back(borderCell);
  }
};

void Game::setObstacles(std::size_t gridWidth, std::size_t gridHeight)
{
  SDL_Point obstacle;
  int x, y;

  for (int i = 0; i < 15; i++)
  {
    x = random_w(engine);
    y = random_h(engine);
    obstacle = {x, y};
    border.push_back(obstacle);
  }
};

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, &obstacles, &border, &colObj);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update()
{
  if (!snake.alive)
    return;
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
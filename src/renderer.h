#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "colors.h"

class Renderer
{
public:
  // Constructor & Destructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  // Methods
  void Render(Snake const snake, SDL_Point const &food, std::vector<SDL_Point> const *obstacles, std::vector<SDL_Point> const *border, Colors const *colObj);
  void UpdateWindowTitle(int score, int fps);

private:
  // Attributes
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
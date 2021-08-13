#include <iostream>
#include <sstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "colors.h"
#include "colors.cpp"

int requestMode()
{
    int mode;
    std::string line;
    std::cout << "Which mode do you want to play (0: hard, 1: easy)?" << std::endl;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if (ss >> mode)
        {
            if (ss.eof())
            {
                if (mode == 0 || mode == 1)
                {
                    // Success
                    std::cout << "Have fun!" << std::endl;
                    return mode;
                }
            }
        }
        std::cout << "Please enter either 0 (hard borders) or 1 (no borders)" << std::endl;
    }
};

int main()
{
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};
    int mode = requestMode();

    Colors colObj = Colors(mode);
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight, mode, colObj);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    return 0;
}

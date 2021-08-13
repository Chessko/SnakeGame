#include "colors.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>

Colors::Colors(int mode)
{
    std::string filepath = "../src/colorSchemes.txt";
    readColorScheme(filepath, mode);
};

void Colors::readColorScheme(std::string path, int mode)
{
    std::string line, key;
    int value1, value2, value3, value4;

    std::ifstream filestream(path);
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::replace(line.begin(), line.end(), ':', ' ');
            std::replace(line.begin(), line.end(), ';', ' ');
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream linestream(line);
            if (mode == 0)
            {
                while (linestream >> key >> std::hex >> value1 >> std::hex >> value2 >> std::hex >> value3 >> std::hex >> value4)
                {
                    if (key == "colorFood_hard")
                    {
                        colorFood = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorObstacles_hard")
                    {
                        colorObstacles = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorBorder_hard")
                    {
                        colorBorder = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorSnakeHead_hard")
                    {
                        colorSnakeHead = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorSnakeBody_hard")
                    {
                        colorSnakeBody = std::vector<int>{value1, value2, value3, value4};
                    }
                }
            }
            if (mode == 1)
            {
                while (linestream >> key >> std::hex >> value1 >> std::hex >> value2 >> std::hex >> value3 >> std::hex >> value4)
                {
                    if (key == "colorFood_easy")
                    {
                        colorFood = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorObstacles_easy")
                    {
                        colorObstacles = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorBorder_easy")
                    {
                        colorBorder = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorSnakeHead_easy")
                    {
                        colorSnakeHead = std::vector<int>{value1, value2, value3, value4};
                    }
                    if (key == "colorSnakeBody_easy")
                    {
                        colorSnakeBody = std::vector<int>{value1, value2, value3, value4};
                    }
                }
            }
        }
    }
};

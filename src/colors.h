#ifndef COLORS_H
#define COLORS_H

#include <string>

class Colors
{
public:
    // Constructor
    Colors(int mode);

    // Methods
    void readColorScheme(std::string path, int mode);

    // Attributes
    std::vector<int> colorFood;
    std::vector<int> colorObstacles;
    std::vector<int> colorBorder;
    std::vector<int> colorSnakeHead;
    std::vector<int> colorSnakeBody;
};

#endif
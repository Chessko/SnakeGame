# CPPND: Capstone Snake Game

This is a starter repo for my Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## C++ & SDL
The code is written in C++ entirely and utilizes the SDL framework.

## Features
I added the following new features to the existing Snake game:
* the user can choose between two different modi: easy and hard
* the hard mode contains borders and obstacles whereas the easy mode 
* the user can set his own color scheme for each mode respectively by simply altering the hex-colors in colorSchemes.txt

## File and class structure
The source code consists of a main function and five classes (Game, Controller, Snake, Renderer, and Colors). Each class has its own .h-file and .cpp-file. The main function asks the user which mode he or she would like to play (- requestMode() -) before creating a Color, Renderer, and Controller object, respectively. The mode and Color object is passed to the constructor of a newly created Game object. Then, the renderer and controller object is passed to the game.Run() method which starts the game loop. The comments within the code provide you with further information. 

## Rubric points
The following rubric points are addressed:
* README --> all
* Compiling and testing --> all
* Loops, functions, I/O: --> all (3)
    * while loop: main.cpp --> requestMode() (Line 9)
    * for loop: snake.cpp --> updateBody() (Line 78)
    * if statement --> requestMode() (Line 9)
    * input: main.cpp --> requestMode() (Line 9)
    * output: main.cpp --> requestMode() (Line 9)
    * reading .txt file: colors.cpp --> readColorScheme() (Line 14)
* Object Oriented Programming: (4)
    * code is organized into classes with class attributes to hold data, and class methods to perform tasks --> see all .h-files
    * class data members are explicitly specified as public, protected, or private --> see all .h-files
    * all class members that are set to argument values are initialized through member initialization lists: renderer.cpp --> Renderer() (Line 9)
    * all member functions document their effects, either through function names, comments, or formal documentation. --> see complete code


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International
Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

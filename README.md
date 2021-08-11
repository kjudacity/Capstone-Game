# CPPND: Capstone Snake Game 
For my capstone project I chose to enhance the provided snake game. I modified the start repo to add a wall around the boarder of the game as well as obstacles. When the snake contacts either of which the snake dies. The obstacles appear every 3rd round played. The snake game consists of 5 main classes: Game, Snake Controller, Renderer and StationaryObject. StationaryObject has two classes that inherit: Wall and Food. The obstacles are formed by using the base StationaryObject Class. The Food is special, because it always clears the previous food when a new food is placed. Wall is special because it is always rectangular and can use a slightly more efficient method to check if an x, y location is occupied by the wall. 

<img src="snake_game.gif"/>

The code leverages the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) which was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. 

## Rubric Points
* Required: README - Project required a read me with instructions (see below), indicates project chosen (see above), and contains information about rubic points (this section).

* Required: Complining and Testing - Must compile and run with no errors. Please follow the instructions below. I tested it in the Udacity workspace/desktop and it compiled without errors and ran perfectly. 

* Loops, Functions and I/O 
  * The project demonstrates an understanding of C++ functions and control structures. - This can be found throughout the code. Specifically in the stationaryObject.h and stationaryObject.cpp files that defines the new functions for the new classes. Additionally a new function was added on line 65 of game.cpp to find clear locations on the board. This function is used in placing the food and obstacles throughout the game. 
  * The project accepts user input and processes the input. - This is part of the starter code but was not modified. 

* Object Oriented Programming  
  * The project uses Object Oriented Programming techniques. - Base code already organized into 4 main classes: Game, Snake Controller, and Renderer. Additionally, I added 1 more base class StationaryObject which has two subclassess: Wall and Food. See stationaryObject.h for declariations of the classes on lines 9, 26, and 43.  
  * Classes use appropriate access specifiers for class members. - See stationaryObject.h for declariations of the classes on lines 10, 27, 35, and 44.  
  * Class constructors utilize member initialization lists. - See stationaryObject.h for declariations of the classes on lines 28.  
  * Classes abstract implementation details from their interfaces. - The base code already started this and it was continued through with StationaryObjects, Wall, and Food.   
  * Classes encapsulate behavior. - The base code started this and it was continued through with StationaryObjects, Wall, and Food, specifically the function Occupied in stationaryObject.cpp lines 11 and 56.  
  * Classes follow an appropriate inheritance hierarchy. - This can be seen in stationaryObject.h for declariations of the classes on lines 9, 26, and 43.  
  * Overloaded functions allow the same function to operate on different parameters. -Yes Occupied works differently for Wall - see stationaryObject.cpp lines 11 and 56.  
  
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

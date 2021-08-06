#include "stationaryObject.h"
#include <cmath>
#include <iostream>

#include <vector>
#include "SDL.h"


// set object location
void Object::SetLocation(int x, int y){
SDL_Point objectLocation{
      static_cast<int>(x),
      static_cast<int>(y)};  
}

// Check location is occupied by Object
bool Object::Occupied(int x, int y) {
  if (x == static_cast<int>(objectLocation.x) && y == static_cast<int>(objectLocation.y)) {
    return true;
  }
}


void Wall::SetLocation(int x, int y) { //can used if we want the box to be different than the window
    int wallTopX = x;
    int wallTopY = y;

    SDL_Point point;

    // loop through the top/bottom
    for (size_t k = 0; i < wallTopX; k++)
    {
        point.x = k;
        point.y = 0;
        wallLocation.push_back(point);
        point.x = k;
        point.y = wallTopY;
        wallLocation.push_back(point);
    }

    // loop through the sides
    for (size_t k = 1; k < wallTopY; k++)
    {
        point.x = 0;
        point.y = k;
        wallLocation.push_back(point);
        point.x = wallTopX;
        point.y = k;
        wallLocation.push_back(point);
    }
}


// Inefficient method to check if cell is occupied by snake.
bool Wall::Occupied(int x, int y) {
  if (x == static_cast<int>(objectLocation.x) && y == static_cast<int>(objectLocation.y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}


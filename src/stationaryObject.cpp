#include "stationaryObject.h"
#include <cmath>
#include <iostream>

#include <vector>
#include "SDL.h"


// Check location is occupied by Object
  // define function for testing if a space is occupied by the object
  bool StationaryObject::Occupied(int x, int y) {
    for (auto const &item : objectLocation) {
      if (x == item.x && y == item.y) {
        return true;
      }
    }
    return false;
  }

  // Define Setter
  void StationaryObject::SetPoint(SDL_Point nextpoint) {
    objectLocation.push_back(nextpoint);  
  }; 

// setup locatoin of the wall
void Wall::SetLocation(int x, int y) { //can used if we want the box to be different than the window
    wallTopX = x;
    wallTopY = y;

    SDL_Point point;

    // loop through the top/bottom note: subtract one or you end up offscreen
    for (int k = 0; k < wallTopX; k++)
    {
        point.x = k;
        point.y = 0;
        objectLocation.push_back(point);
        point.x = k;
        point.y = wallTopY-1; 
        objectLocation.push_back(point);
    }

    // loop through the sides note: subtract one or you end up offscreen
    for (int k = 1; k < wallTopY; k++)
    {
        point.x = 0;
        point.y = k;
        objectLocation.push_back(point);
        point.x = wallTopX-1;
        point.y = k;
        objectLocation.push_back(point);
    }
}

// a more efficient method for checking if an x, y location is in the wall
bool Wall::Occupied(int x, int y) {

  if (x == 0 || x == wallTopX-1|| y == 0 || y == wallTopY-1) {
    return true;
  }
  return false;
}


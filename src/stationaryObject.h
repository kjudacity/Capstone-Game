#ifndef STATION_H
#define STATION_H

#include <random>
#include "SDL.h"
#include <iostream>

// Define a generic stationary object (assume single point)
class StationaryObject{
 public:

  StationaryObject() {};
  ~StationaryObject() {};

  // Define Setter and Getter Functions
  std::vector<SDL_Point> GetLocation() { return objectLocation; } // getter function
  void SetPoint(SDL_Point nextpoint); // setter function
  
  // define function for testing if a space is occupied by the object
  bool Occupied(int x, int y);
    
  std::vector<SDL_Point> objectLocation;
 };

// Define Wall object
class Wall: public StationaryObject {
  public:
    Wall(int grid_width, int grid_height) {SetLocation(grid_width, grid_height);}
    Wall() {};
    ~Wall() {};

    void SetLocation(int x, int y); // wall specific setter function
    bool Occupied(int x, int y); // more efficient check thats specific to wall

  private:
    int wallBottomX{0};
    int wallTopX;
    int wallBottomY{0};
    int wallTopY;
};

// Redefine food as a stationary object instead of a point
class Food: public StationaryObject {
  public:
    Food() {};
    ~Food() {};

    // setter function - want this to be a single point not vector of many food points
    void SetPoint(SDL_Point nextpoint) { 
      objectLocation.clear();
      objectLocation.push_back(nextpoint); 
    }; 

};


#endif
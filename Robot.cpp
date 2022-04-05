//
// Created by Mohamed Ahmed on 1/25/18.
//

#include "Robot.h"
#include "iostream"
//using namespace std;

Robot::Robot()
{
    coordinates = {0,0};
}

Robot::Robot(Point coord)
{
    this->coordinates = coord;
}

Robot::~Robot()
{

}

Point Robot::getCoordinates()
{
    return coordinates;
}

int Robot::getXPoint() {
    return coordinates.x;
}

int Robot::getYPoint() {
    return coordinates.y;
}


void Robot::setCoordinates(const Point &coord) {
    this->coordinates = coord;
}

void Robot::Move(string dir) {
    if(dir == "N")
    {
        coordinates.y = coordinates.y + 1;
    }
    if(dir == "S")
    {
        coordinates.y = coordinates.y - 1;
    }
    if(dir == "W")
    {
        coordinates.x = coordinates.x - 1;
    }
    if(dir == "E")
    {
        coordinates.x = coordinates.x + 1;
    }
}

void Robot::PrintCoord()
{
    cout << "x y point: (" << coordinates.x << ", " << coordinates.y << ")" <<  endl;
}






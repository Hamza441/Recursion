//
// Created by Mohamed Ahmed on 1/25/18.
//

#ifndef GREEDYROBOT_ROBOT_H
#define GREEDYROBOT_ROBOT_H

#include <ostream>
using namespace std;

struct Point
{
    int x;
    int y;
};
class Robot
{
    public:
        // constructors
        Robot();
        Robot(Point coordinates);
        ~Robot();

        //getters/setters
        Point getCoordinates();
        int getXPoint();
        int getYPoint();

        void setCoordinates(const Point &coord);
        void Move(string dir);
        void PrintCoord();

    private:
        Point coordinates; // robots location
};


#endif //GREEDYROBOT_ROBOT_H

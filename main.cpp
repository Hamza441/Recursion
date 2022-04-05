#include <iostream>
#include <string>
#include "Robot.h"
#include <cmath>

int getPaths(Robot robot, Point treasure, int shortestPath, string path, char prevMove, int frequency);

int main()
{
    int rX;
    int rY;
    int tX;
    int tY;
    cout << "Please enter input: " << endl;
    cin >> rX >> rY >> tX >> tY;

    Point r1;
    r1.x = rX;
    r1.y = rY;

    Point treasure;
    treasure.x = tX;
    treasure.y = tY;

    Robot robot(r1);

    string path;
    path = "";

    int shortestPath = abs(r1.x - treasure.x) + abs(r1.y - treasure.y);

    int numOfPaths = getPaths(robot,treasure,shortestPath,path,'A',0);

    cout << "Number of paths: " << numOfPaths << endl;
    return 0;
}

int getPaths(Robot robot,Point treasure ,int shortestPath,string path,char prevMove,int freq)
{
    if(abs(robot.getXPoint() - treasure.x) + abs(robot.getYPoint() - treasure.y) > shortestPath)
    {
        return 0;
    }
    else if(freq > 2){
        return 0;
    }
    Robot robotX(robot.getCoordinates());
    Robot robotY(robot.getCoordinates());
    if(robot.getXPoint() == treasure.x && robot.getYPoint() == treasure.y)
    {
       cout<< "Found Path: " << path << endl;
        return 1;
    }

    else if(robot.getXPoint() == treasure.x)
    {
        if(robot.getYPoint() > treasure.y)
        {
            robotY.Move("S");
            return (prevMove == 'S') ? getPaths(robotY,treasure,shortestPath,path + "S",'S', freq + 1) : getPaths(robotY,treasure,shortestPath,path + "S",'S',1) ;
        }
        else
        {
            robotY.Move("N");
            return (prevMove == 'N') ? getPaths(robotY,treasure,shortestPath,path + "N",'N',freq + 1) : getPaths(robotY,treasure,shortestPath,path + "N",'N',1) ;
        }
    }
    else if(robot.getYPoint() == treasure.y)
    {
        if(robot.getXPoint() > treasure.x)
        {
            robotX.Move("W");
            return (prevMove == 'W') ? getPaths(robotX, treasure,shortestPath,path + "W",'W',freq + 1) : getPaths(robotX, treasure,shortestPath,path + "W",'W',1) ;
        }
        else
        {
            robotX.Move("E");
            return (prevMove == 'E') ? getPaths(robotX,treasure,shortestPath,path + "E", 'E',freq + 1) : getPaths(robotX,treasure,shortestPath,path + "E", 'E',1);
        }
    }
    else
    {
        if(robot.getXPoint() > treasure.x && robot.getYPoint() > treasure.y)
        {
            robotX.Move("W");
            robotY.Move("S");
            if(prevMove == 'W')
            {
                return getPaths(robotX,treasure,shortestPath,path + "W", 'W',freq + 1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',1);
            }
            else if(prevMove == 'S')
            {
                return getPaths(robotX,treasure,shortestPath,path + "W", 'W',1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',freq + 1);
            }
            else
            {
                return getPaths(robotX,treasure,shortestPath,path + "W", 'W',1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',1);
            }
        }
        else if(robot.getXPoint() > treasure.x && robot.getYPoint() < treasure.y)
        {
            robotX.Move("W");
            robotY.Move("N");
            if(prevMove == 'W')
            {
                return getPaths(robotX,treasure,shortestPath,path + "W",'W',freq + 1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',1);

            }
            else if(prevMove == 'N')
            {
                return getPaths(robotX,treasure,shortestPath,path + "W",'W',1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',freq + 1);
            }
            else
            {
                return getPaths(robotX,treasure,shortestPath,path + "W",'W',1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',1);
            }
        }
        else if(robot.getXPoint() < treasure.x && robot.getYPoint() < treasure.y)
        {
            robotX.Move("E");
            robotY.Move("N");
            if(prevMove == 'E')
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',freq + 1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',1);
            }
            else if(prevMove == 'N')
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',freq + 1);
            }
            else
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',1) + getPaths(robotY,treasure,shortestPath,path + "N",'N',1);

            }
        }
        else
        {
            robotX.Move("E");
            robotY.Move("S");
            if(prevMove == 'E')
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',freq + 1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',1);
            }
            else if(prevMove == 'S')
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',freq + 1);
            }
            else
            {
                return getPaths(robotX,treasure,shortestPath,path + "E",'E',1) + getPaths(robotY,treasure,shortestPath,path + "S",'S',1);
            }
        }
    }
}
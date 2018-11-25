#pragma once

class Point{
    
    public:

    Point(double x, double y);
    void Set(double x, double y);
    void Increment(double deltaX, double deltaY);
    double GetX();
    double GetY();

    private:

    double xCoordinate;
    double yCoordinate;
};
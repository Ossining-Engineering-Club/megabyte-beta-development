#include <vector>
#include <cmath>
#include "Point.h"
#pragma once

class Path{

    public:

    Path(double minPointsPerInch);
    void initCenterAngleArcPath(Point center, double startRadians, double stopRadians, bool isClockwise);
    std::vector<Point> GetPath();

    private:
    void constructCirclePath(Point center, double startAngle, double endAngle, bool isClockwise);
    std::vector<Point> currPath;
    double pointsPerInch;
    double radius;
    double centralAngle;
    double arcLength;
    double angleIncrement;
    double m1;
    double m2;
    double b1;
    double b2;
    double centerX;
    double centerY;
    Point centerPoint;
};
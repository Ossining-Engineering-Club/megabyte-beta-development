#include "Path.h"

Path::Path(double minPointsPerInch):
centerPoint(0,0),
currPath()
{
    pointsPerInch = minPointsPerInch;
}
void Path::initCenterAngleArcPath(Point center, double startRadians, double stopRadians, bool isClockwise){
    constructCirclePath(center, startRadians, stopRadians, isClockwise);
}
void Path::constructCirclePath(Point center, double startAngle, double endAngle, bool isClockwise){

    if(isClockwise){
        centralAngle = fmod(fmod(startAngle-endAngle, 360) + 360, 360);
        arcLength = centralAngle*radius;
    }
    else{
        centralAngle = fmod(fmod(endAngle-startAngle, 360) + 360, 360);
        arcLength = centralAngle*radius;
    }
    pointsPerInch = ceil(arcLength*pointsPerInch)/pointsPerInch;
    angleIncrement = centralAngle/pointsPerInch;
    if(isClockwise){
        double currAngle = 0.0;
        Point currentPoint(0,0);
        while(fmod(currAngle + 360.0, 360.0) < centralAngle){
            currentPoint.Set(radius*cos(startAngle-currAngle), radius*sin(startAngle-currAngle));
            currPath.push_back(currentPoint);
            currAngle += angleIncrement;
        }
    }
    else{
        double currAngle = 0.0;
        Point currentPoint(0,0);
        while(fmod(currAngle + 360.0, 360.0) < centralAngle){
            currentPoint.Set(radius*cos(startAngle+currAngle), radius*sin(startAngle+currAngle));
            currPath.push_back(currentPoint);
            currAngle += angleIncrement;
        }
    }
}
std::vector<Point> Path::GetPath(){
    return currPath;
}
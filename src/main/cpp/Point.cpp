#include "Point.h"

Point::Point(double x, double y){
    xCoordinate = x;
    yCoordinate = y;
}
void Point::Set(double x, double y){
    xCoordinate = x;
    yCoordinate = y;
}
void Point::Increment(double deltaX, double deltaY){
    xCoordinate += deltaX;
    yCoordinate += deltaY;
}
double Point::GetX(){
    return xCoordinate;
}
double Point::GetY(){
    return yCoordinate;
}

#include "Tankdrive.h"
#include <iostream>
#include <math.h>

Tankdrive::Tankdrive(SmartDashboard *dash):
rightMotors(0),
leftMotors(1),
leftEncoder(3,4,true,frc::Encoder::EncodingType::k4X),
rightEncoder(1,2,false,frc::Encoder::EncodingType::k4X),
pidController(-1.0,0.0,0.0)
{
    dashboard = dash;
    lastAngle = 3.14159265/2.0;
    leftPower = 0.0;
    rightPower = 0.0;
    currentX = 0.0;
    currentY = 0.0;
    currAngle = 3.14159265/2.0;
    lastLeft = 0.0;
    lastRight = 0.0;
    leftEncoder.SetDistancePerPulse(0.07766803);
    rightEncoder.SetDistancePerPulse(0.07766803);
    leftEncoder.Reset();
    rightEncoder.Reset();
}
void Tankdrive::UpdateOdometry(){
    double rightDist = rightEncoder.GetDistance()-lastRight;
    double leftDist = leftEncoder.GetDistance()-lastLeft;
    currAngle+=(leftDist-rightDist)/(29.75);
    currentX += cos((currAngle+lastAngle)/2)*((rightDist+leftDist)/2);
    currentY += sin((currAngle+lastAngle)/2)*((rightDist+leftDist)/2);
    lastRight = rightEncoder.GetDistance();
    lastLeft = leftEncoder.GetDistance();
    dashboard -> PutNumber("X: ", currentX);
    dashboard -> PutNumber("Y: ", currentY);
    dashboard -> PutNumber("Angle: ", currAngle);
}
void Tankdrive::SetPower(double rightPow, double leftPow){
    leftMotors.Set(-1.0*leftPow);
    rightMotors.Set(-1.0*rightPow);
}
void Tankdrive::ResetEncoders() {
    leftEncoder.Reset();
    rightEncoder.Reset();
    lastAngle = 3.14159265/2.0;
    currentX = 0.0;
    currentY = 0.0;
    currAngle = 3.14159265/2.0;
    lastLeft = 0.0;
    lastRight = 0.0;
}
void Tankdrive::DrivePath(std::vector<Point> drivepath, double speed){}
void Tankdrive::DriveCircle(double travelAngle, double radius, double power){
    ResetEncoders();
    double rightInitPow = power+14.0*power/(radius/2);
    double leftInitPow = power-14.0*power/(radius/2);
    double leftEncoderExpected = 0.0;
    if(abs(rightInitPow > 0.9)){
        leftInitPow = (0.9/abs(rightInitPow))*leftInitPow;
        rightInitPow = 0.9;
    }
    if(abs(leftInitPow > 0.9)){
        rightInitPow = (0.9/abs(leftInitPow))*rightInitPow;
        leftInitPow = 0.9;
    }
    rightMotors.Set(rightInitPow);
    leftMotors.Set(leftInitPow);
    dashboard->PutNumber("right power: ", rightInitPow);
    dashboard->PutNumber("left power: ", leftInitPow);
    while((rightEncoder.GetDistance()+leftEncoder.GetDistance())/2 < travelAngle*radius){
        leftEncoderExpected = rightEncoder.GetDistance()-rightEncoder.GetDistance()*(14.0/radius);
        //leftMotors.Set(pidController.GetPIDCorrection(leftEncoder.GetDistance()-leftEncoderExpected)+leftInitPow);
    }
    leftMotors.Set(0.0);
    rightMotors.Set(0.0);
}
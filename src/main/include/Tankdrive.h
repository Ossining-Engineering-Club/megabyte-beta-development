#pragma once
#include <frc/WPIlib.h>
#include "Point.h"
#include "GoodPIDController.h"

using namespace frc;
class Tankdrive{
public:
    Tankdrive(SmartDashboard *dash);
    void UpdateOdometry();
    void SetPower(double rightPow, double leftPow);
    void DrivePath(std::vector<Point> drivepath, double speed);
    void ResetEncoders();
    void DriveCircle(double tavelAngle, double radius, double power);
private:
    SmartDashboard *dashboard;
    double leftPower;
    double rightPower;
    double currentX;
    double currentY;
    double currAngle;
    double lastAngle;
    double lastLeft;
    double lastRight;
    frc::Talon rightMotors;
    frc::Talon leftMotors;
    frc::Encoder leftEncoder;
    frc::Encoder rightEncoder;
    GoodPIDController pidController;
};
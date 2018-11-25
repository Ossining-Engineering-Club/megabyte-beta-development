
#pragma once
#include <WPILib.h>

class Tankdrive{

    public:

    Tankdrive(frc::Joystick* stickLeft, frc::Joystick* stickRight, int leftPWM, int rightPWM);
    void SetPower(double leftPower, double rightPower);
    void DriveArc(double radius, double centralAngle);
    void SetRunWithGyro(bool runWithGyro);
    void ResetEncoders();
    double GetLeftEncoderDist();
    double GetRightEncoderDist();
    double GetOdometryX();
    double GetOdometryY();
    double ResetOdometry();

    private:

    frc::Joystick* leftStick;
    frc::Joystick* rightStick;
    frc::Spark leftMotors;
    frc::Spark rightMotors;


};
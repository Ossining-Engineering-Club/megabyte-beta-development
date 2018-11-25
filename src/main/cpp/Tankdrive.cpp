#include "Tankdrive.h"

Tankdrive::Tankdrive(frc::Joystick* stickLeft, frc::Joystick* stickRight, int leftPWM, int rightPWM):
leftMotors(leftPWM),
rightMotors(rightPWM)
{
    leftStick = stickLeft;
    rightStick = stickRight;
}
void Tankdrive::SetPower(double rightPower, double leftPower){
    leftMotors.Set(leftPower);
    rightMotors.Set(rightPower);
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"


Robot::Robot():
tankdrive(dash),
stickLeft(0),
stickRight(1)
{
  dash -> init();
}

void Robot::RobotInit() {
}

void Robot::Autonomous() {
  Wait(3);
  tankdrive.DriveCircle(3.14159265/2, 96, 0.25);
}

void Robot::OperatorControl() {
  tankdrive.ResetEncoders();
  while(IsOperatorControl() && IsEnabled()){
    tankdrive.SetPower(stickRight.GetRawAxis(1), stickLeft.GetRawAxis(1));
    tankdrive.UpdateOdometry();
    Wait(0.005);
  }
}

void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif

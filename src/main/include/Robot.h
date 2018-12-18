#pragma once
#include "Tankdrive.h"

#include <frc/WPIlib.h>
using namespace frc;
using namespace std;
class Robot : public frc::SampleRobot {
 public:
  Robot();
  SmartDashboard *dash;

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
 Tankdrive tankdrive;
 Joystick stickLeft;
 Joystick stickRight;
};

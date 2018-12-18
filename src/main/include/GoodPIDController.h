#pragma once
#include <frc/WPIlib.h>

class GoodPIDController{
public:
    GoodPIDController(double kP, double kI, double kD);
    void Start();
    double GetPIDCorrection(double error);
private:
    double coefP;
    double coefI;
    double coefD;
    double proportional;
    double integral;
    double differential;
    double lastError;
    double lastTime;
    frc::Timer timer;
};
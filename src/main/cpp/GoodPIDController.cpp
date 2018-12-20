#include "GoodPIDController.h"

GoodPIDController::GoodPIDController(double kP, double kI, double kD):
timer()
{
    coefP = kP;
    coefI = kI;
    coefD = kD;
    lastError = 0.0;
    lastTime = 0.0;
    proportional = 0.0;
    integral = 0.0;
    differential = 0.0;
}
void GoodPIDController::Start(){
    timer.Start();
}
double GoodPIDController::GetPIDCorrection(double error){
    proportional = error*coefP;
    differential = coefD*((error-lastError)/timer.Get());
    integral = coefI*(lastError*(timer.Get()-lastTime));
    lastTime = timer.Get();
    lastError = error;
    return proportional+integral+differential;
}
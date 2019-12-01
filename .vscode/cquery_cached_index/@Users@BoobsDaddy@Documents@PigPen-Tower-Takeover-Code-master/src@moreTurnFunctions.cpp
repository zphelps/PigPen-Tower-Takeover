#include "main.h"

void turnRightProgramming(int angle)
{

  double kP = 0.485; //0.025; //0.17;

  double kD = 0.25; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 45; //35;

  while(thetaInDegreesUncorrected < angle - targetError || thetaInDegreesUncorrected > angle + targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (angle - thetaInDegreesUncorrected) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD) ;
    //pros::delay(5);

    rightSlewTurn(-power);
    leftSlewTurn(power);
  }

  left(0);
  right(0);
  brake();
  wait(100);
  coast();
}

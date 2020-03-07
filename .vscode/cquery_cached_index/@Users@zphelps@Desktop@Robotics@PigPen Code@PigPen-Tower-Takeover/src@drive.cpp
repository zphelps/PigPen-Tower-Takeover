#include "main.h"

//motors
pros::Motor leftFront (2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBack (11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBack (20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

//Tracking Encoders
pros::ADIEncoder R ('E', 'F', true);
pros::ADIEncoder L ('D', 'C', true);
//pros::ADIEncoder S ('G', 'H', false);

//Turn and Move Function Variables and Constants
int targetAngle = 0;

//Position Tracking Constants and Variables
const double wheelDiameter = 3.25;
const double ticsPerRotation = 360;
const double leftOffset = 3.65;
const double rightOffset = 3.65;
const double rearOffset = 4.5; //Likely going to need re-measurement

double prevL = 0;
double currentL = 0;
double deltaL = 0;
double prevR = 0;

double currentR = 0;
double deltaR = 0;
double prevS = 0;

double currentS = 0;
double deltaS = 0;
double deltaTheta = 0;

double thetaInRadians = 0;
double thetaInDegrees = 0;
double thetaInDegreesUncorrected = 0;

double deltaxglobal = 0;
double deltayglobal = 0;
double deltaxlocal = 0;
double deltaylocal = 0;
double xglobal = 0;
double yglobal = 0;
double coordinateSystemOffset = 0;
double rlocal = 0;
double thetaLocal = 0;
double rGlobal = 0;
double thetaGlobal = 0;

//************POSITION TRACKING*****************
// current_position(void*parameter) is a task is run in initialize()
// the task is used for ALL of our autonomous movements
void current_position(void* parameter)
{
  pros::lcd::initialize();

  while(true)
  {

  double LInches = (L.get_value() * 1) * pi * wheelDiameter / ticsPerRotation;
  double RInches = (R.get_value() * 1) * pi * wheelDiameter / ticsPerRotation;
  //double SInches = (S.get_value() * -1) * pi * wheelDiameter / ticsPerRotation;

  currentL = LInches;
  currentR = RInches;
//  currentS = SInches;

  deltaL = currentL - prevL;
  deltaR = currentR - prevR;
  deltaS = currentS - prevS;

  prevL = currentL;
  prevR = currentR;
  prevS = currentS;

//Theta Calculation
  deltaTheta = (deltaL - deltaR) / (leftOffset + rightOffset);

  coordinateSystemOffset = thetaInRadians + 0.5 * deltaTheta;

  thetaInRadians = thetaInRadians + deltaTheta;

  thetaInDegrees = thetaInRadians * 180 / pi;

  thetaInDegreesUncorrected = thetaInDegrees;

  thetaInDegrees = thetaInDegrees -  360 * floor(thetaInDegrees / 360);

  if (thetaInDegrees < 0)
  {
    thetaInDegrees = 360 + thetaInDegrees;
  }

//X & Y Calculation -NOT currently used
  // if (deltaTheta == 0)
  // {
  //   deltaxlocal = deltaS;
  //   deltaylocal = deltaR;
  // }
  // else
  // {
  //   deltaxlocal = 2 * sin(deltaTheta / 2) * ((deltaS / deltaTheta) + rearOffset);
  //
  //   deltaylocal = 2 * sin(deltaTheta / 2) * ((deltaR / deltaTheta) + rightOffset);
  // }

deltaxlocal = deltaS;
deltaylocal = deltaR;

//  coordinateSystemOffset = thetaInRadians - 0.5 * deltaTheta;

//Convert Local Cartesian to Local Polar Coordinates
  rlocal = sqrt(deltaxlocal * deltaxlocal + deltaylocal * deltaylocal);

  if(deltaxlocal == 0)
  {
    thetaLocal = pi / 2;
  }
  else
  {
    thetaLocal = atan(deltaylocal/deltaxlocal);
  }

//Rotate from local to global coordinate System
  rGlobal  = rlocal;

  thetaGlobal = thetaLocal - coordinateSystemOffset;

//Convert Global Polar to Global Cartesian
  deltaxglobal = rGlobal * cos(thetaGlobal);

  deltayglobal = rGlobal * sin(thetaGlobal);

xglobal = xglobal + deltaxglobal;
yglobal = yglobal + deltayglobal;


  pros::delay(5); //20
  //Display to Screen
  //IDENTIFIERS:: d = int, f = float
  pros::lcd::print(1, "Theta - Absolute: %f", thetaInDegrees);

  //pros::lcd::print(3, "L %d", L.get_value());
  //pros::lcd::print(4, "R %d", R.get_value());
  }

}

//Resets thetaInDegrees to @param degrees
void resetTheta(int degrees)
{
  thetaInRadians = degrees * PI /180;
}

//************BASIC FUNCTIONS*******************
//Basic functions used to simplify PROS syntax
void left(int speed)
{
  leftFront.move(speed);
  leftBack.move(speed);
}

void right(int speed)
{
  rightFront.move(speed);
  rightBack.move(speed);
}

//Function used to prevent timeouts
void timedDrive(int time, int speed)
{
  right(speed);
  left(speed);
  wait(time);
  right(speed);
  left(speed);
}

void brake()
{
  rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void coast()
{
  rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void wait(int duration)
{
  pros::delay(duration);
}

//slew control -> smoother autonomous movement
const int accel_step_turn = 9;
const int deccel_step_turn = 256; // no decel slew

const int accel_step = 1;
const int deccel_step = 256; // no decel slew

static int leftSpeed = 0;
static int rightSpeed = 0;

void leftSlewTurn(int leftTarget)
{
  int step;

  if(abs(leftSpeed) < abs(leftTarget))
    step = accel_step_turn;
  else
    step = deccel_step_turn;

  if(leftTarget > leftSpeed + step)
    leftSpeed += step;
  else if(leftTarget < leftSpeed - step)
    leftSpeed -= step;
  else
    leftSpeed = leftTarget;

  left(leftSpeed);
}

void rightSlewTurn(int rightTarget)
{
  int step;

  if(abs(rightSpeed) < abs(rightTarget))
    step = accel_step_turn;
  else
    step = deccel_step_turn;

  if(rightTarget > rightSpeed + step)
    rightSpeed += step;
  else if(rightTarget < rightSpeed - step)
    rightSpeed -= step;
  else
    rightSpeed = rightTarget;

  right(rightSpeed);
}

void leftSlew(int leftTarget)
{
  int step;

  if(abs(leftSpeed) < abs(leftTarget))
    step = accel_step;
  else
    step = deccel_step;

  if(leftTarget > leftSpeed + step)
    leftSpeed += step;
  else if(leftTarget < leftSpeed - step)
    leftSpeed -= step;
  else
    leftSpeed = leftTarget;

  left(leftSpeed);
}

//slew control
void rightSlew(int rightTarget)
{
  int step;

  if(abs(rightSpeed) < abs(rightTarget))
    step = accel_step;
  else
    step = deccel_step;

  if(rightTarget > rightSpeed + step)
    rightSpeed += step;
  else if(rightTarget < rightSpeed - step)
    rightSpeed -= step;
  else
    rightSpeed = rightTarget;

  right(rightSpeed);
}

//****************TURN AND MOVE FUNCTIONS*****************
void turnLeft(int angle) //-X
{

  double kP = 0.545; //0.025; //0.17;

  double kD = 0.25; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 65;

  int error = 0;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = (thetaInDegreesUncorrected - angle) + minSpeed;

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + derivative*kD);

  //    pros::delay(5);

      rightSlewTurn(power);
      leftSlewTurn(-power);
    }

    right(0);
    left(0);

  wait(100);

}

void turnLeftProgramming(int angle) //-Good
{

  double kP = 0.5; //0.5

  double kD = 0.35; //0.35

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 70; //65

  int error = 0;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = (thetaInDegreesUncorrected - angle) + minSpeed;

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + derivative*kD);

  //    pros::delay(5);

      rightSlewTurn(power);
      leftSlewTurn(-power);
    }

    left(0);
    right(0);
    brake();
    wait(100);
    coast();

}

void turnLeftLoaded(int angle) //-O
{

  double kP = 0.49; //0.485

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 65; //58

  int error = 0;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = (thetaInDegreesUncorrected - angle) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

  //    pros::delay(5);

      rightSlewTurn(power);
      leftSlewTurn(-power);
    }

    right(0);
    left(0);

  wait(100);

}

void turnLeftLoadedAuton(int angle) //-O
{

  double kP = 0.485; //0.465

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 55;

  int error = 0;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = (thetaInDegreesUncorrected - angle) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

  //    pros::delay(5);

      rightSlewTurn(power);
      leftSlewTurn(-power);
    }

    right(0);
    left(0);

  wait(100);

}

void turnLeftLoadedProgramming(int angle) //-O
{

  double kP = 0.5; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 60; //35;

  while(thetaInDegreesUncorrected > angle + targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (thetaInDegreesUncorrected - angle) + minSpeed;

    if (error < 0)
    {
      int error = (thetaInDegreesUncorrected - angle) - minSpeed;
    }

    int integral = integral + error;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + integral*kI + derivative*kD);

    //pros::delay(5);

    rightSlewTurn(power);
    leftSlewTurn(-power);
  }

  left(0);
  right(0);

  wait(100);
}

void turnRight(int angle) //-X
{

  double kP = 0.545; //0.025; //0.17;

  double kD = 0.25; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 65; //35;

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

void turnRightNoPID(int angle, int speed) //-0
{
  double targetError = 3;

  while(thetaInDegreesUncorrected < angle - targetError)
  {
    rightSlewTurn(-speed);
    leftSlewTurn(speed);
  }

  left(0);
  right(0);
  coast();
}

void turnRightProgramming(int angle) //-O
{

  double kP = 0.5; //0.5

  double kD = 0.35; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 65; //63;

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

void turnRightHalfLoaded(int angle) //-Not needed for current programming_skills
{

  double kP = 0.4; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 60; //35;

  while(thetaInDegreesUncorrected < angle - targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (angle - thetaInDegreesUncorrected) + minSpeed;

    if (error < 0)
    {
      int error = (angle - thetaInDegreesUncorrected) - minSpeed;
    }

    int integral = integral + error;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + integral*kI + derivative*kD);

    //pros::delay(5);

    rightSlewTurn(-power);
    leftSlewTurn(power);
  }

  left(0);
  right(0);

  wait(100);
}

void turnRightLoaded(int angle) //-O
{

  double kP = 0.495; //465

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 60; //65

  while(thetaInDegreesUncorrected < angle - targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (angle - thetaInDegreesUncorrected) + minSpeed;

    if (error < 0)
    {
      int error = (angle - thetaInDegreesUncorrected) - minSpeed;
    }

    int integral = integral + error;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + integral*kI + derivative*kD);

    //pros::delay(5);

    rightSlewTurn(-power);
    leftSlewTurn(power);
  }

  left(0);
  right(0);

  wait(100);
}

void turnRightLoadedAuton(int angle) //-O
{

  double kP = 0.47; //485

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 55; //55

  while(thetaInDegreesUncorrected < angle - targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (angle - thetaInDegreesUncorrected) + minSpeed;

    if (error < 0)
    {
      int error = (angle - thetaInDegreesUncorrected) - minSpeed;
    }

    int integral = integral + error;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + integral*kI + derivative*kD);

    //pros::delay(5);

    rightSlewTurn(-power);
    leftSlewTurn(power);
  }

  left(0);
  right(0);

  wait(100);
}

void turnRightLoadedProgramming(int angle) //-O
{

  double kP = 0.425; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 55; //35;

  while(thetaInDegreesUncorrected < angle - targetError) // || thetaInDegrees > angle + targetError)
  {
    int error = (angle - thetaInDegreesUncorrected) + minSpeed;

    if (error < 0)
    {
      int error = (angle - thetaInDegreesUncorrected) - minSpeed;
    }

    int integral = integral + error;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + integral*kI + derivative*kD);

    //pros::delay(5);

    rightSlewTurn(-power);
    leftSlewTurn(power);
  }

  left(0);
  right(0);

  wait(100);
}

void move(int distance, int heading, int speed) //-O
{

  double kP = 0.35;

  double correctionMultiplier = 0.2;

  double startUpIncrement = 0.5;

  double startSpeed = speed;

  double minSpeed = 45;

  double target = abs(L.get_value()) + ticsPerRotation * (distance / (wheelDiameter * pi));

  while(abs(L.get_value()) < target)
  {

    double error = target - abs(L.get_value());

    double PIDSpeed = minSpeed + speed * error / target;

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = PIDSpeed - startSpeed;

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(correctionMultiplier * PIDSpeed);
        leftSlew(PIDSpeed);
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(correctionMultiplier * PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(PIDSpeed * 0.9);
      leftSlew(PIDSpeed);
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed * 0.9);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();

  wait(50);

  coast();
}

void moveFast(int distance, int heading, int speed) //accounted for v1.09 voltage change
{

  double kP = 0.5; //0.2

  double correctionMultiplier = 0.15; //0.2

  double startUpIncrement = 0.5; //10

  double startSpeed = speed;

  double minSpeed = 55; //45

  double target = abs(L.get_value()) + ticsPerRotation * (distance / (wheelDiameter * pi));

  while(abs(L.get_value()) < target)
  {

    double error = target - abs(L.get_value());

    double PIDSpeed = minSpeed + speed * error / target;

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = PIDSpeed - startSpeed;

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(correctionMultiplier * PIDSpeed);
        leftSlew(PIDSpeed);
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(correctionMultiplier * PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(PIDSpeed * 0.9);
      leftSlew(PIDSpeed);
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed * 0.9);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();
}

void moveMAX(int distance, int heading, int speed) //accounted for v1.09 voltage change
{

  double kP = 0.9; //0.2

  double correctionMultiplier = 0.25; //0.2

  double startUpIncrement = 0.9; //10

  double startSpeed = speed;

  double minSpeed = 90; //35

  double target = abs(L.get_value()) + ticsPerRotation * (distance / (wheelDiameter * pi));

  while(abs(L.get_value()) < target)
  {

    double error = target - abs(L.get_value());

    double PIDSpeed = minSpeed + speed * error / target;

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = PIDSpeed - startSpeed;

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(correctionMultiplier * PIDSpeed);
        leftSlew(PIDSpeed);
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(correctionMultiplier * PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(PIDSpeed * 0.9);
      leftSlew(PIDSpeed);
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed * 0.9);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();
}

void moveLoaded(int distance, int heading, int speed) //accounted for v1.09 voltage control
{

  double kP = 0.35; //0.34

  double correctionMultiplier = 0.2;

  double startUpIncrement = 0.025; //0.0015

  double startSpeed = speed;

  double minSpeed = 35; //90

  double target = abs(L.get_value()) + ticsPerRotation * (distance / (wheelDiameter * pi));

  while(abs(L.get_value()) < target)
  {

    double error = target - abs(L.get_value());

    double PIDSpeed = minSpeed + speed * error / target;

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = PIDSpeed - startSpeed;

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(correctionMultiplier * PIDSpeed);
        leftSlew(PIDSpeed);
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(correctionMultiplier * PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(PIDSpeed * 0.9);
      leftSlew(PIDSpeed);
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed * 0.9);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(PIDSpeed);
      leftSlew(PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();
}

void moveBack(int distance, int heading, int speed) //-O
{

  double correctionMultiplier = 0.8;

  double minSpeed = 35;

  double startUpIncrement = 0.004; //0.01;

  double startSpeed = speed;

  double startingPoint = L.get_value();

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    double error = target - L.get_value();

    //double error = L.get_value() - target;

    double PIDSpeed = minSpeed + speed * error / (target - startingPoint);

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = (PIDSpeed - startSpeed);

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-(correctionMultiplier * PIDSpeed));
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(-(correctionMultiplier * PIDSpeed));
        leftSlew(-PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-(PIDSpeed * 0.9));
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(-(PIDSpeed * 0.9));
      leftSlew(-PIDSpeed);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();

  wait(200);

  coast();



}

void moveBackMAX(int distance, int heading, int speed) //-O
{

  double correctionMultiplier = 0.8;

  double minSpeed = 70; //80

  double startUpIncrement = 0.99; //0.01;

  double startSpeed = speed;

  double startingPoint = L.get_value();

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    double error = target - L.get_value();

    double PIDSpeed = minSpeed + speed * error / (target - startingPoint);

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = (PIDSpeed - startSpeed);

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-(correctionMultiplier * PIDSpeed));
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(-(correctionMultiplier * PIDSpeed));
        leftSlew(-PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-(PIDSpeed * 0.9));
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(-(PIDSpeed * 0.9));
      leftSlew(-PIDSpeed);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();

  wait(200);

  coast();

}

void moveBackNoPID(int distance, int heading, int speed) //-O
{

  double correctionMultiplier = 0.8;

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(-speed);
        leftSlew(-(correctionMultiplier * speed));
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(-(correctionMultiplier * speed));
        leftSlew(-speed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(-speed);
        leftSlew(-speed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(-speed);
      leftSlew(-(speed * 0.9));
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(-(speed * 0.9));
      leftSlew(-speed);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(-speed);
      leftSlew(-speed);
    }
  }
}

  right(0);
  left(0);
}

void moveBackNoPos(int distance, int speed) //-O
{

  double correctionMultiplier = 0.8;

  double minSpeed = 35;

  double startUpIncrement = 0.004; //0.01;

  double startSpeed = speed;

  double startingPoint = L.get_value();

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    double error = target - L.get_value();

    //double error = L.get_value() - target;

    double PIDSpeed = minSpeed + speed * error / (target - startingPoint);

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = (PIDSpeed - startSpeed);

    startSpeed = startSpeed - startUpIncrement;

    rightSlew(-PIDSpeed);
    leftSlew(-PIDSpeed);
}

  right(0);
  left(0);
  brake();

  wait(200);

  coast();
}

void moveBackFast(int distance, int heading, int speed) //accounted for v1.09 voltage change
{

  double correctionMultiplier = 0.8;

  double minSpeed = 30; //70

  double startUpIncrement = 0.9; //0.5

  double startSpeed = speed;

  double startingPoint = L.get_value();

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    double error = target - L.get_value();

    double PIDSpeed = minSpeed + speed * error / (target - startingPoint);

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = (PIDSpeed - startSpeed);

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-(correctionMultiplier * PIDSpeed));
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(-(correctionMultiplier * PIDSpeed));
        leftSlew(-PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-(PIDSpeed * 0.9));
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(-(PIDSpeed * 0.9));
      leftSlew(-PIDSpeed);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();
  wait(50);
  coast();
}

void moveBackLoaded(int distance, int heading, int speed) // Only used in programming_skills_65();
{

  double correctionMultiplier = 0.8;

  double minSpeed = 30;

  double startUpIncrement = 0.00275; //0.01;

  double startSpeed = speed;

  double startingPoint = L.get_value();

  double targetTics = ticsPerRotation * (distance / (wheelDiameter * pi));

  double target = L.get_value() - targetTics;

  while(L.get_value() > target)
  {

    double error = target - L.get_value();

    //double error = L.get_value() - target;

    double PIDSpeed = minSpeed + speed * error / (target - startingPoint);

    if (startSpeed < 0)
    {
      startSpeed = 0;
    }

    PIDSpeed = (PIDSpeed - startSpeed);

    startSpeed = startSpeed - startUpIncrement;

    if (heading - thetaInDegreesUncorrected >= 5 || heading - thetaInDegreesUncorrected <= -5)
    {
      if (thetaInDegreesUncorrected < heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-(correctionMultiplier * PIDSpeed));
      }

      if (thetaInDegreesUncorrected > heading)
      {
        rightSlew(-(correctionMultiplier * PIDSpeed));
        leftSlew(-PIDSpeed);
      }

      if (thetaInDegreesUncorrected == heading)
      {
        rightSlew(-PIDSpeed);
        leftSlew(-PIDSpeed);
      }
    }
    else
    {
    if (thetaInDegreesUncorrected < heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-(PIDSpeed * 0.9));
    }

    if (thetaInDegreesUncorrected > heading)
    {
      rightSlew(-(PIDSpeed * 0.9));
      leftSlew(-PIDSpeed);
    }

    if (thetaInDegreesUncorrected == heading)
    {
      rightSlew(-PIDSpeed);
      leftSlew(-PIDSpeed);
    }
  }
}

  right(0);
  left(0);
  brake();

  wait(200);

  coast();



}

void sweepRight(int angle) //-O
{

  double kP = 0.9; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 50; //45

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      leftSlew(power);
    }

    left(0);

}

void sweepLeft(int angle) //-O
{
  double kP = 0.7; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 45;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = (abs(angle) - abs(thetaInDegreesUncorrected)) * 2 + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(power);
    }

    right(0);

}

void rightSweep(int angle, int speed) //-O
{
  double targetError = 0.5;

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      leftSlew(speed);
    }
    left(0);
}

void rightSweepBack(int angle, int speed) //-O
{
  double targetError = 0.5;

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      right(-speed);
    }
    right(0);
}

void leftSweep(int angle, int speed) //-O
{
  double targetError = 0.5;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      rightSlew(speed);
    }

    right(0);
}

void leftSweepBack(int angle, int speed) //-O
{
  double targetError = 0.5;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      left(-speed);
    }

    left(0);
}

void sweepRightBack(int angle) //-O
{

  double kP = 0.675; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 40;

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(-power);
    }

    left(0);

}

void sweepRightProgramming(int angle, int rightSideSpeed) //-O
{

  double kP = 0.675; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 45; //40

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(rightSideSpeed);
      leftSlew(power);
    }

    left(0);
    right(0);

}

void sweepRightBackProgramming(int angle, int leftSideSpeed) //-O
{

  double kP = 0.75; //0.675

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 45; //45

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(-power);
      leftSlew(leftSideSpeed);
    }

    left(0);
    right(0);

}

void sweepRightBackLoaded(int angle) //-O
{

  double kP = 0.65; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 50;

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(-power);
    }

    left(0);

}

void sweepRightBackNoPID(int angle, int speed) //-O
{

  double targetError = 0.5;
    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      rightSlew(-speed);
    }
    left(0);
}

void sweepLeftBack(int angle) //-O
{

  double kP = 0.675; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 40;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((thetaInDegreesUncorrected - angle) * 2) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      leftSlew(-power);
    }

    left(0);

}

void sweepLeftBackProgramming(int angle, int rightSideSpeed) //-O
{

  double kP = 0.675; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 45; //40

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((thetaInDegreesUncorrected - angle) * 2) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      leftSlew(-power);
      rightSlew(rightSideSpeed);
    }
    right(0);
    left(0);

}

void sweepLeftBackNoPID(int angle, int speed) //-O
{

  double targetError = 0.5;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      leftSlew(-speed);
    }

    left(0);

}

void sweepLeftBackProgramming1(int angle) //-O
{

  double kP = 0.625; //.675

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 50; //40

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((thetaInDegreesUncorrected - angle) * 2) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      leftSlew(-power);
      rightSlew(30); //20
    }

    right(0);
    left(0);

}

void sweepRightBackQuick(int angle) //NOT accounted for v1.09 voltage change
{

  double kP = 0.99; //0.75

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 95;

    while(thetaInDegreesUncorrected < angle - targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((angle - thetaInDegreesUncorrected) * 2) + minSpeed;

      if (error < 0)
      {
        int error = (angle - thetaInDegreesUncorrected) - minSpeed;
      }

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      rightSlew(-power);
    }

    left(0);

}

void sweepLeftBackQuick(int angle) //-O
{

  double kP = 0.75; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 0.5;

  int distToAngle = thetaInDegrees - angle;

  int minSpeed = 95;

    while(thetaInDegreesUncorrected > angle + targetError) //|| thetaInDegrees > angle + targetError)
    {
      int error = ((thetaInDegreesUncorrected - angle) * 2) + minSpeed;

      int integral = integral + error;

      if (error == 0 || error < angle)
      {
        integral = 0;
      }
      if (error > 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      leftSlew(-power);
    }

    left(0);

}

//*******************S-Turn Functions for Autonomous routines******************
void STurn_RedFront()
{
  sweepRightBackQuick(35); //35
  moveRollers(0);
  brakeRollers();
  moveBackMAX(38, 38, 127); //38
  moveRollers(-200);
}

void STurn_RedFront2()
{
  sweepLeftBackQuick(-38);
  moveRollers(0);
  moveBackFast(30, -40, 127);
  turnRightNoPID(0, 50);
}

void STurn_RedFront3()
{
  moveRollers(0);
  leftSweepBack(-28, 200); //-25
  moveRollers(-200);
  moveBackNoPID(26, -30, 200); //26, -30
  sweepRightBackProgramming(-4, 2);
}

void STurn_RedFront4()
{
  moveRollers(0);
  leftSweepBack(-60, 200); //-45
  moveRollers(-200);
  moveBackNoPID(6, -60, 200); //10, -55
  moveRollers(0);
  sweepRightBackProgramming(-6, 5); //-5,2
}

void STurn_BlueFront()
{
  sweepLeftBackQuick(-35);
  moveRollers(0);
  moveBackFast(39, -35, 127); //38
}

void STurn_BlueFront3()
{
  moveRollers(0);
  rightSweepBack(20, 200); //20
  moveRollers(-200);
  moveBackNoPID(28, 20, 200); //26, 20, 200
  moveRollers(0);
  sweepLeftBackProgramming(5, 2); //0
}

void STurn_BlueFront4()
{
  moveRollers(0);
  rightSweepBack(58, 200);
  moveRollers(-200);
  moveBackNoPID(5, 60, 200); //28
  moveRollers(0);
  sweepLeftBackProgramming(5, 2); //3
}

void setDriveMAXCurrent() {
  rightFront.set_current_limit(2500);
  rightBack.set_current_limit(2500);
  leftFront.set_current_limit(2500);
  leftBack.set_current_limit(2500);
}

//***********************DRIVER CONTROL FUNCTIONS**********************
void driveOP()
{
  coast(); //Fail safe if wrong autonomous is selected

  //Current control used to account for lowered current cap of motor after v1.0.9
  //firmware update. Prevents jitter in drive.
  if(master.get_analog(ANALOG_LEFT_Y) < 15 && master.get_analog(ANALOG_LEFT_Y) > -15) {
    leftFront.set_current_limit(1500);
    leftBack.set_current_limit(1500);
  }
  else {
    leftFront.set_current_limit(2500);
    leftBack.set_current_limit(2500);
  }

  if(master.get_analog(ANALOG_RIGHT_Y) < 15 && master.get_analog(ANALOG_RIGHT_Y) > -15) {
    rightFront.set_current_limit(1500);
    rightBack.set_current_limit(1500);
  }
  else {
    rightFront.set_current_limit(2500);
    rightBack.set_current_limit(2500);
  }

  //Tank drive control
  leftFront.move(master.get_analog(ANALOG_LEFT_Y));
  leftBack.move(master.get_analog(ANALOG_LEFT_Y));
  rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
  rightBack.move(master.get_analog(ANALOG_RIGHT_Y));

}

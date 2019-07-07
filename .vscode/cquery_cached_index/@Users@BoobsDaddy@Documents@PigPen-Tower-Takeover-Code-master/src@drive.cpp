#include "main.h"

//motors
pros::Motor leftFront (1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBack (2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBack (9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//Tracking Encoders
pros::ADIEncoder R ('G', 'H', false);
pros::ADIEncoder L ('C', 'D', false);
pros::ADIEncoder S ('E', 'F', false);

//Turn and Move Function Variables and Constants
int targetAngle = 0;

//Position Tracking Constants and Variables
//const double pi = 3.14159;
const double wheelDiameter = 3.1875;
const double ticsPerRotation = 360;
const double leftOffset = 4.546875;
const double rightOffset = 4.609375;
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


void current_position(void* parameter)
{
  pros::lcd::initialize();

  while(true)
  {

  double LInches = (L.get_value() * -1) * pi * wheelDiameter / ticsPerRotation;
  double RInches = (R.get_value() * -1) * pi * wheelDiameter / ticsPerRotation;
  double SInches = (S.get_value() * -1) * pi * wheelDiameter / ticsPerRotation;

  currentL = LInches;
  currentR = RInches;
  currentS = SInches;

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

  thetaInDegrees = thetaInDegrees -  360 * floor(thetaInDegrees / 360);

  if (thetaInDegrees < 0)
  {
    thetaInDegrees = 360 + thetaInDegrees;
  }

//X & Y Calculation
  if (deltaTheta == 0)
  {
    deltaxlocal = deltaS;
    deltaylocal = deltaR;
  }
  else
  {
    deltaxlocal = 2 * sin(deltaTheta / 2) * ((deltaS / deltaTheta) + rearOffset);

    deltaylocal = 2 * sin(deltaTheta / 2) * ((deltaR / deltaTheta) + rightOffset);
  }


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


  pros::delay(20);
  //Display to Screen
  //IDENTIFIERS:: d = int, f = float


  pros::lcd::print(1, "Theta - Absolute: %f", thetaInDegrees);
  //pros::lcd::print(2, "deltaS %f", deltaS);
  pros::lcd::print(2, "R side Value: %d", R.get_value());
  pros::lcd::print(3, "L side Value: %d", L.get_value());
  pros::lcd::print(5, "X global %f", xglobal);
  pros::lcd::print(6, "Y global %f", yglobal);

  }

}

//************BASIC FUNCTIONS*******************
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

void wait(int duration)
{
  pros::delay(duration);
}

//slew control
const int accel_step = 9;
const int deccel_step = 256; // no decel slew
static int leftSpeed = 0;
static int rightSpeed = 0;

void leftSlew(int leftTarget){
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
void rightSlew(int rightTarget){
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



//****************TURN AND MOVE FUNCTIONS*****************
void turnToAbs(int angle)
{

  double kP = 0.025; //0.17;

  double kI = 0;

  double kD = 0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 1.5;

  int distToAngle = thetaInDegrees - angle;


  if (distToAngle <= -180)
  {
    while(thetaInDegrees < angle - targetError || thetaInDegrees > angle + targetError)
    {
      int error = (angle - thetaInDegrees) * 100;

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

      pros::delay(60);

      rightSlew(power);
      leftSlew(-power);
    }

    right(0);
    left(0);

  }
  else
  {
    while(thetaInDegrees < angle - targetError || thetaInDegrees > angle + targetError)
    {
      int error = (angle - thetaInDegrees) * 100;

      int integral = integral + error;

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      pros::delay(60);

      rightSlew(-power);
      leftSlew(power);
    }

    left(0);
    right(0);

  }

  wait(200);

}

void move(int distance, int heading, int speed)
{
  double correctionMultiplier = 0.2;

  double minSpeed = 2;

  double target = ticsPerRotation * (distance / (wheelDiameter * pi));

  while(abs(L.get_value()) < target)
  {

    double error = target - L.get_value();

    double PIDSpeed = minSpeed + speed * error / target;

    if (heading - thetaInDegrees >= 3 || heading - thetaInDegrees <= -3)
    {
      if (thetaInDegrees < heading)
      {
        rightSlew(correctionMultiplier * PIDSpeed);
        leftSlew(PIDSpeed);
      }

      if (thetaInDegrees > heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(correctionMultiplier * PIDSpeed);
      }

      if (thetaInDegrees == heading)
      {
        rightSlew(PIDSpeed);
        leftSlew(PIDSpeed);
      }
    }

    if (thetaInDegrees < heading)
    {
      right(PIDSpeed * 0.5);
      left(PIDSpeed);
    }

    if (thetaInDegrees > heading)
    {
      right(PIDSpeed);
      left(PIDSpeed * 0.5);
    }

    if (thetaInDegrees == heading)
    {
      right(PIDSpeed);
      left(PIDSpeed);
    }
  }

  right(0);
  left(0);
  brake();

  wait(200);

  coast();



}

void driveOP()
{
  leftFront.move(master.get_analog(ANALOG_LEFT_Y));
  leftBack.move(master.get_analog(ANALOG_LEFT_Y));
  rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
  rightBack.move(master.get_analog(ANALOG_RIGHT_Y));
}

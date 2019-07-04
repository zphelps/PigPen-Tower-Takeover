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

//Position Tracking Constants and Variables

const double pi = 3.14159;
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

void turnToAbs(int angle)
{
  double kP = 0.17;

  double kI = 0;

  double kD = 0.3; //0.3

  double prevError = 0;

  double targetError = 2.5;

  int distToAngle = thetaInDegrees - angle;

  if (distToAngle <= -180)
  {
    while(thetaInDegrees < angle - targetError || thetaInDegrees > angle + targetError)
    {
      int error = (angle - thetaInDegrees) * 10;

      int integral = integral + error;

      if (error == 0 || error > angle)
      {
        integral = 0;
      }
      if (error == 50)
      {
        integral = 0;
      }

      int derivative = error - prevError;

      prevError = error;

      int power = error*kP + integral*kI + derivative*kD;

      pros::delay(50);

      right(power);
      left(-power);
    }

    right(0);
    left(0);
  }
  else
  {
    while(thetaInDegrees < angle - targetError || thetaInDegrees > angle + targetError)
    {
      int error = (angle - thetaInDegrees) * 10;

      int integral = integral + error;

      int derivative = error - prevError;

      prevError = error;

      int power = error*kP + integral*kI + derivative*kD;

      pros::delay(50);

      right(-power);
      left(power);
    }

    right(0);
    left(0);
  }


}



void driveOP()
{
  leftFront.move(master.get_analog(ANALOG_LEFT_Y));
  leftBack.move(master.get_analog(ANALOG_LEFT_Y));
  rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
  rightBack.move(master.get_analog(ANALOG_RIGHT_Y));
}


/*
void current_position(void* parameter)
{

  pros::lcd::initialize();

  int R_pos = 0;
  int L_pos = 0;
  int S_pos = 0;

  R.reset();
  L.reset();
  S.reset();

  //pros::lcd::print(0, "L: %d", L_pos);

  while(true)
  {
    //Get Value
    R_pos = R.get_value();
    L_pos = L.get_value();
    S_pos = S.get_value();

    pros::delay(100);
    //Display to Screen
    pros::lcd::print(0, "R: %d", R_pos);
    pros::lcd::print(1, "L: %d", L_pos);
    pros::lcd::print(2, "S: %d", S_pos);

  }
}
*/

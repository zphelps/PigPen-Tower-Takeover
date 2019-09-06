#include "main.h"

//motors
pros::Motor tilter (17, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIPotentiometer tilterPot ('H');

//Autonomous FUNCTIONS

void moveTilter(int speed)
{
  tilter.move(speed);
}

void score()
{
  double kP = 0.2;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 65;

  while(tilterPot.get_value() < 1400 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1400 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 550)
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      moveRollers(25);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  wait(100);
}

void tilterTowerPos()
{
  double kP = 0.4;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() < 650 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (650 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(-power);
  }
  moveTilter(0);
  wait(100);
}

void tilterBack()
{
  double kP = 0.3;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() > 175 + targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (tilterPot.get_value()) - 175 + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(power);
  }
  moveTilter(0);
  wait(100);
}

void tilterOP()
{
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //pros::lcd::print(1, "%d", tilterPot.get_value());

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    score();
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    tilter.move(127);
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    if(tilterPot.get_value() < 750)
    {
      tilter.move(-127);
    }
    else
    {
      tilter.move(0);
    }
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    if(tilterPot.get_value() > 190)
    {
      tilter.move(75);
    }
    else
    {
      tilter.move(0);
    }
  }
  else {
    tilter.move_velocity(0);
  }
}

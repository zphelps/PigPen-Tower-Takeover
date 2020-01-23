#include "main.h"

//motors
pros::Motor tilter (1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIPotentiometer tilterPot ('H');

//Autonomous FUNCTIONS

void moveTilter(int speed)
{
  tilter.move(speed);
}

void brakeTilter() {
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void scoreRedFront()
{
  double kP = 0.4;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 90;

  while(tilterPot.get_value() < 1400 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1400 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 650)
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

void scoreProgramming()
{
  double kP = 0.17;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 65;

  while(tilterPot.get_value() < 1450 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1450 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 600)
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      moveRollers(20);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  wait(100);
}


void scoreOP()
{
  double kP = 0.18; //0.175

  double kD = 0.1;//2

  double prevError = 0;

  double targetError = 10;//20

  int minSpeed = 35; //1450

  while(tilterPot.get_value() < 1350 - targetError) //1465
  {

    driveOP();
    rollersOP();
    liftOP();

    int error = (1350 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1250) //800
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 200) {
      moveRollers(45);
    }
    else
    {
      moveRollers(10);
      Lift(10);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  //wait(100);
}

void scoreAuton()
{
  double kP = 0.235;

  double kD = 0.1;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 70;

  while(tilterPot.get_value() < 1525 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1525 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 700)
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 150) {
      moveRollers(80);
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

void scoreAuton2()
{
  double kP = 0.4;

  double kD = 0.1;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 90;

  while(tilterPot.get_value() < 1475 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1475 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 725) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 100) {
      moveRollers(80);
    }
    else
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  wait(100);
}

void scoreAutonSlow()
{
  double kP = 0.15;

  double kD = 0.035;

  double prevError = 0;

  double targetError = 150;

  int minSpeed = 75;

  while(tilterPot.get_value() < 1300 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1300 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 900) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 200) {
      moveRollers(80);
    }
    else
    {
      moveRollers(10);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
}

void halfwayPos()
{

  double kP = 0.5;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() < 350 - targetError) //|| thetaInDegrees > angle + targetError)
  {

    driveOP();
    rollersOP();

    int error = (400 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(-power);
    moveRollers(-20);
    rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  moveTilter(0);
  moveRollers(0);
}

void halfwayPos(void*parameter)
{

  double kP = 0.5;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() < 250 - targetError) //|| thetaInDegrees > angle + targetError)
  {

    int error = (250 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(-power);
    moveRollers(-20);
    rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  moveTilter(0);
  moveRollers(0);
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

void tilterBack(void* parameter)
{
    while(tilterPot.get_value() > 10) //150
    {
      moveTilter(200);
      Lift(5);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    Lift(0);
    moveTilter(0);
    wait(100);
  }

void tilterBack2()
{
    while(tilterPot.get_value() > 10) //150
    {
      driveOP();
      rollersOP();
      moveTilter(200);
      Lift(5);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    Lift(0);
    moveTilter(0);
    wait(100);
}

void tilterOP()
{
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::lcd::print(3, "%d", tilterPot.get_value());
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    //scoreAuton();
    scoreOP();
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    //scoreAuton();
    halfwayPos();
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    tilter.move(127);
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    //pros::Task tilter_back(tilterBack);
    tilterBack2();
  }

  else {
    tilter.move_velocity(0);
  }
}

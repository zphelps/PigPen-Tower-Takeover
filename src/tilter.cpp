#include "main.h"

//motors
pros::Motor tilter (1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES); //f

//Sensors
pros::ADIPotentiometer tilterPot ('H');
pros::ADIDigitalIn tilterLimit ('G');

//Autonomous FUNCTIONS

void moveTilter(int speed)
{
  tilter.move(speed);
}

void brakeTilter() {
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void coastTilter() {
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Tilter PID loop used for driver control
void scoreOP()
{
  double kP = 0.125; //0.12

  double kD = 0.75;//15

  double prevError = 0;

  double targetError = 10;//20

  int minSpeed = 40; //25

  while(tilterPot.get_value() < 2250 - targetError) //2300
  {

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      //pros::Task tilter_back(tilterBack);
      tilterBack2();
      break;
    }

    driveOP();
    rollersOP();
    liftOP();

    int error = (2250 - tilterPot.get_value()) + minSpeed; //1400

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 875) //875
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else
    {
      Lift(5);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  //wait(100);
}

//Primary autonomous PID loop
void scoreAuton7cube()
{
  double kP = 0.185; //0.13

  double kD = 0.1;

  double prevError = 0;

  double targetError = 50; //25

  int minSpeed = 35; //35 50

  while(tilterPot.get_value() < 2300 - targetError) //2375
  {
    int error = (2300 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1200) {
      moveRollers(35);
    }
    else
    {
      Lift(10);
      moveRollers(25); //15
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  moveRollers(200);
  Lift(0);
}

void scoreAuton8cube()
{
  double kP = 0.175; //5

  double kD = 0.1;

  double prevError = 0;

  double targetError = 25; //20

  int minSpeed = 10; //80

  while(tilterPot.get_value() < 2350 - targetError) //2375
  {
    int error = (2350 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error < 100) {
      moveRollers(80);
    }
    else
    {
      moveRollers(15); //40
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  moveRollers(200);
  //wait(100);
}

//PID loop used for programming_skills_75() and 9 cube auton
void scoreAuton9Cube()
{
  double kP = 0.16; //15

  double kD = 0.1;

  double prevError = 0;

  double targetError = 25; //30

  int minSpeed = 30; //25

  while(tilterPot.get_value() < 2300 - targetError) //2375
  {
    int error = (2300 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error < 100) {
      moveRollers(80);
    }
    else
    {
      Lift(2);
      moveRollers(20); //15
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  moveRollers(200);
  Lift(0);
}

//Function
void halfwayPos()
{

  double kP = 0.9;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() < 750 - targetError) //|| thetaInDegrees > angle + targetError)
  {

    driveOP();
    rollersOP();

    int error = (750 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(-power);
    moveRollers(-20);
    rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  moveTilter(0);
  //moveRollers(0);
}

//Task
void halfwayPos(void*parameter)
{

  double kP = 0.9;

  double kD = 0;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 100;

  while(tilterPot.get_value() < 750 - targetError) //|| thetaInDegrees > angle + targetError)
  {

    int error = (750 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    moveTilter(-power);
    moveRollers(-200); //-20
    rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  moveTilter(0);
  brakeTilter();
  //moveRollers(0);
}

void liftTilterPos(void*parameter)
{

  while(tilterPot.get_value() < 600) {
    tilter.move(-100);
  }
  tilter.move(0);
  brakeTilter();
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
    while(tilterLimit.get_value() == 0) //300
    {
      moveTilter(200);
      Lift(5);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    Lift(0);
    moveTilter(0);
}

void tilterBack2()
{
    while(tilterLimit.get_value() == 0) //300
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
}

void tilterBackSlow(void*parameter)
{
    while(tilterLimit.get_value() == 0) //300
    {
      moveTilter(20);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(0);
}

void tilterOP()
{

  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::lcd::print(3, "%d", tilterPot.get_value());

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    scoreOP();
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    if(tilterPot.get_value()< 400) {
      tilter.move(-100);
    }
    else{
      tilter.move(0);
    }
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    if(tilterLimit.get_value() == 0) {
      tilter.move(30);
    }
    else {
      tilter.move(0);
    }
  }
  else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    tilterBack2();
  }

  else {
    tilter.move_velocity(0);
  }
}

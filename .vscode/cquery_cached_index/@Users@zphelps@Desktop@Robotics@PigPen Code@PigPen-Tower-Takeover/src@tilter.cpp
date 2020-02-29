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
  double kP = 0.125; //0.11

  double kD = 0;//15

  double prevError = 0;

  double targetError = 10;//20

  int minSpeed = 40; //50

  while(tilterPot.get_value() < 2350 - targetError) //2375
  {

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      //pros::Task tilter_back(tilterBack);
      tilterBack2();
      break;
    }

    driveOP();
    rollersOP();
    liftOP();

    int error = (2350 - tilterPot.get_value()) + minSpeed; //1400

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
      //moveRollers(15);
      Lift(5);
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
  double kP = 0.225;

  double kD = 0.1;

  double prevError = 0;

  double targetError = 20;

  int minSpeed = 45;

  while(tilterPot.get_value() < 1350 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1350 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1000) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 350) {
      moveRollers(20);
    }
    else
    {
      Lift(10);
      moveRollers(10);
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  Lift(0);
  moveTilter(0);
  moveRollers(200);
}

void scoreAuton7cube()
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

    if(error > 1200) //725
    {
      //rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      //leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 100) {
      moveRollers(80);
    }
    else
    {
      moveRollers(40); //40
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  moveRollers(200);
  //wait(100);
}

void scoreAuton8cube()
{
  double kP = 0.35; //4

  double kD = 0.1;

  double prevError = 0;

  double targetError = 25; //20

  int minSpeed = 50; //65

  while(tilterPot.get_value() < 1325 - targetError) //1475
  {
    int error = (1325 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1100) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 100) {
      moveRollers(80);
    }
    else
    {
      moveRollers(30); //40
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
  moveRollers(200);
  //wait(100);
}


void scoreAutonSlow()
{
  double kP = 0.17; //15

  double kD = 0.035;

  double prevError = 0;

  double targetError = 75; //175

  int minSpeed = 75;

  while(tilterPot.get_value() < 1375 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1375 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1000) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 200) {
      moveRollers(80);
    }
    else
    {
      moveRollers(20); //10
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
    moveTilter(-power);
  }
  moveTilter(0);
}

void scoreAutonSlow2()
{
  double kP = 0.18;

  double kD = 0.035;

  double prevError = 0;

  double targetError = 100; //150

  int minSpeed = 75;

  while(tilterPot.get_value() < 1375 - targetError) //|| thetaInDegrees > angle + targetError)
  {
    int error = (1375 - tilterPot.get_value()) + minSpeed;

    int derivative = error - prevError;

    prevError = error;

    int power = (error*kP + derivative*kD);

    if(error > 1200) //725
    {
      rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else if(error < 200) {
      moveRollers(80);
    }
    else
    {
      moveRollers(45); //10
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
    if(tilterPot.get_value()> 275) {
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

#include "main.h"

//motors
pros::Motor rightLift(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftLift (5, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIPotentiometer liftPot ('B');

//Lift Constants
int pickUpPos = 950;
int pickUpPosLow = 1075;
int downPos = 1150;
int fourCubes = 350;
int fiveCubes = 100;
int allianceTower = 450;
int shortTower = 450;
int mediumTower = 200;
int towerDeposit = 200;
int mediumTowerDeposit = 50;
int stackOnFourCubes = 200;
int depositLastThreeCubes = 50;
int tallTowerHeight = 25;


void moveLift(int speed)
{
  rightLift.move_velocity(speed);
  leftLift.move_velocity(speed);
}

void lift_brake()
{
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
/*
void set_lift_height(int height)
{

  double kP = 0.15; //0.025; //0.17;

  double kI = 0;

  double kD = 0; //0.06; //0.3; //0.3

  double prevError = 0;

  double targetError = 3;

  int minSpeed = 50;

  if (liftPot.get_value() > height)
  {
      while(liftPot.get_value() > height + targetError) //|| thetaInDegrees > angle + targetError)
      {
        int error = (liftPot.get_value() - height) + minSpeed;

        int integral = integral + error;

        if (error == 0 || error < height)
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

        moveLift(power);

      }

    moveLift(0);
    wait(100);

  }
  if (liftPot.get_value() < height)
  {
    while(liftPot.get_value() < height - targetError) // || thetaInDegrees > angle + targetError)
    {
      int error = (height - liftPot.get_value()) + minSpeed;

      int integral = integral + error;

      int derivative = error - prevError;

      prevError = error;

      int power = (error*kP + integral*kI + derivative*kD);

      //pros::delay(5);

      moveLift(-power);
    }

    moveLift(0);
    wait(100);

  }
}
*/

void pick_up_pos()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < pickUpPos - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > pickUpPos + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void pick_up_pos_low()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < pickUpPosLow - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > pickUpPosLow + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);
      lift_brake();

      done = true;
    }

  }
}

void pickUpTask(void* parameter)
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < pickUpPos - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > pickUpPos + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void lift_down()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < downPos - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > downPos + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);
      lift_brake();

      done = true;
    }
  }
}

void lift_down_task(void* parameter)
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < downPos - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > downPos + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }
  }
}

void deposit_four_cubes()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < fourCubes - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > fourCubes + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void deposit_five_cubes()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < fiveCubes - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > fiveCubes + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void stack_on_four_cubes()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < stackOnFourCubes - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > stackOnFourCubes + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void deposit_last_three_cubes()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < depositLastThreeCubes - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > depositLastThreeCubes + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void alliance_tower_height()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < allianceTower - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > allianceTower + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void alliance_tower_height_task(void* parameter)
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < allianceTower - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > allianceTower + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void short_tower_height()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < shortTower - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > shortTower + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void medium_tower_height()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < mediumTower - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > mediumTower + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void tall_tower_height()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < tallTowerHeight - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > tallTowerHeight + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void medium_tower_deposit()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < mediumTowerDeposit - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > mediumTowerDeposit + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}

void deposit_cube_in_tower()
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < towerDeposit - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > towerDeposit + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);

      lift_brake();

      done = true;
    }

  }
}



//*************************** - OP Control - ***********************************
void liftOP()
{
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightLift.move_velocity(100);
      leftLift.move_velocity(100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      rightLift.move_velocity(-100);
      leftLift.move_velocity(-100);
    }

    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R1))) {
      rightLift.move_velocity(95);
      leftLift.move_velocity(95);
    }
    else {
      leftLift.move(partner.get_analog(ANALOG_LEFT_Y));
      rightLift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }

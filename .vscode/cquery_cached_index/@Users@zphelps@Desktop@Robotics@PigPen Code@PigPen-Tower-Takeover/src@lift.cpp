#include "main.h"

//motors
pros::Motor lift(15, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

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
int mediumTower = 100;
int towerDeposit = 200;
int mediumTowerDeposit = 15;
int stackOnFourCubes = 200;
int depositLastThreeCubes = 50;
int tallTowerHeight = 25;


void Lift(int speed)
{
  lift.move_velocity(speed);
}

void lift_brake()
{
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void moveLift(int time, int speed)
{
/*
  if(tilterPot.get_value() < 750)
  {
    pros::Task halfway_pos(halfwayPos);
  }
  if(tilterPot.get_value() > 190)
  {
    pros::Task tilter_back(tilterBack);
  }
*/
  lift.move_velocity(speed);
  wait(time);
  lift.move_velocity(0);
  lift_brake();

}

void short_tower(void*paramameter) {
  moveLift(1250, -127);
}

//*************************** - OP Control - ***********************************
void liftOP()
{
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      lift.move_velocity(-100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      lift.move_velocity(100);
    }
    else {
      lift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }

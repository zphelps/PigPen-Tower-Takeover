#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

void frontRed()
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 75);
  lift_down();
  pick_up_pos();

  //Second Cube
  move(6, 0, 100);
  lift_down();
  pick_up_pos();

  //Third Cube
  move(6, 0, 100);
  lift_down();
  pick_up_pos();

  brakeRollers();

  //Score In Zone
  sweepRightBack(120);
  wait(100);
  move(30, 120, 200);
  timedDrive(300, 50);

  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Get tower cube
  moveBack(18, 120, 50);
  lift_down();
  turnLeft(0);
  pick_up_pos();
  moveRollers(600);
  move(26, 0, 200);
  lift_down();
  pick_up_pos();

  //score in alliance tower
  sweepRightBack(90);
  alliance_tower_height();
  move(20, 90, 100);
  moveRollers(-600);
  deposit_cube_in_tower();

}

void autonomous()
{

  frontRed();

}

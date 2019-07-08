#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

void frontRed()
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 100);
  lift_down();
  pick_up_pos();

  //Second Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos();

  //Third Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos();

  brakeRollers();

  //Score In Zone
  sweepRightBack(120);
  wait(100);
  move(30, 120, 127);
  timedDrive(300, 50);

  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Get tower cube
  moveBack(18, 120, 50);
  turnLeft(0);
  pros::Task pick_up_task(pickUpTask);
  moveRollers(600);
  move(25, 0, 100);
  lift_down();
  pros::Task allianceTowerTask(alliance_tower_height_task);

  //score in alliance tower
  sweepRightBack(90);
  move(20, 90, 200);
  moveRollers(-600);
  timedDrive(250, 100);
  deposit_cube_in_tower();

}

void autonomous()
{
  frontRed();

  //move(48, 0, 200);

}

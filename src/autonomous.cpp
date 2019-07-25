#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************
void programming_skills_28()
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 50);
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
  moveRollers(0);

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
  pick_up_pos();
  moveBack(2, 0, 35);
  pros::Task allianceTowerTask(alliance_tower_height_task);

  //score in alliance tower
  sweepRightBack(90);
  move(20, 90, 100);
  moveRollers(-600);
  timedDrive(300, 50);
  deposit_cube_in_tower();

  //get center tower Cube
  wait(100);
  moveBack(13, 90, 35);
  wait(100);
  pros::Task pick_up_task2(pickUpTask);
  sweepLeftBack(0);
  moveRollers(600);
  move(24, 0, 127);
  timedDrive(200, 35);
  lift_down();
  moveBack(5, 0, 20);
  pick_up_pos();
  short_tower_height();
  move(10, 0, 20);
  moveRollers(-600);
  deposit_cube_in_tower();
  wait(100);

  //Get Near Tower
  moveBack(15, 0, 20);
  wait(100);
  lift_down();
  moveBack(35, 0, 100);
  timedDrive(500, -35); //Back up against wall

  wait(100);
  move(2, 0, 35);
  sweepLeft(-91);
  pick_up_pos();
  moveRollers(600);
  move(12, -90, 50);
  timedDrive(300, 20);
  lift_down();
  moveBack(5, 0, 20);
  pick_up_pos();
  medium_tower_height();
  move(10, -90, 20);
  moveRollers(-600);
  medium_tower_deposit();
  wait(300);

  //Get middle three Cubes
  moveBack(10, -90, 20);
  turnRight(-2);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(7, 0, 50);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  wait(100);
  moveRollers(0);
  brakeRollers();

  //Deposit in Goal Zone
  turnRight(130);
  move(40, 130, 127);
  stack_on_four_cubes();
  move(8, 130, 45);
  timedDrive(950, 45);

  moveRollers(-600);
  moveLift(100);
  wait(500);
  moveBack(15, 130, 35);

}

void programming_skills_28_fast()
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 50);
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
  moveRollers(0);

  //Score In Zone
  sweepRightBack(120);
  wait(100);
  moveFast(30, 120, 127);
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
  pick_up_pos();
  moveBack(2, 0, 35);
  pros::Task allianceTowerTask(alliance_tower_height_task);

  //score in alliance tower
  sweepRightBack(90);
  moveFast(20, 90, 100);
  moveRollers(-600);
  timedDrive(300, 50);
  deposit_cube_in_tower();

  //get center tower Cube
  wait(100);
  moveBack(12, 90, 35);
  wait(100);
  pros::Task pick_up_task2(pickUpTask);
  sweepLeftBack(0);
  moveRollers(600);
  moveFast(22, 0, 127);
  timedDrive(200, 35);
  lift_down();
  moveBack(5, 0, 20);
  pick_up_pos();
  short_tower_height();
  move(10, 0, 35);
  moveRollers(-600);
  deposit_cube_in_tower();
  moveBack(10, 0, 20);

  //Get Near Tower
  lift_down();
  moveBackFast(40, 0, 127);
  timedDrive(500, -35); //Back up against wall

  wait(100);
  move(2, 0, 35);
  sweepLeft(-91);
  pick_up_pos();
  moveRollers(600);
  move(12, -90, 50);
  timedDrive(300, 20);
  lift_down();
  moveBack(5, -90, 20);
  pick_up_pos();
  medium_tower_height();
  move(10, -90, 20);
  moveRollers(-600);
  medium_tower_deposit();
  wait(300);

  //Get middle three Cubes
  moveBack(11, -90, 20);
  turnRight(-4);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(7, 0, 50);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  wait(100);
  moveRollers(0);
  brakeRollers();

  //Deposit in Goal Zone
  turnRight(130);
  moveFast(40, 130, 127);
  stack_on_four_cubes();
  move(6, 130, 45);
  timedDrive(500, 45);

  moveRollers(-600);
  moveLift(100);
  wait(500);
  moveBack(15, 130, 15);

}

void programming_skills_35()
{

  programming_skills_28_fast();

  //Score far tower
  pros::Task pick_up_task3(pickUpTask);
  moveBack(24, 135, 20);
  sweepLeftBack(90);
  moveBackFast(21, 90, 127);
  turnLeft(0);

  moveRollers(600);
  move(5, 0, 50);
  timedDrive(300, 20);
  lift_down();
  moveBack(3, 0, 20);
  moveLift(100);
  wait(600);
  move(8, 0, 35);
  timedDrive(550, 35);
  moveLift(-100);
  wait(300);
  moveLift(0);
  moveRollers(-600);
  wait(500);

}

//****************RED AUTONOMOUS*****************************
void redFront() //Working as of 7/9/19
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  brakeRollers();

  //Score In Zone
  sweepRightBack(120);
  moveFast(30, 120, 127);
  timedDrive(300, 50);

  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Get tower cube
  moveBackFast(31, 120, 45);
  pros::Task pick_up_task(pickUpTask);
  turnLeft(0);
  moveRollers(600);
  moveFast(20, 0, 127);
  timedDrive(200, 35);
  lift_down();
  moveBack(5, 0, 35);
  pros::Task shortTower(alliance_tower_height_task);
  wait(100);
  move(10, 0, 50);
  moveRollers(-600);
  deposit_cube_in_tower();
  moveBack(10, 0, 50);

}

void blueBack()
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up First Cube
  moveRollers(600);
  move(10, 0, 100);
  lift_down();
  wait(50);
  pick_up_pos();

  //Pick Up Second Cube
  turnRight(90);
  move(18, 90, 75);
  lift_down();
  wait(50);
  pick_up_pos();
  sweepRight(135);
  move(3, 135, 50);
  timedDrive(300, 35);
  lift_down();
  intakeOut();
  deposit_four_cubes();
  moveBack(2, 135, 45);
  sweepLeftBack(0);
}
//***************BLUE AUTONOMOUS*****************************
void blueFront() //Working as of 7/11/19
{
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(15, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  move(5, 0, 100);
  lift_down();
  pick_up_pos_low();

  brakeRollers();

  //Score In Zone
  sweepLeftBack(-120);
  moveFast(30, -120, 127);
  timedDrive(300, 50);

  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Get tower cube
  moveBackFast(29, -120, 35);
  pros::Task pick_up_task(pickUpTask);
  turnRight(0);
  moveRollers(600);
  moveFast(20, 0, 127);
  timedDrive(200, 35);
  lift_down();
  moveBack(5, 0, 35);
  pros::Task shortTower(alliance_tower_height_task);
  wait(100);
  move(10, 0, 50);
  moveRollers(-600);
  deposit_cube_in_tower();
  moveBack(10, 0, 50);

}

void autonomous()
{
  switch(autonIndex){
    case 0:
      redFront();
      break;
    case 1:
      //redBack();
      break;
    case 2:
      blueFront();
      break;
    case 3:
      blueBack();
      break;
    case 4:
      programming_skills_35();
      break;
  }

}

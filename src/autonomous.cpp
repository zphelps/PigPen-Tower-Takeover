#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{
    lift_brake();
    //Pick up first 5 cubes
    moveRollers(-200);
    wait(75);
    moveRollers(200);
    wait(100);
    moveRollers(0);
    wait(250);
    moveRollers(-200);
    move(48, 0, 50);
    moveRollers(0);
    turnRightLoaded(20);
    moveRollers(-200);
    move(30, 0, 80);
    move(30, 0, 127);

    turnRightSmooth(45);
    moveLoaded(10, 45, 127);
    timedDrive(300, 45);

    scoreProgramming();
    moveBack(20, 45, 100);
    pros::Task tilter_back(tilterBack);
    turnLeft(-90);



}
/*
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
*/
/* Before I sped it up even more
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
*/
/*
void programming_skills_28_fast()
{
  move(2, 0, 127);
  pick_up_pos_low();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(12, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  brakeRollers();
  moveRollers(0);

  //Score In Zone
  sweepRightBack(115);
  moveFast(30, 115, 127);
  timedDrive(300, 50);

  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Get alliance tower cube
  moveBack(21, 135, 127);
  pros::Task pick_up_task(pickUpTask);
  wait(100);
  turnLeft(0);
  moveRollers(600);
  move(24, 0, 127);
  lift_down();
  pick_up_pos();
  wait(50);
  moveBackFast(3, 0, 25);
  pros::Task allianceTowerTask(alliance_tower_height_task);

  //score in alliance tower
  sweepRightBack_Programming(90);
  move(20, 90, 127);
  moveRollers(-600);
  timedDrive(350, 50);
  deposit_cube_in_tower();

  //get center tower Cube
  wait(100);
  moveBack(11, 90, 127);
  pros::Task pick_up_task2(pickUpTask);
  wait(150);
  sweepLeftBack_Programming(0);
  moveRollers(600);
  moveFast(22, 0, 127);
  timedDrive(200, 45);
  lift_down();
  moveBackFast(5, 0, 70);
  pick_up_pos();
  alliance_tower_height();
  move(11, 0, 127);
  moveRollers(-600);
  deposit_cube_in_tower();
  wait(175);
  moveBack(10, 0, 127);

  //Get Near Tower
  lift_down();
  moveBack(40, 0, 127);
  timedDrive(250, -35); //Back up against wall

  wait(100);
  move(2, 0, 127);
  sweepLeft_Programming(-90);
  pick_up_pos();
  moveRollers(600);
  move(13, -90, 127);
  timedDrive(300, 30);
  lift_down();
  moveBack(5, -90, 127);
  pick_up_pos();
  medium_tower_height();
  move(14, -90, 127);
  moveRollers(-600);
  medium_tower_deposit();
  wait(300);

  //Get middle three Cubes
  moveBack(11, -90, 127);
  pros::Task pick_up_task3(pickUpTask);
  wait(500);
  turnRight(-5);
  pick_up_pos();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(7, 0, 50);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(5, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(5, 0, 127);
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
  moveBack(15, 135, 20);

}

void programming_skills_35()
{

  programming_skills_28_fast();

  //Score far tower
  pros::Task pick_up_task3(pickUpTask);
  wait(300);
  moveBack(24, 135, 127);
  sweepLeftBack(90);
  moveBackFast(23, 90, 127);
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

*/

//****************RED AUTONOMOUS*****************************

void redFront()
{

  lift_brake();
  //Pick up first 5 cubes
  moveRollers(-200);
  wait(75);
  moveRollers(200);
  wait(100);
  moveRollers(0);
  wait(250);
  moveRollers(-200);
  move(50, 0, 60);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(40, 0, 50);

  //Turn to the corner
  turnRight(130);
  moveLoaded(48, 130, 200);
  moveRollers(0);
  timedDrive(350, 30);
  moveRollers(150);
  wait(85);
  moveRollers(0);
  scoreRedFront();
  //timedDrive(250, 30);
  moveBack(48, 140, 100);

}
/*
void redFront_Four_Cubes() //Working as of 7/9/19
{
  wait(75); //fixes bug where lift moves before drive
  move(3, 0, 127);
  pick_up_pos_low();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(12, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos();

  brakeRollers();

  //Score In Zone
  sweepRightBack(120);
  moveFast(30, 120, 127);
  timedDrive(375, 50);

  lift_down();
  intakeOut();
  deposit_five_cubes();

  //Get tower cube
  moveBack(33, 135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnLeft(0);
  moveRollers(600);
  moveFast(15, 0, 127);
  timedDrive(300, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  move(10, 0, 127);
  moveRollers(-600);
  wait(300);
  moveBack(15, 0, 127);
  pros::Task prepareForMatchPos(pickUpTask);

}

void redFront_Five_Cubes() //Working as of 7/9/19
{
  wait(75); //fixes bug where lift moves before drive
  move(3, 0, 127);
  pick_up_pos_low();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(12, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos();

  //Fourth Cube
  moveFast(4, 0, 127);
  lift_down();
  pick_up_pos_low();

  brakeRollers();

  //Score In Zone
  sweepRightBack(135);
  moveFast(39, 135, 127);
  timedDrive(350, 30);

  lift_down();
  intakeOut();
  wait(25);
  deposit_five_cubes();

  //Get tower cube
  moveBack(33, 135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnLeft(0);
  moveRollers(600);
  moveFast(14, 0, 127);
  timedDrive(250, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  timedDrive(300, 80);
  moveRollers(-600);
  moveLift(-35);
  wait(275);
  timedDrive(300, -50);
  wait(10000);
  //deposit_cube_in_tower();
  //moveBack(10, 0, 127);

}

void redBack()
{
  wait(100);
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up First Cube
  moveRollers(600);
  move(8, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Pick Up Second Cube
  turnLeft(-90);
  move(16, -90, 127);
  lift_down();
  pick_up_pos_low();

  //Deposit in Zone
  sweepLeft(-135);
  move(4, -135, 127);
  timedDrive(300, 35);
  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Score cube in tower
  moveBack(30, -135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnRight(0);
  moveRollers(600);
  move(14, 0, 127);
  timedDrive(250, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  move(8, 0, 127);
  moveRollers(-600);
  deposit_cube_in_tower();
  wait(100);
  timedDrive(300, -50);
  wait(100);
  pros::Task prepareForMatchPos(pickUpTask);
  moveBack(20, 0, 127);
}
*/
//***************BLUE AUTONOMOUS*****************************
void blueFront_Four_Cubes() //Working as of 7/11/19
{
  wait(75); //fixes bug where lift moves before drive
  move(3, 0, 127);
  pick_up_pos_low();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(12, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos();

  brakeRollers();

  //Score In Zone
  sweepLeftBack(-115);
  moveFast(30, -115, 127);
  timedDrive(375, 50);

  lift_down();
  intakeOut();
  deposit_five_cubes();

  //Get tower cube
  moveBack(33, -135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnRight(0);
  moveRollers(600);
  moveFast(15, 0, 127);
  timedDrive(300, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  move(10, 0, 127);
  moveRollers(-600);
  wait(300);
  moveBack(15, 0, 127);
  pros::Task prepareForMatchPos(pickUpTask);

}

void blueFront_Five_Cubes() //Working as of 7/11/19
{
  wait(75); //fixes bug where lift moves before drive
  move(3, 0, 127);
  pick_up_pos_low();

  //Pick Up Row of Cubes
  moveRollers(600);
  move(12, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Second Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Third Cube
  moveFast(3, 0, 127);
  lift_down();
  pick_up_pos();

  //Fourth Cube
  moveFast(4, 0, 127);
  lift_down();
  pick_up_pos_low();

  brakeRollers();

  //Score In Zone
  sweepLeftBack(-125);
  moveFast(39, -125, 127);
  timedDrive(350, 30);

  lift_down();
  intakeOut();
  wait(25);
  deposit_five_cubes();

  //Get tower cube
  moveBack(33, -135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnRight(0);
  moveRollers(600);
  moveFast(14, 0, 127);
  timedDrive(250, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  timedDrive(300, 80);
  moveRollers(-600);
  moveLift(-35);
  wait(275);
  timedDrive(300, -50);
  wait(10000);
}

void blueBack()
{
  wait(100);
  move(2, 0, 50);
  pick_up_pos();

  //Pick Up First Cube
  moveRollers(600);
  move(8, 0, 127);
  lift_down();
  pick_up_pos_low();

  //Pick Up Second Cube
  turnRight(90);
  move(16, 90, 127);
  lift_down();
  pick_up_pos_low();

  //Deposit in Zone
  sweepRight(135);
  move(4, 135, 127);
  timedDrive(300, 35);
  lift_down();
  intakeOut();
  deposit_four_cubes();

  //Score cube in tower
  moveBack(30, 135, 127);
  pros::Task pick_up_task(pickUpTask);
  turnLeft(0);
  moveRollers(600);
  move(14, 0, 127);
  timedDrive(250, 50);
  lift_down();
  wait(25);
  pros::Task shortTower(alliance_tower_height_task);
  moveBack(4, 0, 127);
  move(10, 0, 127);
  moveRollers(-600);
  deposit_cube_in_tower();
  wait(100);
  timedDrive(300, -50);
  wait(100);
  pros::Task prepareForMatchPos(pickUpTask);
  moveBack(20, 0, 127);
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  //programming_skills();
  turnRightLoaded(90);
  //move(48, 0, 127);
  //redFront();
  /*
  switch(autonIndex){
    case 0:
      redFront_Four_Cubes();
      break;
    case 1:
      redFront_Five_Cubes();
      break;
    case 2:
      redBack();
      break;
    case 3:
      blueFront_Four_Cubes();
      break;
    case 4:
      blueFront_Five_Cubes();
      break;
    case 5:
      blueBack();
      break;
    case 6:
      programming_skills_35();
      break;
  }
  */
}

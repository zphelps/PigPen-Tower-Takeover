#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{
/*{
    //Pick up first 5 cubes
    moveRollers(-200);
    wait(200);
    moveRollers(200);
    moveLift(300, 20);
    moveRollers(-200);
    move(44, 0, 75);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(33, 0, 60);
    wait(350);

    //Turn to the corner
    turnRightSmooth(132);
    moveLoaded(42, 132, 127);
    moveRollers(0);
    timedDrive(600, 30);
    moveRollers(125);
    wait(40);
    moveRollers(0);
    scoreOP();
}*/

    //Pick up first 5 cubes
    //moveRollers(-200);
    //wait(130);
    //moveRollers(200);

    deploy();
    moveRollers(-200);
    move(44, 0, 75);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(34, 0, 75);
    wait(350);

    //Turn to the corner
    turnRightSmooth(133);
    moveLoaded(42, 133, 127);
    moveRollers(0);
    moveRollers(125);
    wait(25);
    moveRollers(0);
    wait(100);
    scoreProgramming();
    timedDrive(100, 25);
    wait(200);
    moveBack(33, 132, 60);

    pros::Task tilter_back(tilterBack);

    turnLeft(0); //******************************Consider Changing direction
    wait(250);
    moveRollers(-200);
    move(28, 0, 127);
    moveRollers(-200);
    timedDrive(300, 40);
    moveRollers(-200);
    wait(200);
    moveBack(10, 0, 127);
    moveRollers(200);
    wait(200);
    moveRollers(0);
    brakeRollers();
    pros::Task halfway_pos(halfwayPos);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(450, 100);
    wait(200);
    moveRollers(60);
    moveBack(34, 0, 127);
    pros::Task tilter_back2(tilterBack);
    moveLift(1000, 100);
    turnLeft(-90);

    moveRollers(-200);
    move(12, -90, 127);
    timedDrive(250, 40);
    wait(200);
    moveBack(10, -90, 45);
    moveRollers(200);
    wait(230);
    moveRollers(0);
    brakeRollers();
    pros::Task halfway_pos2(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 50);
    timedDrive(250, 30);
    moveRollers(60);
    wait(300);

    moveBack(2, -90, 30);
    pros::Task tilter_back3(tilterBack);
    moveLift(1500, 100);
    turnRight(-2);

    moveRollers(-200);
    move(101, 0, 127);

    turnRightSmooth(90);
    move(3, 90, 50);

    sweepRight(180);
    move(26, 180, 100);
    wait(250);

    moveBack(26, 180, 127);
    turnLeftSmooth(45);
    move(12, 45, 50);
    moveRollers(0);
    scoreProgramming();
    timedDrive(100, 40);
    wait(200);
    moveBack(48, 45, 50);
    pros::Task tilter_back4(tilterBack);


}

//****************RED AUTONOMOUS*****************************

void red_front_8_cubes()
{

  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 75);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(38, 0, 127);
  wait(100);

  //Turn to the corner
  turnRightLoaded(135);
  moveLoaded(44, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(40);
  moveRollers(0);
  scoreOP();
  pros::Task tilter_back_red_front_8_cubes(tilterBack);
  timedDrive(100, 30);
  moveBack(32, 135, 127);

}

void red_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 75);
  moveRollers(-200);
  sweepRightBack(135);
  moveLoaded(32, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  timedDrive(200, 30);
  pros::Task tilter_back(tilterBack);
  moveBack(27, 132, 100);
}

void red_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(42, 0, 75);
  sweepLeft(-25);
  sweepRight(-20);
  sweepRightBack(0);
  moveBack(3, 0, 40);
  moveRollers(-200);
  wait(100);
  sweepRightBack(135);
  moveLoaded(26, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  timedDrive(350, 30);
  pros::Task tilter_back(tilterBack);
  moveBack(27, 135, 100);
}

//***************BLUE AUTONOMOUS*****************************
void blue_front_8_cubes()
{

  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 75);

  //S-Turn to other Cubes
  STurn_BlueFront();
  moveRollers(-200);
  moveHalfLoaded(38, 0, 127);
  wait(100);

  //Turn to the corner
  turnLeftLoaded(-135);
  moveLoaded(44, -135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(40);
  moveRollers(0);
  scoreOP();
  pros::Task tilter_back_red_front_8_cubes(tilterBack);
  timedDrive(100, 30);
  moveBack(32, -135, 127);

}

void blue_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 75);
  moveRollers(-200);
  sweepLeftBack(-133);
  moveLoaded(31, -133, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  timedDrive(200, 30);
  pros::Task tilter_back(tilterBack);
  moveBack(27, -135, 100);
}

void blue_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(45, 0, 75);
  sweepRight(25);
  sweepLeftBack(0);
  moveBack(3, 0, 40);
  moveRollers(-200);
  wait(100);
  sweepLeftBack(-135);
  moveLoaded(26, -135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  timedDrive(350, 30);
  pros::Task tilter_back(tilterBack);
  moveBack(27, -135, 100);
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  //programming_skills();

  //Red side
  //red_front_8_cubes();
  //red_front_5_cubes();
  //red_front_6_cubes();

  //Blue Side
  //blue_front_8_cubes();
  blue_front_6_cubes();

  /*
  turnLeftLoaded(-90);
  wait(500);
  turnLeftLoaded(-180);
  wait(500);
  turnLeftLoaded(-270);
  wait(500);
  turnLeftLoaded(-360);
  wait(500);
*/
/*
  switch(autonIndex){
    case 0:
      red_front_8_cubes();
      break;
    case 1:
      red_front_5_cubes_tower();
      break;
    case 2:
      red_front_5_cubes_no_tower();
      break;
    case 3:
      //Red Back
      break;
    case 4:
      //Blue Front - 8 Cubes
      break;
    case 5:
      //Blue Front - 5 Cubes, 1 tower
      break;
    case 6:
      //Blue Front - 5 Cubes, no tower
      break;
    case 7:
      //Blue Back
      break;
    case 8:
      programming_skills();
      break;
  }
*/
}

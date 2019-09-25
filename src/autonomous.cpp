#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{

    //Pick up first 5 cubes
    moveLift(50);
    moveRollers(-200);
    wait(75);
    moveLift(0);
    lift_brake();
    moveRollers(200);
    wait(100);
    moveRollers(0);
    wait(250);
    moveRollers(-200);
    move(47, 0, 60);
    wait(200);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(38, 0, 60);
    wait(200);

    //Turn to the corner
    turnRightSmooth(135);
    moveLoaded(44, 135, 127);
    moveRollers(0);
    timedDrive(400, 20);
    moveRollers(150);
    wait(110);
    moveRollers(0);
    scoreOP();
    moveBack(20, 135, 100);

    pros::Task tilter_back(tilterBack);

    turnLeft(0); //******************************Consider Changing direction
    moveRollers(-200);
    move(36, 0, 127);
    wait(100);
    moveBack(8, 0, 127);
    moveRollers(200);
    wait(150);
    moveRollers(0);
    moveLift(-100);
    wait(1000);
    moveLift(0);
    move(8, 0, 127);
    moveRollers(100);

}

//****************RED AUTONOMOUS*****************************

void redFront()
{

  //Pick up first 5 cubes
  moveLift(50);
  moveRollers(-200);
  wait(75);
  moveLift(0);
  lift_brake();
  moveRollers(200);
  wait(100);
  moveRollers(0);
  wait(250);
  moveRollers(-200);
  move(50, 0, 75);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(40, 0, 75);

  //Turn to the corner
  turnRightSmooth(135);
  moveLoaded(44, 135, 127);
  moveRollers(0);
  timedDrive(400, 20);
  moveRollers(150);
  wait(90);
  moveRollers(0);
  scoreOP();
  moveBack(48, 140, 100);

}

//***************BLUE AUTONOMOUS*****************************


//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  programming_skills();


  //sweepRightBackLoaded(45);
  //move(9, 45, 35);
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

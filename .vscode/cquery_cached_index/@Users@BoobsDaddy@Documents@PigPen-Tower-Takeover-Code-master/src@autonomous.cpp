#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{

    //Pick up first 5 cubes
    moveLift(100, 50);
    moveRollers(-200);
    wait(75);
    moveRollers(200);
    wait(100);
    moveRollers(0);
    wait(250);
    moveRollers(-200);
    move(44, 0, 60);
    wait(350);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(33, 0, 60);
    wait(350);

    //Turn to the corner
    turnRightSmooth(135);
    moveLoaded(44, 135, 127);
    moveRollers(0);
    timedDrive(600, 50);
    moveRollers(125);
    wait(75);
    moveRollers(0);
    scoreOP();
    moveBack(32, 137, 50);

    pros::Task tilter_back(tilterBack);

    turnLeft(0); //******************************Consider Changing direction
    moveRollers(-200);
    move(32, 0, 127);
    wait(100);
    moveBack(8, 0, 127);
    moveRollers(200);
    wait(150);
    moveRollers(0);
    moveLift(1000, 127);
    moveLift(0, 0);
    move(8, 0, 127);
    moveRollers(100);

}

//****************RED AUTONOMOUS*****************************

void redFront()
{

  //Pick up first 5 cubes
  moveLift(100, 50);
  moveRollers(-200);
  wait(75);
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

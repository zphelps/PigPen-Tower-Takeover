#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{

    //Pick up first 5 cubes
    moveRollers(-200);
    wait(100);
    moveRollers(200);
    wait(250);
    moveRollers(0);
    brakeRollers();
    moveLift(300, 20);
    moveRollers(-200);
    move(44, 0, 60);
    wait(350);

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
    moveBack(32, 132, 50);

    pros::Task tilter_back(tilterBack);

    turnLeft(0); //******************************Consider Changing direction
    wait(750);
    moveRollers(-200);
    move(28, 0, 127);
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
    moveRollers(75);
    moveBack(34, 0, 127);
    pros::Task tilter_back2(tilterBack);
    moveLift(1000, 100);
    turnLeft(-90);

    moveRollers(-200);
    move(12, -90, 127);
    timedDrive(250, 40);
    wait(200);
    moveBack(10, -90, 50);
    moveRollers(200);
    wait(200);
    moveRollers(0);
    brakeRollers();
    pros::Task halfway_pos2(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 50);
    timedDrive(250, 30);
    moveRollers(75);
    wait(300);

    moveBack(2, -90, 50);
    pros::Task tilter_back3(tilterBack);
    moveLift(1500, 100);
    turnRight(0);

    moveRollers(-200);
    move(99, 0, 127);

    turnRightSmooth(90);
    move(5, 90, 50);

    sweepRight(180);
    move(26, 180, 100);
    wait(250);

    moveBack(28, 180, 127);
    turnLeftSmooth(45);
    move(6, 45, 35);
    moveRollers(-200);
    timedDrive(600, 40);
    moveRollers(0);
    brakeRollers();
    scoreOP();
    timedDrive(250, 30);
    pros::Task tilter_back4(tilterBack);
    moveBack(48, 45, 50);


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

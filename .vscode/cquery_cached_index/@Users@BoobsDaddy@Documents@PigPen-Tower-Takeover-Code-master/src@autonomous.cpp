#include "main.h"

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
    deploy();
    moveRollers(-200);
    move(44, 0, 75);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(34, 0, 75);
    wait(350);

    //Turn to the corner
    turnRightLoaded(135);
    moveLoaded(42, 135, 127);
    moveRollers(0);
    moveRollers(125);
    wait(20);
    moveRollers(0);
    scoreProgramming();
    pros::Task task1(tilterBack);
    timedDrive(250, 40);
    wait(200);
    moveBack(25, 132, 127);

    turnLeft(0); //******************************Consider Changing direction
    wait(250);
    moveRollers(-200);
    move(21, 0, 127);
    moveRollers(-200);
    timedDrive(300, 40);
    moveRollers(-200);
    wait(200);
    moveBack(10, 0, 127);
    moveRollers(200);
    wait(200);
    moveRollers(0);
    brakeRollers();
    pros::Task task2(halfwayPos);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(450, 100);
    wait(200);
    moveRollers(75);
    moveBack(33, 0, 127);
    pros::Task task3(tilterBack);
    moveLift(1000, 100);
    turnLeft(-90);

    moveRollers(-200);
    move(12, -90, 100);
    timedDrive(250, 40);
    wait(200);
    moveBack(10, -90, 40);
    moveRollers(200);
    wait(200);
    moveRollers(0);
    brakeRollers();
    pros::Task task4(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBack(3, -90, 40);
    pros::Task task5(tilterBack);
    moveLift(1500, 100);
    turnRight(-3);

    moveRollers(-200);
    move(101, 0, 127);

    turnRightHalfLoaded(90);
    move(4, 90, 50);

    sweepRight(180);
    move(24, 180, 100);
    wait(250);

    moveBack(20, 180, 100);
    turnLeftLoaded(48);
    move(12, 48, 50);
    timedDrive(200, 40);
    moveRollers(0);
    moveRollers(125);
    wait(20);
    moveRollers(0);
    scoreProgramming();
    pros::Task task6(tilterBack);
    timedDrive(250, 40);
    wait(200);
    moveBack(25, 132, 127);
    task1.remove();
    task2.remove();
    task3.remove();
    task4.remove();
    task5.remove();
    task6.remove();
}

//****************RED AUTONOMOUS*****************************
/*
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
  scoreAuton();
  pros::Task tilter_back_red_front_8_cubes(tilterBack);
  timedDrive(100, 30);
  moveBack(32, 135, 127);

}
*/

void red_front_8_cubes()
{
  deploy();
  moveRollers(-200);
  move(44, 0, 75);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(34, 0, 75);
  wait(350);

  //Turn to the corner
  turnRightLoaded(135);
  moveLoaded(42, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(20);
  moveRollers(0);
  scoreAuton();
  pros::Task task1(tilterBack);
  timedDrive(250, 40);
  wait(175);
  moveBack(25, 132, 127);
  task1.remove();
}

void red_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(43, 0, 75);
  moveRollers(-200);
  sweepRightBack(135);
  moveLoaded(32, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  pros::Task task1(tilterBack);
  timedDrive(250, 30);
  moveBack(27, 132, 100);
  task1.remove();
}

void red_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(42, 0, 75);
  sweepLeft(-25);
  wait(200);
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
  pros::Task task1(tilterBack);
  timedDrive(250, 30);
  moveBack(27, 135, 100);
  task1.remove();
}

void red_back()
{
  pros::Task task1(halfwayPos);
  moveLift(1400, -127);
  sweepRight(65);
  moveRollers(75);
  wait(550);
  sweepLeftBack(0);
  pros::Task task2(tilterBack);
  moveLift(1500, 100);
  moveRollers(-200);
  move(1, 0, 40);
  sweepLeft(-90);
  move(12, -90, 100);
  sweepLeft(-135);
  moveRollers(200);
  wait(2000);

  moveBack(20, -135, 127);
  task1.remove();
  task2.remove();
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
  moveHalfLoaded(35, 0, 75);
  wait(100);

  //Turn to the corner
  turnLeftLoaded(-135);
  moveLoaded(42, -135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(20);
  moveRollers(0);
  scoreAuton();
  pros::Task task1(tilterBack);
  timedDrive(250, 40);
  wait(175);
  moveBack(32, -132, 127);
  task1.remove();
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
  pros::Task task1(tilterBack);
  moveBack(27, -135, 100);
  task1.remove();
}

void blue_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(45, 0, 75);
  sweepRight(25);
  wait(200);
  sweepLeftBack(0);
  moveBack(2, 0, 40);
  moveRollers(-200);
  wait(100);
  sweepLeftBack(-135);
  moveLoaded(26, -135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  scoreOP();
  pros::Task task1(tilterBack);
  timedDrive(250, 30);
  moveBack(27, -135, 100);
  task1.remove();
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  programming_skills();

  //Red side
  //red_front_8_cubes();
  //red_front_5_cubes();
  //red_front_6_cubes();
  //red_back();

  //Blue Side
  //blue_front_8_cubes();
  //blue_front_5_cubes();
  //blue_front_6_cubes();

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
      red_front_6_cubes();
      break;
    case 2:
      red_front_5_cubes();
      break;
    case 3:
      //Red Back
      break;
    case 4:
      blue_front_8_cubes();
      break;
    case 5:
      blue_front_6_cubes();
      break;
    case 6:
      blue_front_5_cubes();
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

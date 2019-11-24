#include "main.h"

//*****************PROGRAMMING SKILLS************************

void programming_skills()
{
    deploy();
    timedDrive(300, -40);
    wait(300);
    moveRollers(-200);
    move(43, 0, 75);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(36, 0, 75);
    wait(350);

    //Turn to the corner
    turnRightLoadedProgramming(134);
    wait(250);
    moveLoaded(41, 134, 127);
    timedDrive(250, 40);
    moveRollers(0);
    moveRollers(15);
    wait(15);
    scoreAuton2();
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBackLoaded(25, 135, 80);

    turnLeftProgramming(0); //******************************Consider Changing direction
    wait(250);
    moveRollers(-200);
    move(21, 0, 127);
    moveRollers(-200);
    timedDrive(300, 40);
    moveRollers(-200);
    wait(200);
    moveBackLoaded(10, 0, 40);
    moveRollers(200);
    wait(220);
    moveRollers(0);
    brakeRollers();
    pros::Task task2(halfwayPos);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(400, 100);
    wait(200);
    moveRollers(75);
    moveBack(32, 0, 127);
    pros::Task task3(tilterBack);
    moveLift(1000, 100);
    turnLeftProgramming(-88);

    moveRollers(-200);
    move(12, -90, 100);
    timedDrive(250, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    moveRollers(200);
    wait(225);
    moveRollers(0);
    brakeRollers();
    pros::Task task4(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBackLoaded(3, -90, 10);
    pros::Task task5(tilterBack);
    moveLift(1500, 100);
    turnRightProgramming(-2);

    moveRollers(-200);
    move(101, -2, 127);

    turnRightHalfLoaded(89);
    move(5, 90, 50);

    sweepRight(176);
    move(19, 178, 100);
    wait(250);

    brakeRollers();
    moveBack(22, 180, 80);
    moveRollers(0);
    brakeRollers();
    turnLeftLoaded(44);
    move(12, 43, 50);
    timedDrive(425, 50);
    moveRollers(0);
    moveRollers(15);
    wait(15);
    scoreAuton();
    pros::Task task6(tilterBack);
    moveRollers(90);
    moveBackNoPos(18, 127);
    moveTilter(0);
    task1.remove();
    task2.remove();
    task3.remove();
    task4.remove();
    task5.remove();
    task6.remove();
    turnLeft(-90);

    moveRollers(-200);
    move(14, -90, 100);
    timedDrive(250, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    moveRollers(200);
    wait(200);
    moveRollers(0);
    brakeRollers();
    pros::Task task7(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBackLoaded(3, -90, 40);

}


//****************RED AUTONOMOUS*****************************
void red_front_8_cubes()
{
  deploy();
  moveRollers(-200);
  move(45, 0, 80);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(36, 0, 90);
  wait(150);

  //Turn to the corner
  turnRightLoaded(135);
  moveLoaded(41, 135, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(15);
  wait(15);
  scoreAuton2();
  pros::Task task1(tilterBack);
  moveRollers(90);
  wait(200);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

void red_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(46, 0, 75);
  moveRollers(-200);
  sweepRightBack(135);
  moveLoaded(30, 135, 127);
  timedDrive(250, 40);
  moveRollers(30);
  wait(25);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(24, 100);
  moveTilter(0);
  task1.remove();
}

void red_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 80);
  sweepLeft(-20);
  wait(200);
  sweepRightBack(0);
  moveRollers(-200);
  moveBack(1, 0, 30);
  sweepRightBack(134);
  moveLoaded(25, 134, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(30);
  wait(25);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(24, 100);
  moveTilter(0);
  task1.remove();
}

void red_back()
{
  moveRollers(-200);
  wait(200);
  moveRollers(0);
  pros::Task task1(halfwayPos);
  moveLift(1500, -127);
  wait(350);
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
  moveHalfLoaded(36, 0, 90);
  wait(100);

  //Turn to the corner
  turnLeftLoaded(-135);
  moveLoaded(41, -135, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(20);
  wait(15);
  scoreAuton2();
  pros::Task task1(tilterBack);
  moveRollers(90);
  wait(200);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

void blue_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(46, 0, 75);
  moveRollers(-200);
  sweepLeftBack(-132);
  moveLoaded(30, -132, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(30);
  wait(25);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(24, 100);
  moveTilter(0);
  task1.remove();
}

void blue_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(44, 0, 75);
  sweepRight(20);
  wait(200);
  sweepLeftBack(0);
  moveRollers(-200);
  moveBack(1, 0, 30);
  sweepLeftBack(-133);
  moveLoaded(25, -133, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(30);
  wait(25);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(24, 100);
  moveTilter(0);
  task1.remove();
}

void blue_back()
{
  moveRollers(-200);
  wait(200);
  moveRollers(0);
  pros::Task task1(halfwayPos);
  moveLift(1600, -127);
  wait(200);
  sweepLeft(-62);
  moveRollers(50);
  wait(600);
  sweepRightBack(0);
  pros::Task task2(tilterBack);
  moveLift(1500, 100);
  moveRollers(-200);
  //move(1, 0, 40);
  sweepRight(90);
  move(12, 90, 100);
  sweepRight(135);
  timedDrive(300, 40);
  moveRollers(200);

  wait(2000);

  moveBack(20, 135, 127);
  task1.remove();
  task2.remove();
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  //Red side
  //red_front_8_cubes();
  //red_front_5_cubes();
  //red_front_6_cubes();
  //red_back();

  //Blue Side
  //blue_front_8_cubes();
  //blue_front_5_cubes();
  //blue_front_6_cubes();
  //blue_back();
  //programming_skills();
  /*
  turnRightProgramming(90);
  wait(500);
  turnRightProgramming(180);
  wait(500);
  turnRightProgramming(270);
  wait(500);
  turnRightProgramming(360);
  */

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

}

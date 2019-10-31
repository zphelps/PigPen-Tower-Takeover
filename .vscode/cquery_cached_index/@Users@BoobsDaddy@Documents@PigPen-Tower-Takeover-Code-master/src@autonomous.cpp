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
    wait(250);
    moveRollers(-200);
    move(44, 0, 75);

    //S-Turn to other Cubes
    STurn_RedFront();
    moveRollers(-200);
    moveHalfLoaded(34, 0, 75);
    wait(350);

    //Turn to the corner
    turnRightLoaded(133);
    moveLoaded(42, 133, 127);
    moveRollers(40);
    moveRollers(0);
    moveRollers(125);
    wait(20);
    moveRollers(0);
    brakeRollers();
    scoreAuton();
    pros::Task task1(tilterBack);
    timedDrive(250, 40);
    wait(250);
    moveBack(25, 132, 127);

    turnLeft(0); //******************************Consider Changing direction
    wait(250);
    moveRollers(-200);
    move(21, 0, 127);
    moveRollers(-200);
    timedDrive(300, 40);
    moveRollers(-200);
    wait(200);
    moveBackLoaded(10, 0, 40);
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
    moveBackLoaded(10, -90, 40);
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

    moveBackLoaded(3, -90, 40);
    pros::Task task5(tilterBack);
    moveLift(1500, 100);
    turnRight(-3);

    moveRollers(-200);
    move(101, -2, 127);

    turnRightHalfLoaded(90);
    move(4, 90, 50);

    sweepRight(180);
    move(24, 180, 100);
    wait(250);

    moveRollers(0);
    brakeRollers();
    moveBack(18, 180, 80);
    moveRollers(0);
    brakeRollers();
    turnLeftLoaded(48);
    move(13, 48, 50);
    //timedDrive(750, 40);
    //wait(650);
    coastRollers();
    moveRollers(125);
    wait(45);
    moveRollers(0);
    brakeRollers();
    scoreAuton();
    pros::Task task6(tilterBack);
    timedDrive(400, 40);
    timedDrive(2000, -75);
    //moveBack(25, 48, 75);
    task1.remove();
    task2.remove();
    task3.remove();
    task4.remove();
    task5.remove();
    //task6.remove();
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
  move(44, 0, 85);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(36, 0, 100);
  wait(50);

  //Turn to the corner
  turnRightLoaded(135);
  moveLoaded(41, 135, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(125);
  wait(55);
  moveRollers(0);
  brakeRollers();
  scoreAuton2();
  //pros::Task task1(tilterBack);
  timedDrive(250, 40);
  wait(200);
  moveBackNoPos(25, 127);
  //task1.remove();
  moveTilter(0);
}

void red_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(45, 0, 75);
  moveRollers(-200);
  sweepRightBack(135);
  moveLoaded(31, 135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(100);
  moveRollers(0);
  brakeRollers();
  timedDrive(300, 40);
  scoreAuton2();
  timedDrive(300, 40);
  wait(300);
  moveBackNoPos(48, 40);
  moveTilter(0);
}

void red_front_6_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(43, 0, 75);
  sweepLeft(-20);
  wait(200);
  sweepRightBack(0);
  moveRollers(-200);
  moveBack(1, 0, 30);
  sweepRightBack(135);
  moveLoaded(25, 135, 127);
  timedDrive(300, 40);
  moveRollers(0);
  moveRollers(125);
  wait(75);
  moveRollers(0);
  brakeRollers();
  scoreAuton();
  pros::Task task1(tilterBack);
  timedDrive(300, 40);
  wait(250);
  moveRollers(200);
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
  move(44, 0, 85);

  //S-Turn to other Cubes
  STurn_BlueFront();
  moveRollers(-200);
  moveHalfLoaded(35, 0, 100);
  wait(100);

  //Turn to the corner
  turnLeftLoaded(-133);
  move(41, -133, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(125);
  wait(60);
  moveRollers(0);
  brakeRollers();
  scoreAuton2();
  //wait(100);
  //pros::Task task1(tilterBack);
  timedDrive(250, 40);
  wait(250);
  moveBackNoPos(25, 127);
  //task1.remove();
  moveTilter(0);
}

void blue_front_5_cubes()
{
  //Pick up first 5 cubes
  deploy();
  moveRollers(-200);
  move(45, 0, 75);
  moveRollers(-200);
  sweepLeftBack(-135);
  moveLoaded(31, -135, 127);
  moveRollers(0);
  moveRollers(125);
  wait(100);
  moveRollers(0);
  brakeRollers();
  timedDrive(300, 40);
  scoreAuton2();
  timedDrive(300, 40);
  wait(300);
  moveBackNoPos(48, 40);
  moveTilter(0);
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
  sweepLeftBack(-135);
  moveLoaded(25, -135, 127);
  timedDrive(300, 40);
  moveRollers(0);
  moveRollers(125);
  wait(75);
  moveRollers(0);
  brakeRollers();
  scoreAuton2();
  pros::Task task1(tilterBack);
  timedDrive(300, 40);
  wait(250);
  moveRollers(200);
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

  programming_skills();


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

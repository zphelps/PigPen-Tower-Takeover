#include "main.h"

//*****************PROGRAMMING SKILLS************************
void programming_skills_65()
{
    resetTheta(0);
    deploy();
    wait(650);
    pros::Task titler_Back(tilterBack);
    moveRollers(-200);
    move(42, 0, 60);
    wait(150);
    moveBack(1, 0, 100);

    sweepRightBackProgramming(90, 2);
    cube_latch();
    moveLift(150, -100);
    move(8, 90, 100);
    moveRollers(100);
    wait(350);
    moveBack(2, 90, 100); //2
    /*
    move(10, 90, 100);
    moveRollers(70);
    wait(350);
    timedDrive(1000, 50);
    moveBack(10, 90, 100);
    */
    moveRollers(-200);
    pros::Task lift_down(liftDown);
    turnLeftLoaded(8);
    moveFast(25, 5, 127);
    moveFast(10, -18, 127);
    move(45, 0, 100);
    wait(300);
    cube_latch_big_stack();
    moveLift(200, -100);
    moveBackLoaded(10, 0, 100);
    turnRightLoaded(90);
    moveLoaded(1, 90, 100);
    moveRollers(75);
    wait(400);
    moveRollers(-200);
    moveBackLoaded(1, 90, 127);
    pros::Task lift_down1(liftDown);
    sweepLeftBack(42);

    moveLoaded(22, 42, 127);
    timedDrive(250, 40);
    wait(100);
    moveRollers(0);
    moveRollers(15);
    wait(30);
    scoreAuton2();
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBack(10, 45, 100);
    wait(300);
    turnRightProgramming(90);
    //moveBackFast(10, 90, 100); //8
    moveBackFast(14, 90, 127); //10
    sweepRightBackProgramming(180, 2);
    timedDrive(1250, -50);
    resetTheta(180);
    wait(100);
    moveRollers(-200);
    moveFast(36, 180, 75); //36
    moveBack(6, 270, 100);
    sweepRightBackProgramming(270, 2);

    moveFast(12, 270, 100);
    timedDrive(350, 40);
    wait(200);
    moveBackLoaded(12, 270, 40);
    cube_latch();
    moveLift(500, -127);
    move(3, 270, 40);
    timedDrive(250, 30);
    moveRollers(200);
    wait(300);

    moveBackLoaded(1, 270, 10);
    moveRollers(-200);
    pros::Task lift_down2(liftDown);

    turnLeftProgramming(178); //180
    moveRollers(0);
    moveRollers(-200);
    moveFast(86, 178, 127); //180

    moveBack(3, 180, 100);
    moveBackLoaded(6, 180, 100);
    turnRightProgramming(220);
    moveRollers(0);
    moveRollers(-200);
    cube_latch();
    moveLift(500, -100);
    moveFast(8, 225, 100);
    moveRollers(75);
    wait(250);
    moveBack(18, 225, 100);
    moveRollers(-200);
    pros::Task lift_down3(liftDown);
    turnLeftLoadedProgramming(133);
    moveLoaded(40, 133, 127);
    timedDrive(250, 40);
    moveRollers(0);
    moveRollers(30);
    wait(50);
    scoreAuton7cube();
    pros::Task task5(tilterBack);
    moveRollers(90);
    moveBack(15, 135, 100);

}

void programming_skills_70()
{
  wait(200);
  resetTheta(0);
  deploy();
  wait(500);
  pros::Task titler_Back(tilterBack);
  moveRollers(-200);
  move(40, 0, 65); //60
  wait(150);
  moveBack(1, 0, 100); //2

  sweepRightBackProgramming(90, 2);
  cube_latch();
  moveLift(100, -100); //150
  move(8, 90, 100);
  moveRollers(150);
  wait(200); //350
  moveBack(2, 90, 100); //2

  moveRollers(-200);
  pros::Task lift_down(liftDown);
  Lift(5);
  turnLeftLoaded(8); //8

  moveFast(22, 8, 127);
  Lift(0);
  moveFast(10, -25, 127); //10, -20

  moveRollers(0);
  brakeRollers();
  wait(50);
  moveRollers(-200);
  move(35, 0, 127); //35, 50
  sweepRight(45);

  moveLoaded(4, 45, 127); //2
  timedDrive(200, 35);
  pros::Task p(position_cube);
  scoreAuton9Cube();
  pros::Task task1(tilterBack);
  p.remove();
  moveRollers(90);
  moveBack(6, 45, 100); //8

  turnRightProgramming(90);
  moveBack(18, 90, 127); //16
  sweepRightBackProgramming(180, 2);
  timedDrive(750, -50); //800
  resetTheta(180);
  wait(100);
  moveRollers(-200);

  moveFast(34, 180, 90); //75

  turnLeft(150);
  moveFast(13, 150, 90); //155
  moveBack(4, 155, 100);
  cube_latch();
  moveLift(125, -100); //175
  move(4, 155, 100);
  moveRollers(75);
  wait(200);
  moveBack(6, 155, 100); //180
  moveRollers(-200);
  pros::Task lift_down_1(liftDown);
  turnRightProgramming(180);

  moveRollers(-50);
  moveBack(9, 180, 127); //8
  sweepRightBackProgramming(270, 2); //270,2
  moveRollers(-200);
  moveFast(10, 270, 100); //10
  timedDrive(350, 40);
  wait(200);
  moveBackLoaded(12, 270, 40);
  cube_latch();
  moveLift(350, -127); //500
  move(4, 270, 40);
  timedDrive(250, 30);
  moveRollers(90);
  wait(300);

  moveBackLoaded(1, 270, 10);
  moveRollers(-200);
  pros::Task lift_down2(liftDown);

  turnLeftProgramming(180); //180
  moveRollers(0);
  moveRollers(-200);

  moveFast(95, 180, 127); //86 in total
  timedDrive(300, 35);
  moveRollers(-50);

  moveBackFast(22, 180, 100); //12
  turnRightProgramming(225);
  moveRollers(0);
  moveRollers(-200);
  cube_latch();
  moveLift(350, -100);
  moveFast(8, 226, 100);
  moveRollers(100);
  wait(250);
  moveBack(12, 220, 100);
  moveRollers(-200);
  pros::Task lift_down3(liftDown);
  turnLeftLoadedProgramming(135);
  moveLoaded(40, 135, 127);
  timedDrive(200, 35);
  pros::Task p2(position_cube);
  scoreAuton7cube();
  pros::Task task5(tilterBack);
  moveRollers(90);
  moveBack(15, 135, 100);

}

//****************RED AUTONOMOUS*****************************
void red_front_9_cubes()
{
  wait(200);
  resetTheta(0);
  deployOP();
  moveRollers(-200);
  Lift(5);
  moveFast(40, 0, 65);
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront();
  moveRollers(-200);
  move(18, 0, 75);
  wait(400);
  moveRollers(0);
  moveLift(400, -100);
  moveRollers(-200);
  move(5, 0, 100);
  //moveRollers(0);
  pros::Task liftDown(liftDownAuton);
  moveBack(3, 0, 127);
  moveRollers(-200);
  move(8, 0, 100);

  //Turn to the corner
  turnRightLoaded(135);
  pros::Task h(halfwayPos);
  moveLoaded(32, 135, 127);
  moveRollers(-200);
  timedDrive(300, 30);
  scoreAuton9Cube();
  moveRollers(200);
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

void red_front_7_cubes()
{
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(42, 0, 50); //75
  wait(200);


  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront();
  moveRollers(-200);
  move(20, 0, 90); //20
  moveBack(1, 0, 50); //Prevent robot from hitting cube
  wait(250);

  //Turn to the corner
  turnRightProgramming(90);
  moveFast(6, 90, 127);
  moveMAX(30, 138, 127);
  timedDrive(350, 35);
  wait(300);
  moveRollers(0);
  scoreAuton7cube();
  moveRollers(200);
  wait(200);
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

void red_front_8_cubes()
{
  wait(200);
  resetTheta(0);
  deployOP();
  moveRollers(-200);
  Lift(5);
  moveFast(42, 0, 55);
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront();
  moveRollers(-200);
  move(28, 0, 85); //20
  wait(250);

  //Turn to the corner
  turnRightProgramming(90);
  moveFast(2, 90, 127);
  moveLoaded(34, 135, 127);
  timedDrive(300, 30);
  //pros::Task p(position_cube);
  scoreAuton7cube();
  moveRollers(200);
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

void red_back()
{
  deploy();
  timedDrive(300, -40);
  wait(300);
  moveRollers(-200);
  move(20, 0, 100);
  turnLeftProgramming(-90);
  move(9, -90, 100);
  sweepLeft(-125);
  timedDrive(200, 30);
  moveRollers(200);
  wait(1000);

  moveBack(12, -135, 127);
  sweepRightBackProgramming(-90, -3);
  moveBack(8, -90, 127);
  turnRightProgramming(0);
  moveRollers(-200);
  moveFast(20, 0, 127);
  wait(250);
  moveBack(30, 0, 127);
}

//***************BLUE AUTONOMOUS*****************************
void blue_front_9_cubes()
{
  resetTheta(0);
  deploy();
  moveRollers(-200);
  timedDrive(350, -30);
  //wait(500); //350
  Lift(5);
  move(26, 0, 50);//27
  wait(400);
  moveRollers(0);
  moveLift(350, -100);
  moveRollers(-200);
  move(6, 0, 100);
  wait(200);
  pros::Task liftDown(liftDownAuton);
  move(4, 0, 100);

  //S-Turn to other Cubes
  Lift(0);
  STurn_BlueFront3();
  moveRollers(-200);
  Lift(5);
  move(37, 0, 50);
  wait(250);
  moveBack(3, 0, 100); //6
  pros::Task cubePos(position_cube);
  pros::Task halfway(halfwayPos);
  brakeTilter();
  moveRollers(0);

  //Turn to the corner
  Lift(0);
  sweepLeftBackProgramming(-135, 2);
  moveLoaded(22, -135, 127);
  timedDrive(300, 30);
  moveRollers(30);
  wait(50);
  moveRollers(0);
  scoreAuton9Cube();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

void blue_front_7_cubes()
{
  wait(200);
  resetTheta(0);
  deployOP();
  moveRollers(-200);
  Lift(5);
  moveFast(40, 0, 75);
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_BlueFront();
  moveRollers(-200);
  move(20, 0, 75);
  wait(250);

  //Turn to the corner
  turnLeftProgramming(-90);
  moveFast(2, -90, 127);
  moveLoaded(30, -135, 127);
  timedDrive(300, 30);
  //pros::Task p(position_cube);
  scoreAuton7cube();
  moveRollers(200);
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

void blue_front_8_cubes()
{

  resetTheta(0);
  deploy();
  moveRollers(-200);
  wait(500); //350
  move(44, 0, 60);

  //S-Turn to other Cubes
  STurn_BlueFront();
  moveRollers(-200);
  moveFast(36, 0, 65);
  wait(100);

  //Turn to the corner
  turnLeftLoadedAuton(-135);
  moveRollers(30);
  wait(75);
  moveRollers(0);
  //pros::Task pos_cube(postion_cube);
  pros::Task half(halfwayPos);
  brakeTilter();
  moveLoaded(40, -135, 127);
  timedDrive(250, 30);
  moveRollers(0);
  moveRollers(20);
  wait(30);
  //scoreAuton2();
  scoreAuton9Cube();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

void blue_back()
{
  deploy();
  timedDrive(300, -40);
  wait(300);
  moveRollers(-200);
  move(20, 0, 100);
  turnRightProgramming(90);
  move(9, 90, 100);
  sweepRight(125);
  timedDrive(200, 30);
  moveRollers(200);
  wait(1000);

  moveBack(12, 125, 127);
  sweepLeftBackProgramming(90, -3);
  moveBack(8, 90, 127);
  turnLeftProgramming(0);
  moveRollers(-200);
  moveFast(20, 0, 127);
  wait(250);
  moveBack(30, 0, 127);
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{
  //1-10-20
  //Red side
  //deploy();
  //red_front_9_cubes();
  //red_front_7_cubes();
  //red_front_8_cubes();
  //red_front_5_cubes();
  //red_front_6_cubes();
  //red_back();

  //Blue Side
  //blue_front_9_cubes();
  //blue_front_7_cubes();
  //blue_front_8_cubes();
  //blue_front_5_cubes();
  //blue_front_6_cubes();
  //blue_back();
  programming_skills_70();

  //sweepLeft(-90);
  /*
  wait(500);
  turnRightProgramming(180);
  wait(500);
  turnRightProgramming(270);
  wait(500);
  turnRightProgramming(360);
  */
/*
  switch(autonIndex){
    case 0:
      red_front_8_cubes();
      break;
    case 1:
      red_front_9_cubes();
      break;
    case 2:
      red_front_7_cubes();
      break;
    case 3:
      //Red Back
      red_back();
      break;
    case 4:
      blue_front_8_cubes();
      break;
    case 5:
      blue_front_9_cubes();
      break;
    case 6:
      blue_front_7_cubes();
      break;
    case 7:
      //Blue Back
      blue_back();
      break;
    case 8:
      programming_skills3();
      break;
  }
*/

}

#include "main.h"

//*****************PROGRAMMING SKILLS************************
/*
void programming_skills() {
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
    resetTheta(135);
    moveBackLoaded(26, 135, 80);

    turnLeftProgramming(2); //******************************Consider Changing direction
    wait(250);
    moveRollers(-200);
    pros::Task cube_collect1(collectCube);
    move(21, 0, 127);
    timedDrive(300, 40);
    wait(200);
    moveBackLoaded(10, 0, 40);
    pros::Task task2(halfwayPos);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(400, 100);
    wait(200);
    moveRollers(75);
    moveBack(31, 0, 127);
    pros::Task task3(tilterBack);
    moveLift(1000, 100);
    turnLeftProgramming(-90);

    pros::Task cube_collect2(collectCube);
    move(12, -90, 100);
    timedDrive(250, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    pros::Task task4(halfwayPos);
    moveLift(1400, -127);
    move(6, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBackLoaded(1, -90, 10);
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
    turnLeftLoaded(45);
    move(5, 45, 50);
    timedDrive(750, 50);
    wait(400);
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
*/

void programming_skills()
{
    resetTheta(0);
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
    turnRightLoadedProgramming(135);
    wait(250);
    moveLoaded(41, 135, 127);
    timedDrive(250, 40);
    wait(100);
    moveRollers(0);
    moveRollers(20);
    wait(15);
    scoreAuton2();
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBack(8, 135, 100);
    sweepLeftBackProgramming1(0);

    pros::Task cube_collect1(collectCube);
    moveFastProgramming(32, 0, 127);
    timedDrive(350, 40);
    wait(200);
    moveBackLoaded(10, 0, 40);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(400, 100);
    wait(200);
    moveRollers(75);
    moveBack(44, 0, 127);
    timedDrive(250, -30);
    moveLift(1200, 100);
    wait(200);
    resetTheta(0);
    //move(1, 0, 50);
    sweepLeft(-90);

    pros::Task cube_collect2(collectCube);
    moveFastProgramming(5, -90, 100);
    timedDrive(300, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    moveLift(1400, -127);
    move(5, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBackLoaded(3, -90, 10);
    moveLift(1500, 100);
    turnRightProgramming(0);

    moveRollers(-200);
    move(90, 0, 127); //101
    timedDrive(650, 40);

    turnRightProgramming(90);
    moveRollers(200);
    wait(50);
    moveRollers(0);
    brakeRollers();
    moveRollers(-200);
    move(5, 90, 50);

    sweepRight(180);
    move(16, 180, 100);
    timedDrive(450,40);
    wait(250);

    brakeRollers();
    moveBack(18, 180, 80);
    moveRollers(0);
    brakeRollers();
    turnLeftLoadedProgramming(45);
    move(5, 45, 50);
    timedDrive(750, 50);
    wait(400);
    moveRollers(0);
    moveRollers(5);
    //wait(15);
    scoreAuton2();
    wait(200);
    pros::Task task6(tilterBack);
    moveRollers(90);
    moveBackNoPos(7, 127);
    moveTilter(0);

}

void programming_skills2()
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
    turnRightLoadedProgramming(135);
    wait(250);
    moveLoaded(41, 135, 127);
    timedDrive(250, 40);
    wait(100);
    moveRollers(0);
    moveRollers(20);
    wait(15);
    scoreAuton2();
    wait(250);
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBack(8, 135, 100);
    sweepLeftBackProgramming1(0);

    pros::Task cube_collect1(collectCube);
    moveFastProgramming(32, 0, 127);
    timedDrive(350, 40);
    wait(200);
    moveBackLoaded(10, 0, 40);
    pros::Task task2(halfwayPos);
    moveLift(1250, -127);
    move(4, 0, 127);
    timedDrive(250, 30);
    moveLift(400, 100);
    wait(200);
    moveRollers(75);
    //moveBack(31, 0, 127);
    moveBack(42, 0, 127);
    timedDrive(250, -30);
    pros::Task task3(tilterBack);
    moveLift(1000, 100);
    wait(200);
    resetTheta(0);
    move(1, 0, 50);
    sweepLeft(-90);
    //turnLeftProgramming(-90);

    pros::Task cube_collect2(collectCube);
    //move(12, -90, 100);
    moveFastProgramming(5, -90, 100);
    timedDrive(300, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    pros::Task task4(halfwayPos);
    moveLift(1400, -127);
    move(5, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBack(38, -90, 127);
    timedDrive(300, -30);
    pros::Task task5(tilterBack);
    moveLift(1500, 100);
    wait(200);
    resetTheta(-90);
    move(1,-90,30);
    sweepRight(10);

    moveRollers(-200);
    move(25, 10, 127);
    move(23,-10,127);
    move(20, 0, 127); //101

    sweepRight(45);
    move(2, 90, 50);
    timedDrive(750, 40);
    wait(400);
    moveRollers(0);
    moveRollers(15);
    wait(15);
    scoreAuton();
    wait(200);
    pros::Task task6(tilterBack);
    moveRollers(90);
    moveBackNoPos(2, 127);
    moveTilter(0);
    task1.remove();
    task2.remove();
    task3.remove();
    task4.remove();
    task5.remove();
    sweepLeftBackProgramming1(-90);

    pros::Task cube_collect3(collectCube);
    move(18, -70, 100);
    move(15, -90, 100);
    timedDrive(250, 40);
    wait(200);
    moveBackLoaded(10, -90, 40);
    pros::Task task7(halfwayPos);
    moveLift(1400, -127);
    move(7, -90, 40);
    timedDrive(250, 30);
    moveRollers(70);
    wait(300);

    moveBackLoaded(3, -90, 40);

}

void programming_skills3()
{
    resetTheta(0);
    deploy();
    timedDrive(300, -40);
    wait(450);
    pros::Task titler_Back(tilterBack);
    moveRollers(-200);
    move(42, 0, 70);
    wait(150);
    moveBack(1, 0, 100);

    sweepRightBackProgramming(90, 2);
    cube_latch();
    moveLift(150, -100);
    move(8, 90, 100);
    moveRollers(100);
    wait(350);
    moveBack(2, 90, 100);
    /*
    move(10, 90, 100);
    moveRollers(70);
    wait(350);
    timedDrive(1000, 50);
    moveBack(10, 90, 100);
    */
    moveRollers(-200);
    pros::Task lift_down(liftDown);
    turnLeftLoaded(5);
    moveFastProgramming(25, 5, 127);
    moveFastProgramming(10, -18, 127);
    move(45, 0, 100);
    wait(300);
    cube_latch_big_stack();
    moveLift(200, -100);
    moveBackLoaded(9, 0, 100);//10
    turnRightLoaded(90);
    moveLoaded(1, 90, 100);
    moveRollers(75);
    wait(400);
    moveRollers(-200);
    pros::Task lift_down1(liftDown);
    sweepLeftBack(42);

    moveLoaded(23, 45, 127);
    timedDrive(250, 40);
    wait(100);
    moveRollers(0);
    moveRollers(20);
    wait(20); //30
    scoreAuton2();
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBack(10, 45, 100);
    wait(300);
    turnRightProgramming(90);
    moveBackFast(8, 90, 100);
    sweepRightBack(180);
    timedDrive(750, -50);
    resetTheta(180);
    wait(100);
    moveRollers(-200);
    moveFastProgramming(36, 180, 75);
    moveBack(6, 270, 100);
    sweepRightBackProgramming(268, 2); //270

    moveFastProgramming(12, 268, 100); //270
    timedDrive(350, 40);
    wait(200);
    moveBackLoaded(12, 268, 40); //270
    cube_latch();
    moveLift(500, -127);
    move(3, 266, 40); //270
    timedDrive(250, 30);
    moveRollers(200);
    wait(300);

    moveBackLoaded(1, 268, 10); //270
    moveRollers(-200);
    pros::Task lift_down2(liftDown);

    turnLeftProgramming(176); //180
    moveRollers(0);
    moveRollers(-200);
    moveFastProgramming(86, 176, 127); //180

    moveBackLoaded(6, 176, 100); //180
    turnRightProgramming(225);
    moveRollers(0);
    moveRollers(-200);
    cube_latch();
    moveLift(500, -100);
    moveFastProgramming(8, 225, 100);
    moveRollers(100);
    wait(250);
    moveBack(17, 225, 100);
    moveRollers(-200);
    pros::Task lift_down3(liftDown);
    turnLeftLoadedProgramming(133);
    moveLoaded(38, 133, 127);
    timedDrive(250, 40);
    moveRollers(0);
    moveRollers(35);
    wait(50);
    scoreAuton2();
    pros::Task task5(tilterBack);
    moveRollers(90);
    moveBack(15, 135, 100);

}

void programming_skills4()
{
    resetTheta(0);
    deploy();
    timedDrive(300, -40);
    wait(300);
    moveRollers(-200);
    move(42, 0, 70);
    wait(150);
    moveBack(1, 0, 100);

    sweepRightBackProgramming(90, 2);
    cube_latch();
    moveLift(150, -100);
    move(10, 90, 100);
    moveRollers(70);
    wait(350);
    timedDrive(1000, 50);
    moveBack(10, 90, 100);
    moveRollers(-200);
    pros::Task lift_down(liftDown);
    turnLeftLoaded(5);
    move(25, 5, 100);
    moveFastProgramming(10, -15, 127);
    move(42, 0, 127);
    wait(600);
    cube_latch_big_stack();
    moveLift(200, -100);
    moveBackLoaded(8, 0, 100);
    turnRightLoaded(90);
    moveLoaded(1, 90, 100);
    moveRollers(45);
    wait(400);
    moveRollers(-200);
    pros::Task lift_down1(liftDown);
    sweepLeftBack(43);

    moveLoaded(24, 45, 127);
    timedDrive(250, 40);
    wait(100);
    moveRollers(0);
    moveRollers(20);
    wait(30);
    scoreAuton2();
    pros::Task task1(tilterBack);
    moveRollers(90);
    moveBack(10, 45, 100);
    wait(300);
    turnRightProgramming(90);
    moveBack(9, 90, 100);
    sweepRightBack(180);
    timedDrive(750, -50);
    resetTheta(180);
    wait(250);
    moveRollers(-200);
    moveFastProgramming(38, 180, 90);
    sweepLeft(135);

    moveBackLoaded(4, 135, 40);
    cube_latch();
    moveLift(150, -127);
    move(3, 270, 40);
    moveRollers(100);
    wait(300);

    moveBackLoaded(1, 270, 10);
    moveRollers(-200);
    pros::Task lift_down2(liftDown);

    turnRightProgramming(180);
    moveFastProgramming(50, 180, 127); //101

    moveBackLoaded(6, 180, 100);
    turnRightProgramming(225);
    cube_latch();
    moveLift(500, -100);
    move(8, 225, 100);
    moveRollers(100);
    wait(250);
    moveBack(14, 225, 100);
    moveRollers(-200);
    pros::Task lift_down3(liftDown);
    turnLeftLoaded(135);
    moveLoaded(41, 135, 127);
    timedDrive(250, 40);
    moveRollers(0);
    moveRollers(30);
    wait(50);
    scoreAuton2();
    pros::Task task5(tilterBack);
    moveRollers(90);
    moveBack(15, 135, 100);

}

//****************RED AUTONOMOUS*****************************
void red_front_9_cubes()
{
  deploy();
  moveRollers(0);
  moveRollers(-200);
  wait(250);
  move(25, 0, 90);
  wait(250);
  moveRollers(0);
  moveLift(300, -100);
  moveRollers(-200);
  move(8, 0, 100);
  moveLift(400, 100);

  //S-Turn to other Cubes
  STurn_RedFront2();
  moveRollers(-200);
  moveHalfLoaded(36, 0, 75);

  //Turn to the corner
  sweepRightBackLoaded(130);
  moveLoaded(25, 130, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(15);
  wait(15);
  scoreAuton2();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

void red_front_8_cubes()
{
  resetTheta(0);
  deploy();
  moveRollers(-200);
  wait(250);
  move(45, 0, 80);

  //S-Turn to other Cubes
  STurn_RedFront();
  moveRollers(-200);
  moveHalfLoaded(38, 0, 85);
  wait(150);

  //Turn to the corner
  turnRightLoadedAuton(135);
  moveLoaded(39, 135, 127); //41
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(22);
  wait(30);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
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
  moveFastProgramming(20, 0, 127);
  wait(250);
  moveBack(30, 0, 127);
}

//***************BLUE AUTONOMOUS*****************************
void blue_front_8_cubes()
{

  resetTheta(0);
  deploy();
  moveRollers(-200);
  wait(250);
  move(44, 0, 80);

  //S-Turn to other Cubes
  STurn_BlueFront();
  moveRollers(-200);
  moveHalfLoaded(36, 0, 85);
  wait(100);

  //Turn to the corner
  turnLeftLoadedAuton(-140);
  moveLoaded(41, -140, 127);
  timedDrive(250, 40);
  moveRollers(0);
  moveRollers(25);
  wait(30);
  scoreAuton();
  pros::Task task1(tilterBack);
  moveRollers(90);
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
  moveFastProgramming(20, 0, 127);
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
  //red_front_8_cubes();
  //red_front_5_cubes();
  //red_front_6_cubes();
  //red_back();

  //Blue Side
  //blue_front_8_cubes();
  //blue_front_5_cubes();
  //blue_front_6_cubes();
  //blue_back();
  //programming_skills3();

  //sweepLeft(-90);
  /*
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
      red_back();
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
      blue_back();
      break;
    case 8:
      programming_skills3();
      break;
  }

}

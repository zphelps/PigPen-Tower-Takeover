#include "main.h"

//*****************PROGRAMMING SKILLS************************

// programming_skills_65() is not currently used. It is our "safe" programming skills
// in the event that our 75 point programming skills does not function correctly.
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
    scoreAuton9Cube();
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

// State programming skills
void programming_skills_75()
{
  wait(200); //Wait to prevent bug that occasionally skips deploy();
  resetTheta(0); //Reset theta to 0 to account for accidental bumping of the robot before match.
  deploy();
  wait(500); //Allow robot to settle before proceeding
  pros::Task titler_Back(tilterBack);
  moveRollers(-200);
  moveFast(40, 0, 45);
  wait(150);
  moveBack(2, 0, 100); //2

  sweepRightBackProgramming(90, 2); //turn towards alliance tower
  cube_latch();
  moveLift(150, -100); //raise to alliance tower height
  moveFast(8, 90, 50);//Fast
  moveRollers(150); //drop cube into tower //200
  wait(300);
  moveBack(2, 90, 100); //2

  moveRollers(-200);
  pros::Task lift_down(liftDown);
  Lift(5);
  turnLeftProgramming(8); //8 Loaded

  moveFast(25, 8, 127); //Move at 8 degree heading to avoid tower. //25
  moveRollers(0);
  Lift(0);
  wait(10);
  moveRollers(-200);
  moveFast(8, -30, 127); //Change heading to align with cubes //8

  //moveRollers(0);
  brakeRollers();
  wait(50);
  moveRollers(-200);
  moveFast(41, 0, 90); //Back to 0 degree heading //41, -3
  sweepRight(45); //Turn towards goal zone
  moveRollers(0);
  brakeRollers();

  moveLoaded(6, 45, 127); //8
  timedDrive(150, 35); //Timed Drive to prevent move() from getting stuck in loop
  moveRollers(50); //65
  wait(500); //550
  moveRollers(0);
  scoreAuton9Cube();
  pros::Task task1(tilterBack);
  moveRollers(200);
  wait(200);
  moveBackFast(5, 45, 50); //6
  wait(100);

  turnRightProgramming(89); //90
  moveBackFast(15, 90, 127); //16, 60
  wait(100);
  sweepRightBackProgramming(178, 2); //Align towards field perimeter
  timedDrive(800, -50);
  resetTheta(180); //resets theta mid-run to prevent drift
  wait(250); //Make sure robot settles
  moveRollers(-200);

  moveFast(34, 180, 127); //75

  turnLeft(145); //150
  moveRollers(0);
  wait(50);
  moveRollers(-200); //Failsafe if cube gets stuck
  moveFast(12, 145, 50); //127
  wait(300);
  moveBackFast(6, 145, 127);
  wait(250);
  cube_latch();
  moveLift(175, -100); //175
  moveFast(6, 145, 50);
  moveRollers(130);
  wait(350);
  moveBackFast(4, 150, 100); //180
  moveRollers(-200);
  pros::Task lift_down_1(liftDown);
  turnRightProgramming(180);

  moveBackFast(9, 180, 100); //8
  wait(100);
  sweepRightBackProgramming(270, 2); //turn towards tall tower
  moveRollers(-200);
  moveFast(8, 270, 100); //10
  timedDrive(350, 35); //Prevent getting stuck in loop.
  wait(200);           //Bumps into tower for point of reference
  moveBackFast(8, 270, 100);
  wait(200);
  cube_latch();
  moveLift(500, -127);
  moveFast(2, 270, 60);
  timedDrive(250, 30);
  moveRollers(115);
  wait(350);

  moveBackLoaded(3, 270, 10); //1
  moveRollers(-200);
  pros::Task lift_down2(liftDown);

  turnLeftProgramming(178); //turn to 180 degree heading
  moveRollers(-200);
  Lift(10);

  moveMAX(90, 178, 35); //Cross field and get remaining cubes in L-stacks
  timedDrive(450, 35);
  Lift(0);
  wait(300);

  moveBackFast(25, 178, 127); //15
  wait(200);
  moveRollers(2);
  wait(50);
  moveRollers(-200);
  turnRightLoaded(220);
  moveRollers(0);
  moveRollers(-200);
  cube_latch();
  moveLift(450, -100);
  moveFast(8, 220, 50); //8
  moveRollers(150);
  wait(350);
  moveBackFast(16, 220, 100); //14
  moveRollers(-200);
  pros::Task lift_down3(liftDown);
  Lift(10);
  turnLeftProgramming(135); //Turn towards goal zone
  Lift(0);
  moveMAX(40, 135, 127);
  timedDrive(200, 35); //Timeout prevention
  moveRollers(60);
  wait(400);
  moveRollers(0);
  brakeRollers();
  scoreAuton7cube();
  pros::Task task5(tilterBack);
  moveRollers(90);
  moveBack(15, 135, 100);
}

//****************RED AUTONOMOUS*****************************

//Only used for matches with weak partner and strong opponent
void red_front_9_cubes()
{
  wait(200); //Prevent bug that skips deployOP();
  resetTheta(0);
  deployOP();
  moveRollers(-200);
  Lift(5);
  moveFast(40, 0, 65);
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront(); //Move to second row of cubes
  moveRollers(-200);
  move(18, 0, 75);
  wait(400);
  moveRollers(0);
  moveLift(400, -100);
  moveRollers(-200);
  move(5, 0, 100);
  pros::Task liftDown(liftDownAuton);
  moveBack(3, 0, 127);
  moveRollers(-200);
  move(8, 0, 100);

  //Turn to the corner
  turnRightLoaded(135);
  pros::Task h(halfwayPos); //move tilter to shorten tilting time in goal zone
  moveLoaded(32, 135, 127);
  moveRollers(-200);
  timedDrive(300, 30); //Timedout prevention
  scoreAuton9Cube();
  moveRollers(200);
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

//Default autonomous
void red_front_7_cubes()
{
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(40, 0, 45); //75
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront();
  moveRollers(-200);
  moveFast(14, 0, 25); //16, 75
  wait(300);
  moveBack(1, 0, 50); //Prevent robot from hitting cube

  //Turn to the corner
  turnRightProgramming(90);
  moveFast(6, 90, 127); //6
  moveMAX(26, 138, 127); //30
  timedDrive(350, 30);
  moveRollers(100);
  wait(300);
  moveRollers(0);
  scoreAuton7cube();
  moveRollers(200);
  wait(100);
  pros::Task task1(tilterBack);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

//Not used for state -> GDC line cross ruling
void red_front_8_cubes()
{
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(42, 0, 50); //75
  //timedDrive(400, 35);
  wait(200);
  //moveBack(1, 0, 127);

  //S-Turn to other Cubes
  Lift(0);
  STurn_RedFront();
  moveRollers(-200);
  move(23, 0, 90); //20
  //moveBack(1, 0, 50); //Prevent robot from hitting cube
  //wait(250);

  //Turn to the corner
  turnRightProgramming(130);
  //moveFast(6, 90, 127);
  moveMAX(30, 135, 127);
  timedDrive(350, 35);
  moveRollers(50);
  wait(250);
  moveRollers(0);
  brakeRollers();
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
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(18, 0, 50);
  wait(200);
  moveBack(2, 0, 50);
  turnRightProgramming(90);
  move(10, 90, 50);
  timedDrive(300, 35);
  wait(250);
  moveBack(10, 90, 50);
  turnLeftProgramming(-90);
  moveFast(10, -90, 50);
  sweepLeft(-130);
  timedDrive(250, 35);
  moveRollers(75);
  wait(350);
  moveRollers(0);
  scoreAuton7cube();
  pros::Task t(tilterBack);
  wait(200);
  moveRollers(200);
  moveBackNoPos(15, 127);
}

//***************BLUE AUTONOMOUS*****************************

//Only used for matches with weak partner and strong opponent
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

//Default autonomous
void blue_front_7_cubes()
{
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(40, 0, 45); //60
  wait(300);

  //S-Turn to other Cubes
  Lift(0);
  STurn_BlueFront();
  moveRollers(-200);
  moveFast(12, 0, 35); //10, 35
  wait(250);
  moveBack(1, 0, 50); //Prevent robot from hitting cube

  //Turn to the corner
  turnLeftProgramming(-90);
  moveFast(6, -90, 127); //6
  moveMAX(25, -138, 127); //30
  timedDrive(350, 30);
  moveRollers(100);
  wait(300);
  moveRollers(0);
  scoreAuton7cube();
  wait(200);
  moveRollers(200);
  pros::Task task1(tilterBack);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);

}

//Not used for state -> GDC line cross ruling
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
  scoreAuton9Cube();
  pros::Task task1(tilterBack);
  moveRollers(90);
  moveBackNoPos(25, 127);
  task1.remove();
  moveTilter(0);
}

//Protected Zone Autonomous
void blue_back()
{
  wait(200);
  resetTheta(0);
  deploy();
  moveRollers(-200);
  Lift(5);
  moveFast(18, 0, 50);
  wait(200);
  moveBack(2, 0, 50);
  turnLeftProgramming(-90);
  move(10, -90, 50);
  timedDrive(300, 35);
  wait(250);
  moveBack(10, -90, 50);
  turnRightProgramming(90);
  moveFast(10, 90, 50);
  sweepRight(130);
  timedDrive(250, 35);
  moveRollers(75);
  wait(350);
  moveRollers(0);
  scoreAuton7cube();
  pros::Task t(tilterBack);
  wait(200);
  moveRollers(200);
  moveBackNoPos(15, 127);
}

//**************AUTONOMOUS SELECTION*************************

void autonomous()
{

  setDriveMAXCurrent(); //Fixes bug that causes drive to slow during autonomous();

  //AUTON TESTS****************************************************************
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
  //programming_skills_75();

  //TEST TURNS*****************************************************************
  /*
  wait(500);
  turnRightProgramming(180);
  wait(500);
  turnRightProgramming(270);
  wait(500);
  turnRightProgramming(360);
  */

  //Autonomous Switch

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
      programming_skills_75();
      break;
   }

}

#ifndef _DRIVE_H_
#define _DRIVE_H_

//****************POSITION TRACKING FUNCTIONS*****************
void current_position(void* parameter);
void resetTheta(int degrees); //-O

//****************BASIC MOTOR FUNCTIONS*********************
void brake();
void wait(int duration);
void timedDrive(int time, int speed);
void right(int speed);
void left(int speed);

//********************TURN FUNCTIONS************************
void turnLeft(int angle); //-O
void turnLeftProgramming(int angle); //-O
void turnLeftLoaded(int angle); //-O
void turnLeftLoadedAuton(int angle); //-O
void turnRight(int angle); //-O
void turnRightNoPID(int angle, int speed); //-0
void turnRightProgramming(int angle); //-O
void turnRightLoaded(int angle); //-O
void turnRightLoadedAuton(int angle); //-O
void turnRightLoadedProgramming(int angle); //-O
void turnLeftLoadedProgramming(int angle); //-O
void turnRightHalfLoaded(int angle); //-O
void sweepRight(int angle); //-O
void rightSweep(int angle, int speed); //-O
void rightSweepBack(int angle, int speed); //-O
void sweepRightBack(int angle); //-O
void sweepRightProgramming(int angle, int rightSideSpeed); //-O
void sweepRightBackProgramming(int angle, int leftSideSpeed); //-O
void sweepRightBackLoaded(int angle); //-O
void sweepLeftBack(int angle); //-O
void sweepLeftBackProgramming(int angle, int rightSideSpeed); //-O
void sweepRightBackNoPID(int angle, int speed);
void sweepLeftBackNoPID(int angle, int speed);
void sweepLeftBackProgramming1(int angle); //-O
void sweepLeft(int angle); //-O
void leftSweep(int angle, int speed); //-O
void leftSweepBack(int angle, int speed); //-O
void STurn_RedFront(); //-O
void STurn_RedFront2(); //-O
void STurn_RedFront3(); //-O
void STurn_RedFront4(); //-O
void STurn_BlueFront(); //-O
void STurn_BlueFront3(); //-O
void STurn_BlueFront4(); //-O

//******************MOVE FUNCTIONS**************************
void move(int distance, int heading, int speed); //-O
void moveBackNoPID(int distance, int heading, int speed); //-O
void moveFast(int distance, int heading, int speed); //-O
void moveMAX(int distance, int heading, int speed); //accounted for v1.09 voltage change
void moveLoaded(int distance, int heading, int speed); //-O
void moveBack(int distance, int heading, int speed); //-O
void moveBackMAX(int distance, int heading, int speed); //-O
void moveBackNoPos(int distance, int speed); //-O
void moveBackLoaded(int distance, int heading, int speed); //-O
void moveBackFast(int distance, int heading, int speed); //-O

void setDriveMAXCurrent();
void driveOP();

#endif

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
void turnRight(int angle); //-O
void turnRightProgramming(int angle); //-O
void turnRightLoaded(int angle); //-O
void turnRightLoadedProgramming(int angle); //-O
void turnLeftLoadedProgramming(int angle); //-O
void turnRightHalfLoaded(int angle); //-O
void sweepRight(int angle); //-O
void sweepRightBack(int angle); //-O
void sweepLeftBack(int angle); //-O
void sweepLeftBackProgramming1(int angle); //-O
void sweepLeft(int angle); //-O
void STurn_RedFront(); //-O
void STurn_BlueFront(); //-O

//******************MOVE FUNCTIONS**************************
void move(int distance, int heading, int speed); //-O
void moveFastProgramming(int distance, int heading, int speed); //-O
void moveLoaded(int distance, int heading, int speed); //-O
void moveHalfLoaded(int distance, int heading, int speed); //-O
void moveBack(int distance, int heading, int speed); //-O
void moveBackNoPos(int distance, int speed); //-O
void moveBackLoaded(int distance, int heading, int speed); //-O
void moveBackFast(int distance, int heading, int speed); //-O


void driveOP();

#endif

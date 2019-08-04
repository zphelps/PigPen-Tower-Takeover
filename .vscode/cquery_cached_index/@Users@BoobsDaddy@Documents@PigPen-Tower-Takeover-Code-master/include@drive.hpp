#ifndef _DRIVE_H_
#define _DRIVE_H_

void current_position(void* parameter);
void turnLeft(int angle);
void turnRight(int angle);
void sweepRight(int angle);
void sweepRightBack(int angle);
void sweepLeftBack(int angle);
void sweepRightBack_Programming(int angle);
void sweepLeftBack_Programming(int angle);
void sweepLeft(int angle);
void sweepLeft_Programming(int angle);
void brake();
void wait(int duration);
void move(int distance, int heading, int speed);
//void moveSlew(int distance, int heading, int speed);
void moveFast(int distance, int heading, int speed);
void moveBack(int distance, int heading, int speed);
void moveBackFast(int distance, int heading, int speed);
void timedDrive(int time, int speed);
void right(int speed);
void left(int speed);
void driveOP();

#endif

#ifndef _DRIVE_H_
#define _DRIVE_H_

void current_position(void* parameter);
void turnToAbs(int angle);
void brake();
void wait(int duration);
void move(int distance, int heading, int speed);
void driveOP();

#endif

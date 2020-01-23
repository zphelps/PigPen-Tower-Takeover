#ifndef _LIFT_H_
#define _LIFT_H_

void liftOP();
void lift_brake();
void lift_coast();
void Lift(int speed);
void short_tower(void*parameter);
void moveLift(int time, int speed);
void liftDown(void* parameter);
void liftDownAuton(void* parameter);
void lift_position(int tics, int speed);
void cube_latch();
void cube_latch_big_stack();

#endif

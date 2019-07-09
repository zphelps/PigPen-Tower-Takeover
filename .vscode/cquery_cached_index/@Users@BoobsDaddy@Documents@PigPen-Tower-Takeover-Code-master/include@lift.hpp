#ifndef _LIFT_H_
#define _LIFT_H_

void liftOP();
void moveLift(int speed);
void lift_down();
void lift_down_task(void *parameter);
void pick_up_pos();
void pick_up_pos_low();
void pickUpTask(void* parameter);
void deposit_four_cubes();
void stack_on_four_cubes();
void deposit_last_three_cubes();
void alliance_tower_height();
void short_tower_height();
void medium_tower_height();
void tall_tower_height();
void medium_tower_deposit();
void alliance_tower_height_task(void* parameter);
void deposit_cube_in_tower();

#endif

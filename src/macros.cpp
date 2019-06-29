#include "main.h"

//motors
pros::Motor rightLift(7);
pros::Motor leftLift (6);
pros::Motor rightRoller (8);
pros::Motor leftRoller (5);

void deposit_cubes(void* parameter)
{
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
    rightLift.move_velocity(50);
    leftLift.move_velocity(50);
    leftRoller.move_velocity(200);
    rightRoller.move_velocity(200);

  }
}

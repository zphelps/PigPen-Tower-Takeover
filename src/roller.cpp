#include "main.h"

//motors
pros::Motor rightRoller (6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftRoller (3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

void rollerOP()
{
  rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
    leftRoller.move_velocity(-600);
    rightRoller.move_velocity(-600);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L2))) {
    leftRoller.move_velocity(600);
    rightRoller.move_velocity(600);
  }

  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R2))){
    leftRoller.move_velocity(600);
    rightRoller.move_velocity(600);
  }

  else {
    leftRoller.move_velocity(0);
    rightRoller.move_velocity(0);
  }
}

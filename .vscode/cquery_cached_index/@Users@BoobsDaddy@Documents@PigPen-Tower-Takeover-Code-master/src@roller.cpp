#include "main.h"

//motors
pros::Motor rightRoller (8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftRoller (5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

void rollerOP()
{
  rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
    leftRoller.move_velocity(-200);
    rightRoller.move_velocity(-200);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L2))) {
    leftRoller.move_velocity(200);
    rightRoller.move_velocity(200);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R2))){
    leftRoller.move_velocity(200);
    rightRoller.move_velocity(200);
  }
  else {
    leftRoller.move_velocity(0);
    rightRoller.move_velocity(0);
  }
}

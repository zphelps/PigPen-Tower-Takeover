#include "main.h"

//motors
pros::Motor tilter (17, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);


void tilterOP()
{
  tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))) {
    tilter.move_velocity(-200);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_UP))) {
    tilter.move_velocity(-65);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))) {
    tilter.move_velocity(200);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    tilter.move_velocity(-165);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    tilter.move_velocity(165);
  }
  else {
    tilter.move_velocity(0);
  }
}

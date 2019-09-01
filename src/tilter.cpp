#include "main.h"

//motors
pros::Motor tilter (17, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIPotentiometer tilterPot ('H');

//Autonomous FUNCTIONS

void score()
{
  bool done = false;

  while(done == false)
  {
    if (tilterPot.get_value() < 500)
    {
      tilter.move(-100);
    }
    else if (tilterPot.get_value() > 500)
    {
      tilter.move(100);
    }
    else
    {
      tilter.move(0);
      done = true;
    }

  }
}

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
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    score();
  }
  else {
    tilter.move_velocity(0);
  }
}

#include "main.h"

//motors
pros::Motor rightLift(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftLift (6, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIDigitalIn liftDown ('A');


void liftOP()
{
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  if(liftDown.get_value() == 1)	{
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightLift.move_velocity(150);
      leftLift.move_velocity(150);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      rightLift.move_velocity(0);
      leftLift.move_velocity(0);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R1))) {
      rightLift.move_velocity(50);
      leftLift.move_velocity(50);
    }
    else {
      leftLift.move(partner.get_analog(ANALOG_LEFT_Y));
      rightLift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }
  else {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightLift.move_velocity(100);
      leftLift.move_velocity(100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      rightLift.move_velocity(-100);
      leftLift.move_velocity(-100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R1))) {
      rightLift.move_velocity(50);
      leftLift.move_velocity(50);
    }
    else {
      leftLift.move(partner.get_analog(ANALOG_LEFT_Y));
      rightLift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }
}

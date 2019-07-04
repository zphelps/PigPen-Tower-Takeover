#include "main.h"

//motors
pros::Motor rightLift(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftLift (5, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIDigitalIn liftDown ('A');
pros::ADIPotentiometer liftPot ('B');


//Github Test Comment

//Constants
int pickUpPos = 1000;

void pick_up_pos(void* parameter)
{
  bool done = false;

  while(done == false)
  {
    if (liftPot.get_value() < pickUpPos - 10)
    {
      rightLift.move(-100);
      leftLift.move(-100);
    }
    else if (liftPot.get_value() > pickUpPos + 10)
    {
      rightLift.move(100);
      leftLift.move(100);
    }
    else
    {
      rightLift.move(0);
      leftLift.move(0);
      done = true;
    }

  }
}

//*************************** - OP Control - ***********************************
void liftOP()
{
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


  if(liftDown.get_value() == 1)	{
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightLift.move_velocity(100);
      leftLift.move_velocity(100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      rightLift.move_velocity(0);
      leftLift.move_velocity(0);
    }

    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R1))) {
      rightLift.move_velocity(95);
      leftLift.move_velocity(95);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
        pros::Task lift_pos(pick_up_pos);
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

    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R1))) {
      rightLift.move_velocity(95);
      leftLift.move_velocity(95);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
      pros::Task lift_pos(pick_up_pos);
    }
    else {
      leftLift.move(partner.get_analog(ANALOG_LEFT_Y));
      rightLift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }
}

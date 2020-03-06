#include "main.h"

//motors
pros::Motor lift(5, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIPotentiometer liftPot ('B');

void Lift(int speed)
{
  lift.move_velocity(speed);
}

void lift_brake()
{
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void lift_coast()
{
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void lift_position(int tics, int speed)
{
  lift.move_relative(tics, speed);
  while (!((lift.get_position() < tics + 5) && (lift.get_position() > tics - 5))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
}

void moveLift(int time, int speed)
{
  lift.move_velocity(speed);
  wait(time);
  lift.move_velocity(0);
  lift_brake();
}

void liftDown(void* parameter)
{
  moveLift(1400, 100);
}

void liftDownAuton(void* parameter)
{
  moveLift(1200, 100);
}

void cube_latch()
{
  Lift(-100);
  wait(125); //200
  moveRollers(200);
  wait(300); //220
  moveRollers(0);
  brakeRollers();
  wait(500); //500
  Lift(0);
  lift_brake();
}

void cube_latch_big_stack()
{
  Lift(-100);
  wait(200);
  moveRollers(150);
  wait(250);
  moveRollers(0);
  brakeRollers();
  wait(500);
  Lift(0);
  lift_brake();
}

//*************************** - OP Control - ***********************************
void liftOP()
{
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      lift.move_velocity(-100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      lift.move_velocity(100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      cube_latch();
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      deployOP();
    }
    else {
      lift.move(partner.get_analog(ANALOG_LEFT_Y));
    }
  }

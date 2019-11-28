#include "main.h"

//motors
pros::Motor rightRoller (18, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftRoller (14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADILineSensor cubeDetector('B');

void moveRollers(int speed)
{
  leftRoller.move(-speed);
  rightRoller.move(-speed);
}

void brakeRollers()
{
  rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void coastRollers()
{
  rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void intakeOut()
{
  moveRollers(-100);
}

void collectCube(void*parameter) {
  while(cubeDetector.get_value() > 1900) {
    moveRollers(-200);
  }
  moveRollers(0);
  brakeRollers();
}

void rollersOP()
{
  pros::lcd::print(6, "Color: %d", cubeDetector.get_value());
  rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
    leftRoller.move_velocity(200);
    rightRoller.move_velocity(200);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L2))) {
    leftRoller.move_velocity(-200);
    rightRoller.move_velocity(-200);
  }
  else {
    leftRoller.move_velocity(0);
    rightRoller.move_velocity(0);
  }
}

#include "main.h"


//motors
pros::Motor leftFront (1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBack (2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBack (9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//Tracking Encoders
pros::ADIEncoder R ('G', 'H', false);
pros::ADIEncoder L ('C', 'D', false);
pros::ADIEncoder S ('E', 'F', false);


void current_position(void* parameter)
{

  pros::lcd::initialize();

  int R_pos = 0;
  int L_pos = 0;
  int S_pos = 0;

  R.reset();
  L.reset();
  S.reset();

  //pros::lcd::print(0, "L: %d", L_pos);

  while(true)
  {
    //Get Value
    R_pos = R.get_value();
    L_pos = L.get_value();
    S_pos = S.get_value();

    pros::delay(100);
    //Display to Screen
    pros::lcd::print(0, "R: %d", R_pos);
    pros::lcd::print(1, "L: %d", L_pos);
    pros::lcd::print(2, "S: %d", S_pos);

  }
}

void driveOP()
{
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    leftFront.move(200);
    leftBack.move(200);
    rightFront.move(-200);
    rightBack.move(-200);

    pros::delay(500);

    leftFront.move(0);
    leftBack.move(0);
    rightFront.move(0);
    rightBack.move(0);
  }
  leftFront.move(master.get_analog(ANALOG_LEFT_Y));
  leftBack.move(master.get_analog(ANALOG_LEFT_Y));
  rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
  rightBack.move(master.get_analog(ANALOG_RIGHT_Y));
}

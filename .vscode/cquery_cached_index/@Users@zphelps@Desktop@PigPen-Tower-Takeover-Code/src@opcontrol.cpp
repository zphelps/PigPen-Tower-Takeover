#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	//Drive Base Definitions
	pros::Motor leftFront(5);
	pros::Motor leftBack(4);
	pros::Motor rightFront(3);
	pros::Motor rightBack(2);

	//Lift Definitions
	pros::Motor rightLift(6);
	pros::Motor leftLift(7);

	//Roller Definition
	pros::Motor roller(10);

	//Four bar Definition
	pros::Motor fourBar(1);

	//Set motors to brake

	rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fourBar.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	roller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


	while (true) {
		/*
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
										 */
		//Lift Code:

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightLift.move_velocity(150);
			leftLift.move_velocity(150);
    }
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			rightLift.move_velocity(-150);
			leftLift.move_velocity(-150);
		}
    else {
			rightLift.move_velocity(0);
			leftLift.move_velocity(0);
    }

		//Roller Code:
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			roller.move_velocity(200);
    }
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			roller.move_velocity(-200);
		}
    else {
			roller.move_velocity(0);
    }

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
			fourBar.move_velocity(-25);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			fourBar.move_velocity(25);
		}
		else {
			fourBar.move_velocity(0);
		}

		//Drive Code:

		leftFront.move(master.get_analog(ANALOG_LEFT_Y));
		leftBack.move(master.get_analog(ANALOG_LEFT_Y));
    rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
		rightBack.move(master.get_analog(ANALOG_RIGHT_Y));


		/*
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);


		leftFront = left;
		leftBack = left;
		rightFront = right;
		rightBack = right;
		*/
		pros::delay(20);
	}
}

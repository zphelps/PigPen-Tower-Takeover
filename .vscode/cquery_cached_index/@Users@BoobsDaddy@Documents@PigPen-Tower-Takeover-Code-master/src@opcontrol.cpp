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
	pros::Controller partner(pros::E_CONTROLLER_PARTNER);


	//Drive Base Definitions
	pros::Motor leftFront(15);
	pros::Motor leftBack(11);
	pros::Motor rightFront(13);
	pros::Motor rightBack(19);

	//Lift Definitions
	pros::Motor rightLift(16);
	pros::Motor leftLift(17);

	//Roller Definition
	pros::Motor leftRoller(12);

	//Four bar Definition
	pros::Motor rightRoller(10);

	//Set motors to brake

	rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	//Sensors
	pros::ADIDigitalIn liftDown ('A');


	while (true) {
		/*
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
										 */
		//Lift Code:
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
				rightLift.move_velocity(25);
				leftLift.move_velocity(25);
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
				rightLift.move_velocity(25);
				leftLift.move_velocity(25);
			}
	    else {
				leftLift.move(partner.get_analog(ANALOG_LEFT_Y));
				rightLift.move(partner.get_analog(ANALOG_LEFT_Y));
	    }
		}


		//Roller Code Normal:
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
			leftRoller.move_velocity(-200);
			rightRoller.move_velocity(-200);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_L2))) {
			leftRoller.move_velocity(200);
			rightRoller.move_velocity(200);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) || (partner.get_digital(pros::E_CONTROLLER_DIGITAL_R2))){
			leftRoller.move_velocity(100);
			rightRoller.move_velocity(100);
		}
		else {
			leftRoller.move_velocity(0);
			rightRoller.move_velocity(0);
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))	{
			leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
			leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		}
		//Drive Code:

		leftFront.move(master.get_analog(ANALOG_LEFT_Y));
		leftBack.move(master.get_analog(ANALOG_LEFT_Y));
    rightFront.move(master.get_analog(ANALOG_RIGHT_Y));
		rightBack.move(master.get_analog(ANALOG_RIGHT_Y));

		//PARTNER CONTROLLER COMMANDS





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

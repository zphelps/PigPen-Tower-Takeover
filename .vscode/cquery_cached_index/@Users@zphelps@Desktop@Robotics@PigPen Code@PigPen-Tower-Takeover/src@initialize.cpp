#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

pros::ADIDigitalIn selector ('A');
int autonIndex = 0;

void autonSelector(void*parameter)
{

	wait(500);

	const int autoCount = 9;
  const char *autoNames[autoCount] = {
		"Red Front - 8 Cubes",
		"Red Front - 6 Cubes",
    "Red Front - 5 Cubes",
		"Red Back",
		"Blue Front - 8 Cubes",
    "Blue Front - 6 Cubes",
		"Blue Front - 5 Cubes",
    "Blue Back",
    "Programming Skills"
  };

	pros::lcd::print(4, "%s", autoNames[autonIndex]);

	while(true)
	{

		if (selector.get_value())
		{
			autonIndex = autonIndex + 1;
			if (autonIndex == autoCount)
				autonIndex = 0;

			pros::lcd::print(4, "%s", autoNames[autonIndex]);
			wait(300);
		}
	}
}

void initialize() {

	pros::lcd::initialize();

	pros::lcd::set_text(4, "Red Front - 8 Cubes");


	pros::Task lcd_task(autonSelector);
	lcd_task.set_priority(LV_TASK_PRIO_LOW);
/*
	if(pros::competition::is_autonomous() || pros::competition::is_connected()) {
		lcd_task.remove();
	}
*/
	//Tasks
	pros::Task drive_pos(current_position);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

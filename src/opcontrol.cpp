#include "main.h"

 pros::Controller master(pros::E_CONTROLLER_MASTER);
 pros::Controller partner(pros::E_CONTROLLER_PARTNER);


void opcontrol() {
	while (true) {
		driveOP();
		liftOP();
		rollerOP();
    if (master.get_digital(DIGITAL_A))
    {
      autonomous();
    }
		pros::delay(10);
	}
}

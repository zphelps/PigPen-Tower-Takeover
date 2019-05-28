#include "main.h"
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
using namespace okapi;
const int DRIVE_LEFTBACK_MOTOR_PORT = 4;
const int DRIVE_RIGHTBACK_MOTOR_PORT = 2;

auto chasis = ChassisControllerFactory::create(DRIVE_LEFTBACK_MOTOR_PORT,DRIVE_RIGHTBACK_MOTOR_PORT);

void autonomous() {






}

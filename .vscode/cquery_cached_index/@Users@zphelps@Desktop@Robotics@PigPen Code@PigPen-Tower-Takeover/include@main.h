//Final Tower Bot Branch
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "okapi/api.hpp"

//Includes
#include "api.h"
#include "drive.hpp"
#include "lift.hpp"
#include "rollers.hpp"
#include "tilter.hpp"
#include "macros.hpp"

using namespace okapi;

extern pros::Controller master;
extern pros::Controller partner;
extern int autonIndex;
extern pros::ADIPotentiometer liftPot;
extern pros::ADIPotentiometer tilterPot;

extern pros::Motor rightRoller;
extern pros::Motor leftRoller;

extern pros::Motor tilter;

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
#include "main.h"


auto myChassis = ChassisControllerFactory::create(
  {1,-2},
  {-10,9},
  AbstractMotor::gearset::green,
  {4_in,15_in}
);

#include "main.h"

void deploy() {

  left(-30);
  right(-30);
  moveRollers(200);

  moveLift(650, -127);

  moveLift(750, 127);

  wait(100);
  left(0);
  right(0);

}

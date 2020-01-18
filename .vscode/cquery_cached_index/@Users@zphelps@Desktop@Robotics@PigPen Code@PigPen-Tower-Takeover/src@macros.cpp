#include "main.h"

void deploy() {

  left(-30);
  right(-30);
  moveRollers(200);

  moveLift(300, -127); //650

  wait(50);
  moveLift(350, 127); //750

  wait(350);
  left(0);
  right(0);

}

#include "main.h"

void deploy() {

  left(-45); //-30
  right(-45); //-30
  moveRollers(200);

  moveLift(300, -127); //650

  wait(50);
  moveLift(350, 127); //750

  wait(500); //350
  left(0);
  right(0);

}

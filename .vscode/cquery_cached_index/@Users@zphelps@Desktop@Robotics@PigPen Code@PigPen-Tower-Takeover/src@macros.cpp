#include "main.h"

void deploy() {

  moveFast(4, 0, 127);
  moveRollers(200);


  Lift(10);

  timedDrive(500, -60);
  wait(1000); //500

}

void deployOP() {

  left(-30);
  right(-30);
  Lift(10);
  moveRollers(200);
  wait(1000); //1500
  right(0);
  left(0);
  Lift(0);

}

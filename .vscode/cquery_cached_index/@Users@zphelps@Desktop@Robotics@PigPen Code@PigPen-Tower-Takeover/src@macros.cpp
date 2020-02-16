#include "main.h"

// void deploy() {
//
//   left(-45); //-30
//   right(-45); //-30
//   moveRollers(200);
//
//   moveLift(250, -127); //300
//
//   wait(0);
//   moveLift(350, 127); //750
//
//   wait(350); //350
//   left(0);
//   right(0);
//
// }

void deploy() {

  move(5, 0, 127);
  moveRollers(200);

  Lift(10);

  timedDrive(350, -50);
  wait(500); //350

}

void deployOP() {

  //left(-45); //-30
  //right(-45); //-30
  //moveRollers(200);

  moveLift(250, -127); //650

  wait(0);
  moveLift(350, 127); //750

  //wait(350); //350
  //left(0);
  //right(0);

}

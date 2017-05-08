
#include <stdio.h>
#include <time.h>
#include "E101.h"

// when line in centre of camera, power both motors.
// when line on left of camera, power right motor.
// when line on right of camera, power left motor.
// when no line on camera, reverse power both motors.

// if irsensorleft is <xyz, IRsL = 1 (near).
// if irsensorleft is >xyz, IRsL = 0 (far).
// if irsensorright is <xyz, IRsR = 1 (near).
// if irsensorright is >xyz, IRsL = 0 (far).

// when level of irsensorleft is 1, power left motor.
// when level of irsensorright is 1, power right motor.
// when level of irsensorfront is 1, turn around (power left, reverse power right or vice versa).

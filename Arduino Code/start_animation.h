#ifndef START_ANIMATION_H
#define START_ANIMATION_H

#include <LiquidCrystal.h>

// Define custom characters
extern byte zero[];
extern byte one[];
extern byte two[];
extern byte three[];
extern byte four[];
extern byte five[];

// Function declarations
void setupAnimation();
void quickProgressBar();
void startAnimation();

#endif // START_ANIMATION_H

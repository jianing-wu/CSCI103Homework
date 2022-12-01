//This file also starts out empty.
//Implement the Turtle class here.

#include<iostream>
#include<cmath>
#include "turtle.h"
using namespace std;

Turtle::Turtle(double xInit, double yInit, double dirInit) {
  xPos = xInit;
  yPos = yInit;
  dir = dirInit;
  color = draw::BLACK;
  vanish = false;
} 
  
void Turtle::move(double dist) {
  double x0 = xPos;
  double y0 = yPos;
  xPos += dist * cos(dir * M_PI / 180);
  yPos += dist * sin(dir * M_PI / 180);
  if (vanish == false) {
    draw::setcolor(color);
    draw::line(x0, y0, xPos, yPos);
  }
}

void Turtle::turn(double deg) {
  dir += deg;
}

void Turtle::setColor(Color c) {
  color = c;
}

void Turtle::off() {
  vanish = true;
}
void Turtle::on() {
  vanish = false;
}


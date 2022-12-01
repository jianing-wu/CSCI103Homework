//This file starts out empty!
//Define the Turtle class here.

#include "draw.h"

class Turtle {
  public:
    Turtle(double xInit, double yInit, double dirInit);
    void move(double dist);
    void turn(double deg);
    void setColor(Color c);
    void off();
    void on();
  
  private:
    double xPos;
    double yPos;
    double dir;
    Color color;
    bool vanish;
};
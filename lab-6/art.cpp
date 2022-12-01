#include "turtle.h"
#include "draw.h"

void square(Turtle);
void rectangle(Turtle);
void line(Turtle);
void circle(Turtle);

int main() {
  draw::setpenwidth(5);
  draw::setrange(-150, 150);
  
  Turtle cute(24, 48, 96);
  Turtle handsome(50, 50, 45);
  Turtle lazy(0, 0, 0);
  Turtle smart(-100, -70, 270);
  
  square(cute);
  rectangle(handsome);
  line(lazy);
  circle(smart);
  
  return 0;
}

void square(Turtle t) {
  t.setColor(draw::BLUE);
  t.move(30);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(30);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(30);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(30);
  draw::show(10);
}

void rectangle(Turtle t) {
  t.setColor(draw::GREEN);
  t.move(30);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(70);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(30);
  draw::show(10);
  t.turn(90);
  draw::show(10);
  t.move(70);
  draw::show(10);
}

void line(Turtle t) {
  t.setColor(draw::BLACK);
  t.move(100);
  draw::show(10);
}

void circle(Turtle t) {
t.setColor(draw::RED);
for (int i=0; i<100; i++) {
      t.move(300.0/100); 
      t.turn(360.0/100);
      draw::show(1);
   }
}
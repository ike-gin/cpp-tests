#include <iostream>

using namespace std;

class DrawTechnique {
public:
  virtual void draw() = 0;
  virtual ~DrawTechnique() = default;
};

class FastDrawTechnique : public DrawTechnique {
public:
  void draw(){ cout << "fast drawing" << endl; }
};

class SlowDrawTechnique : public DrawTechnique {
public:
  void draw(){ cout << "slow drawing" << endl; }
};


class Shape {
public:
  virtual void draw() = 0;
  virtual ~Shape(){};
};

class Square : public Shape {
public:
  Square(DrawTechnique* dt) : d(dt) {}
  void draw() { cout << "Square "; d->draw(); };
  DrawTechnique *d = nullptr;

  ~Square() { delete d; }
};

class Circle : public Shape {
public:
  Circle(DrawTechnique* dt) : d(dt) {}
  void draw() { cout << "Circle "; d->draw(); };
  DrawTechnique *d = nullptr;

  ~Circle() { delete d; }
};


int main() {

  Shape *s = new Square(new FastDrawTechnique);
  s->draw();

  Shape *c = new Circle(new SlowDrawTechnique);
  c->draw();

  Shape *s2 = new Square(new SlowDrawTechnique);
  s2->draw();


  delete s;
  delete c;
  delete s2;

  return 0;
}

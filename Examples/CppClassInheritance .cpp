#include <iostream>

class Shape {
public:
  Shape() {}
  virtual int getArea() = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(int width, int height) : width(width), height(height) {}
  int getArea() { return width * height; }

private:
  int width;
  int height;
};

class Circle : public Shape {
public:
  Circle(int radius) : radius(radius) {}
  int getArea() { return 3.14 * radius * radius; }

private:
  int radius;
};

int main() {
  Rectangle rect(10, 5);
  Circle circle(7);
  Shape* shapes[2];
  shapes[0] = &rect;
  shapes[1] = &circle;
  for (int i = 0; i < 2; i++) {
    std::cout << "Area: " << shapes[i]->getArea() << std::endl;
  }
  return 0;
}

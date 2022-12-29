#include <iostream>

class Point2d
{
public:

  void Set(int dx, int dy);
  int GetX();
  int GetY();
  void Display();

private:

  int mX;
  int mY;

};

void Point2d::Set(int dx, int dy)
{
  mX = dx;
  mY = dy;
}

int Point2d::GetX()
{
  return mX;
}

int Point2d::GetY()
{
  return mY;
}

void Point2d::Display()
{
  std::cout << "X: " << mX <<
   ", Y: " << mY << std::endl;
}


int main() {
  Point2d point;
  point.Set(0,5);
  point.Display();

  Point2d point2;
  point2.Set(7, 11);
  point2.Display();

  std::cout << "X: " << point2.GetX() 
  << ", Y: " << point2.GetY() << std::endl;

  std::cout << "the size of my point is: "
  << sizeof(point2) << std::endl;

  return 0;
}
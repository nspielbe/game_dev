#include <iostream>

class Point2d
{
public:

  void Set(int dx, int dy);
  int GetX();
  int GetY();
  void Display();
  Point2d* PointOurselves();
  Point2d& RefOurselves();

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

Point2d* Point2d::PointOurselves(){
  return this;
}

Point2d& Point2d::RefOurselves(){
  return *this;
}


int main() {
  Point2d point;
  point.Set(0,5);
  point.Display();

  Point2d& refPoint = point.RefOurselves();
  Point2d* ptrPoint = point.PointOurselves();

  std::cout << "The address of point is: " << &point << " and the refpoint address is: " << &refPoint << " and lastly the pointer points to: " <<  ptrPoint << std::endl;

  return 0;
}
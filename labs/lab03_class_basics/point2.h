#ifndef LAB03_POINT2_H_
#define LAB03_POINT2_H_

class Point2 {
  public:
    float DistanceBetween(Point2 point_);
    int Quadrant();
    void Print();
    Point2(float x=0, float y=0);

  private:
    float point[2];


};

#endif /* LAB03_POINT2_H */

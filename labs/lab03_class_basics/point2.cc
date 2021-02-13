#include <cmath>
#include <iostream>

#include "point2.h"

float Point2::DistanceBetween(Point2 point_) {
  return sqrt((point_.point[0] - point[0]) * (point_.point[0] - point[0]) +
              (point_.point[1] - point[1]) * (point_.point[1] - point[1]));
}

void Point2::Print() {
  std::cout
  << "X coordinate:" <<point[0] << " Y coordinate:" << point[1] << std::endl;
}

int Point2::Quadrant() {
  if(point[0]==0){
    if(point[1]==0){
      return 0;
    }else if(point[1]>0){
      return 2;
    }else if(point[1]<0){
      return 4;
    }
  }
  else if(point[0]>0){
    if(point[1]>=0){
      return 1;
    }else if(point[1]<0){
      return 4;
    }
  }
  else if(point[0]<0){
    if(point[1]<=0){
      return 3;
    }else if(point[1]>0){
      return 2;
    }
  }
}

Point2::Point2(float x, float y) {
  point[0] = x;
  point[1] = y;
}

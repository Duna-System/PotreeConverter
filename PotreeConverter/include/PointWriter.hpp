
#ifndef POINTWRITER_H
#define POINTWRITER_H

#include <iostream>
#include <string>

#include "Point.h"

using std::string;

namespace Potree {

class PointWriter {
 public:
  string file;
  int numPoints = 0;

  virtual ~PointWriter(){};

  virtual void write(const Point &point) = 0;

  virtual void close() = 0;
};

}  // namespace Potree

#endif

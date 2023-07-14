

#ifndef POINTREADER_H
#define POINTREADER_H

#include <filesystem>

#include "AABB.h"
#include "Point.h"

namespace Potree {

class PointReader {
 public:
  virtual ~PointReader(){};

  virtual bool readNextPoint() = 0;

  virtual Point getPoint() = 0;

  virtual AABB getAABB() = 0;

  virtual long long numPoints() = 0;

  virtual void close() = 0;
};

}  // namespace Potree

#endif
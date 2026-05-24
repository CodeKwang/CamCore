#ifndef GLOBAL_H
#define GLOBAL_H

#include <QList>
#include <QVariantMap>

namespace CamCore {

enum OpType { Drill = 0 };

enum PathMode { G0_Fast, G1_Cut };

struct PathSegment {
  PathMode mode;
  double x, y, z;
  double feed;
  double speed;
};

using ToolPath = QList<PathSegment>;

} // namespace CamCore

#endif

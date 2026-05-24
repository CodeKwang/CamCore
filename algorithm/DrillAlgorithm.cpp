#include "DrillAlgorithm.h"
#include "../core/BaseOperation.h"

namespace CamCore {

ToolPath DrillAlgorithm::calculate(BaseOperation *op) {
  auto p = op->saveParams();
  double depth = p["depth"].toDouble();
  double feed = p["feed"].toDouble();
  double speed = p["speed"].toDouble();

  ToolPath path;
  path.append({G0_Fast, 0, 0, 50, 0, 0});
  path.append({G1_Cut, 0, 0, -depth, feed, speed});
  path.append({G0_Fast, 0, 0, 50, 0, 0});
  return path;
}

} // namespace CamCore

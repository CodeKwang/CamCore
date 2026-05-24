#ifndef DRILLALGORITHM_H
#define DRILLALGORITHM_H

#include "BaseAlgorithm.h"

namespace CamCore {

class DrillAlgorithm : public BaseAlgorithm {
public:
  ToolPath calculate(BaseOperation *op) override;
};

} // namespace CamCore

#endif

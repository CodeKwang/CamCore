#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H

#include "../core/Global.h"

namespace CamCore {

class BaseOperation;

class BaseAlgorithm {
public:
  virtual ~BaseAlgorithm() = default;
  virtual ToolPath calculate(BaseOperation *op) = 0;
};

} // namespace CamCore

#endif // BASEALGORITHM_H

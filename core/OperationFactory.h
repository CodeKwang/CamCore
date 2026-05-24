#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "BaseOperation.h"
#include "DrillOperation.h"

namespace CamCore {

class OperationFactory {
public:
  static BaseOperation *create(OpType type) {
    if (type == Drill)
      return new DrillOperation;
    return nullptr;
  }
};

} // namespace CamCore

#endif

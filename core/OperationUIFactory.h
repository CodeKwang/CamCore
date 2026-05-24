#ifndef OPERATIONUIFACTORY_H
#define OPERATIONUIFACTORY_H

#include "../ui/BaseOperationUI.h"
#include "../ui/DrillOperationUI.h"
#include "BaseOperation.h"

namespace CamCore {

class OperationUIFactory {
public:
  static BaseOperationUI *createUI(BaseOperation *op) {
    if (!op)
      return nullptr;

    switch (op->opType()) {
    case Drill:
      return new DrillOperationUI(op);
    default:
      return nullptr;
    }
  }
};

} // namespace CamCore

#endif // OPERATIONUIFACTORY_H

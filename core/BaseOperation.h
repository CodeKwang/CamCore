#ifndef BASEOPERATION_H
#define BASEOPERATION_H

#include "../algorithm/BaseAlgorithm.h"
#include "Global.h"

namespace CamCore {

class BaseOperation {
public:
  BaseOperation() : m_algorithm(nullptr) {}
  virtual ~BaseOperation() { delete m_algorithm; }

  virtual OpType opType() const = 0;
  virtual void loadParams(const QVariantMap &map) = 0;
  virtual QVariantMap saveParams() const = 0;

  ToolPath computeToolPath() {
    return m_algorithm ? m_algorithm->calculate(this) : ToolPath();
  }

protected:
  void setAlgorithm(BaseAlgorithm *alg) {
    delete m_algorithm;
    m_algorithm = alg;
  }

  QVariantMap m_params;

private:
  BaseAlgorithm *m_algorithm;
};

} // namespace CamCore

#endif

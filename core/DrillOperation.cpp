#include "DrillOperation.h"
#include "../algorithm/DrillAlgorithm.h"

namespace CamCore {

DrillOperation::DrillOperation() {
  m_params["depth"] = 10.0;
  m_params["diameter"] = 5.0;
  m_params["feed"] = 100.0;
  m_params["speed"] = 3000.0;
  setAlgorithm(new DrillAlgorithm);
}

OpType DrillOperation::opType() const { return Drill; }
void DrillOperation::loadParams(const QVariantMap &map) { m_params = map; }
QVariantMap DrillOperation::saveParams() const { return m_params; }

void DrillOperation::setParam(ParamKey key, const QVariant &var) {
  m_params[paramKey(key)] = var;
}

QVariant DrillOperation::getParam(ParamKey key) const {
  return m_params[paramKey(key)];
}

QMap<DrillOperation::ParamKey, QString> DrillOperation::paramKeyMap() {
  static QMap<ParamKey, QString> map = {{Param_Depth, "depth"},
                                        {Param_Diameter, "diameter"},
                                        {Param_Feed, "feed"},
                                        {Param_Speed, "speed"}};
  return map;
}

QString DrillOperation::paramKey(ParamKey key) {
  return paramKeyMap().value(key);
}

} // namespace CamCore

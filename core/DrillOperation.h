#ifndef DRILLOPERATION_H
#define DRILLOPERATION_H

#include "BaseOperation.h"

namespace CamCore {

class DrillOperation : public BaseOperation {
public:
  enum ParamKey {
    Param_Depth,    // 深度
    Param_Diameter, // 直径
    Param_Feed,     // 进给
    Param_Speed     // 转速F
  };
  DrillOperation();
  OpType opType() const override;
  void loadParams(const QVariantMap &map) override;
  QVariantMap saveParams() const override;

  void setParam(ParamKey key, const QVariant &var);
  QVariant getParam(ParamKey key) const;

  static QMap<ParamKey, QString> paramKeyMap();
  static QString paramKey(ParamKey key);
};

} // namespace CamCore

#endif

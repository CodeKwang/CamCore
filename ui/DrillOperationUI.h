#ifndef DRILLOPERATIONUI_H
#define DRILLOPERATIONUI_H

#include "BaseOperationUI.h"
#include <QDoubleSpinBox>

namespace CamCore {

class DrillOperationUI : public BaseOperationUI {
  Q_OBJECT
public:
  explicit DrillOperationUI(BaseOperation *op, QWidget *parent = nullptr);

  void bindOperation() override;
  void saveToOperation() override;

private:
  void initUI();

private:
  QDoubleSpinBox *m_depth;
  QDoubleSpinBox *m_diameter;
  QDoubleSpinBox *m_feed;
  QDoubleSpinBox *m_speed;
};

} // namespace CamCore

#endif // DRILLOPERATIONUI_H

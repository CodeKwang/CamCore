#include "DrillOperationUI.h"
#include "../core/DrillOperation.h"
#include "../template/ParamManager.h"
#include <QFormLayout>
#include <QGroupBox>
#include <QVBoxLayout>

namespace CamCore {

DrillOperationUI::DrillOperationUI(BaseOperation *op, QWidget *parent)
    : BaseOperationUI(op, parent) {
  initUI();
}

void DrillOperationUI::bindOperation() {
  auto drillOperation = dynamic_cast<DrillOperation *>(m_operation);
  if (!drillOperation)
    return;
  auto params = m_operation->saveParams();
  ParamManager::instance().init(params);

  m_depth->setValue(
      drillOperation->getParam(DrillOperation::Param_Depth).toDouble());
  m_diameter->setValue(
      drillOperation->getParam(DrillOperation::Param_Diameter).toDouble());
  m_feed->setValue(
      drillOperation->getParam(DrillOperation::Param_Feed).toDouble());
  m_speed->setValue(
      drillOperation->getParam(DrillOperation::Param_Speed).toDouble());
}

void DrillOperationUI::saveToOperation() {
  auto drillOperation = dynamic_cast<DrillOperation *>(m_operation);
  if (!drillOperation)
    return;
  drillOperation->setParam(DrillOperation::Param_Depth, m_depth->value());
  drillOperation->setParam(DrillOperation::Param_Diameter, m_diameter->value());
  drillOperation->setParam(DrillOperation::Param_Feed, m_feed->value());
  drillOperation->setParam(DrillOperation::Param_Speed, m_speed->value());

  ParamManager::instance().apply();
}

void DrillOperationUI::initUI() {
  setMinimumWidth(350);

  auto layout = new QVBoxLayout(this);
  auto group = new QGroupBox("钻孔参数", this);
  auto form = new QFormLayout(group);

  m_depth = new QDoubleSpinBox;
  m_diameter = new QDoubleSpinBox;
  m_feed = new QDoubleSpinBox;
  m_speed = new QDoubleSpinBox;
  m_depth->setMaximum(10000);
  m_diameter->setMaximum(10000);
  m_feed->setMaximum(10000);
  m_speed->setMaximum(10000);

  form->addRow("钻孔深度", m_depth);
  form->addRow("刀具直径", m_diameter);
  form->addRow("进给速度", m_feed);
  form->addRow("主轴转速", m_speed);

  layout->addWidget(group);
  layout->addStretch();

  // 绑定数据
  bindOperation();

  // 绑定参数变更
  auto bindChange = [&](QDoubleSpinBox *box, DrillOperation::ParamKey key) {
    connect(box, &QDoubleSpinBox::valueChanged, this, [=](double v) {
      ParamManager::instance().update(DrillOperation::paramKey(key), v);
      box->setStyleSheet(
          ParamManager::instance().isModified(DrillOperation::paramKey(key))
              ? "background:#fff9c4"
              : "background:white");
    });
  };

  bindChange(m_depth, DrillOperation::Param_Depth);
  bindChange(m_diameter, DrillOperation::Param_Diameter);
  bindChange(m_feed, DrillOperation::Param_Feed);
  bindChange(m_speed, DrillOperation::Param_Speed);
}

} // namespace CamCore

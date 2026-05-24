#ifndef BASEOPERATIONUI_H
#define BASEOPERATIONUI_H

#include "../core/BaseOperation.h"
#include <QWidget>

namespace CamCore {

class BaseOperationUI : public QWidget {
  Q_OBJECT
public:
  explicit BaseOperationUI(BaseOperation *op, QWidget *parent = nullptr);

  // 标准接口（多态）
  virtual void bindOperation() = 0;   // 数据→UI
  virtual void saveToOperation() = 0; // UI→数据

protected:
  BaseOperation *m_operation;
};

} // namespace CamCore

#endif // BASEOPERATIONUI_H

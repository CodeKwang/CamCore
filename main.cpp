#include "./core/OperationFactory.h"
#include "./core/OperationUIFactory.h"
#include "./template/TemplateManager.h"
#include <QApplication>

using namespace CamCore;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  // 1. 创建工序（数据+算法）
  BaseOperation *op = OperationFactory::create(Drill);

  // 2. 自动创建对应UI（完全多态）
  BaseOperationUI *ui = OperationUIFactory::createUI(op);
  ui->show();

  // 3. 保存参数
  ui->saveToOperation();

  // 4. 计算刀路
  auto path = op->computeToolPath();

  // 5. 模板
  auto tpl = OpTemplate::fromOp(op);
  TemplateManager::instance().add(tpl);

  delete op;
  return a.exec();
}

#ifndef TEMPLATEMANAGER_H
#define TEMPLATEMANAGER_H

#include "../core/BaseOperation.h"
#include <QList>

namespace CamCore {

struct OpTemplate {
  QString name;
  OpType type;
  QVariantMap params;

  static OpTemplate fromOp(BaseOperation *op) {
    OpTemplate tpl;
    tpl.type = op->opType();
    tpl.params = op->saveParams();
    tpl.name = "钻孔模板";
    return tpl;
  }

  void apply(BaseOperation *op) { op->loadParams(params); }
};

class TemplateManager {
public:
  static TemplateManager &instance() {
    static TemplateManager mgr;
    return mgr;
  }
  void add(const OpTemplate &t) { m_list.append(t); }
  QList<OpTemplate> all() const { return m_list; }

private:
  QList<OpTemplate> m_list;
};

} // namespace CamCore

#endif

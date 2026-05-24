#ifndef PARAMMANAGER_H
#define PARAMMANAGER_H

#include <QMap>
#include <QVariantMap>

namespace CamCore {

struct ParamItem {
  QVariant origin;
  QVariant current;
  bool modified = false;
};

class ParamManager {
public:
  static ParamManager &instance() {
    static ParamManager ins;
    return ins;
  }

  void init(const QVariantMap &map) {
    m_data.clear();
    for (auto it = map.begin(); it != map.end(); ++it) {
      ParamItem item;
      item.origin = item.current = it.value();
      m_data[it.key()] = item;
    }
  }

  void update(const QString &key, const QVariant &val) {
    if (!m_data.contains(key))
      return;
    m_data[key].current = val;
    m_data[key].modified = (val != m_data[key].origin);
  }

  bool isModified(const QString &key) { return m_data.value(key).modified; }

  void apply() {
    for (auto &item : m_data) {
      item.origin = item.current;
      item.modified = false;
    }
  }

private:
  ParamManager() = default;
  QMap<QString, ParamItem> m_data;
};

} // namespace CamCore

#endif

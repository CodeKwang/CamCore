#include "BaseOperationUI.h"

namespace CamCore {

BaseOperationUI::BaseOperationUI(BaseOperation* op, QWidget* parent)
    : QWidget(parent), m_operation(op)
{
}

}

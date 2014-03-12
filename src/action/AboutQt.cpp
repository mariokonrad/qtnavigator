#include "AboutQt.hpp"

namespace action {

AboutQt::AboutQt(QObject* parent)
	: QAction(parent)
{
	setText(tr("AboutQt"));
	setStatusTip(tr("Shows the AboutQt dialog"));
}

}

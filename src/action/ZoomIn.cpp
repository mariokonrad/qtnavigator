#include "ZoomIn.hpp"

namespace action {

ZoomIn::ZoomIn(QObject* parent)
	: QAction(parent)
{
	setText(tr("Zoom In"));
	setStatusTip(tr("Zooms in"));
}

}


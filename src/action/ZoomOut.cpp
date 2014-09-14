#include "ZoomOut.hpp"

namespace action {

ZoomOut::ZoomOut(QObject* parent)
	: QAction(parent)
{
	setText(tr("Zoom Out"));
	setStatusTip(tr("Zooms out"));
}

}


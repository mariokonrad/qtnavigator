#include "About.hpp"

namespace action {

About::About(QObject* parent)
	: QAction(parent)
{
	setText(tr("About"));
	setStatusTip(tr("Shows the About dialog"));
}

}

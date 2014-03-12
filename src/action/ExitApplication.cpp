#include "ExitApplication.hpp"

namespace action {

ExitApplication::ExitApplication(QObject* parent)
	: QAction(parent)
{
	setText(tr("E&xit"));
	setStatusTip(tr("Closes the application"));
}

}

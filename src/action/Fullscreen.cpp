#include "Fullscreen.hpp"
#include <QDebug>

namespace action {

Fullscreen::Fullscreen(QObject* parent)
	: QAction(parent)
{
	setCheckable(true);
	setChecked(false);
	setText(tr("Fullscreen"));
	setStatusTip(tr("Shows the window in fullscreen"));
	connect(this, SIGNAL(triggered()), SLOT(on_change()));
}

void Fullscreen::on_change()
{
	qDebug() << __PRETTY_FUNCTION__ << ": " << isChecked();
	if (isChecked()) {
		emit showFullScreen();
	} else {
		emit showNormal();
	}
}

}


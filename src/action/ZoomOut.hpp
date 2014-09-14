#ifndef __ACTION__ZOOMOUT__HPP__
#define __ACTION__ZOOMOUT__HPP__

#include <QAction>

namespace action {

class ZoomOut : public QAction
{
	Q_OBJECT

public:
	ZoomOut(QObject* parent);
};

}

#endif

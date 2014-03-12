#ifndef __ACTION__EXITAPPLICATION__HPP__
#define __ACTION__EXITAPPLICATION__HPP__

#include <QAction>

namespace action {

class ExitApplication : public QAction
{
public:
	ExitApplication(QObject* parent);
};

}

#endif

#ifndef __PLUGINS__PLUGIN__HPP__
#define __PLUGINS__PLUGIN__HPP__

#include <QtCore/QString>
#include <QtCore/QObject>

namespace plugins {

class Plugin
{
public:
	virtual ~Plugin()
	{
	}

	virtual QString name() const = 0;
	virtual void setup() = 0;
	virtual void cleanup() = 0;
};

}

Q_DECLARE_INTERFACE(plugins::Plugin, "qttmp.PluginInterface/0.1")

#endif

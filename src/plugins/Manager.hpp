#ifndef __PLUGINS__MANAGER__HPP__
#define __PLUGINS__MANAGER__HPP__

class QString;

namespace plugins {

class Manager
{
public:
	virtual ~Manager() {}

	virtual void load(const QString& plugin_path) = 0;
	virtual void unload() = 0;
};

}

#endif

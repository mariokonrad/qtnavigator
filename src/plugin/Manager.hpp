#ifndef __PLUGIN__MANAGER__HPP__
#define __PLUGIN__MANAGER__HPP__

class QString;

namespace plugin {

class Manager
{
public:
	virtual ~Manager() {}

	virtual void load(const QString& plugin_path) = 0;
	virtual void unload() = 0;
};

}

#endif

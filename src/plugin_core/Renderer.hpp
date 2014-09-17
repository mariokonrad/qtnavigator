#ifndef __PLUGIN_CORE__RENDERER__HPP__
#define __PLUGIN_CORE__RENDERER__HPP__

class QPainter;

namespace plugin {

/// Interface for all plugin renderers. This has no direct link to the
/// chart renderers, because of dependencies and plugin renderers shall
/// be more general than chart renderers.
class Renderer
{
public:
	virtual ~Renderer() {}

	virtual void render(QPainter&) const = 0; // TODO: add context
};

}

#endif

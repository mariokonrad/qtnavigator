#include "TestPlugin.hpp"
#include <QDebug>

namespace plugins {
namespace testplugin {

TestPlugin::TestPlugin()
{
	qDebug() << __PRETTY_FUNCTION__;
	::plugin::test_dump();
}

TestPlugin::~TestPlugin()
{
	qDebug() << __PRETTY_FUNCTION__;
}

QString TestPlugin::name() const
{
	return QString("TestPlugin/0.1");
}

void TestPlugin::setup()
{
	qDebug() << __PRETTY_FUNCTION__;
}

void TestPlugin::cleanup()
{
	qDebug() << __PRETTY_FUNCTION__;
}

}}

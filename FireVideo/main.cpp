#include <QtWidgets/QApplication>
#include "FireVideo.h"
#include<qdebug.h>

int main(int argc, char *argv[])
{
	QApplication::addLibraryPath("./plugins");
	QApplication app(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	FireVideo *FV = nullptr;
	FV = new FireVideo;
	FV->show();
	return app.exec();
}

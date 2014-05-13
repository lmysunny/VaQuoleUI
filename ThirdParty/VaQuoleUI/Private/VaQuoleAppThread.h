// Copyright 2014 Vladimir Alyamkin. All Rights Reserved.

#ifndef VAQUOLEAPPTHREAD_H
#define VAQUOLEAPPTHREAD_H

#include "VaQuolePublicPCH.h"

#include <QThread>

class QApplication;
class QWebView;
class VaQuoleWebView;

class VaQuoleAppThread : public QThread
{
	Q_OBJECT

public:
	explicit VaQuoleAppThread(QObject *parent = 0);
	~VaQuoleAppThread();

	void stopThread();

	void createView(int w = 256, int h = 256);
	void closeView();

	void openURL(const QString& NewURL);

	void setTransparent(bool transparent = true);
	void resize(int w, int h);

	const uchar * grabView();

protected:
	void run();

private:
	/** Main Qt class object */
	QApplication* pApp;

	/** Web page renderer */
	VaQuoleWebView *View;

};

#endif // VAQUOLEAPPTHREAD_H

/****************************************************************************
** $Id: qt/examples/httpd/httpd.cpp   2.3.2   edited 2001-07-10 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "httpd.h"
#include "httpinfo.h"

HttpDaemon::HttpDaemon(QObject *parent) : QServerSocket(8080, 1, parent)
{
	if (!ok()) {
		qWarning("Failed to bind to port 8080");
		exit(1);
	}
}

void HttpDaemon::newConnection(int socket)
{
	QSocket *s = new QSocket(this);
	connect(s, SIGNAL(readyRead()), this, SLOT(readClient()));
	connect(s, SIGNAL(delayedCloseFinished()), this, SLOT(discardClient()));
	s->setSocket(socket);
	emit newConnect();
}

void HttpDaemon::readClient()
{
	QSocket *socket = (QSocket *)sender();
	if (socket->canReadLine()) {
		QStringList tokens = QStringList::split(
			QRegExp("[ \n\r][ \n\r]*"), socket->readLine());
		if (tokens[0] == "GET") {
			QTextStream os(socket);
			os << "<h1>Nothing to see here</h1>\n";
			socket->close();
			emit wroteToClient();
		}
	}
}
void HttpDaemon::discardClient()
{
	QSocket *socket = (QSocket *)sender();
	delete socket;
	emit endConnect();
}

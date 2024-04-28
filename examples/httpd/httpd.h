#pragma once

#include <qserversocket.h>
#include <qapplication.h>
#include <qmainwindow.h>
#include <qtextstream.h>
#include <qvbox.h>
#include <qlabel.h>
#include <qtextview.h>
#include <qpushbutton.h>
#include <stdlib.h>

class HttpDaemon : public QServerSocket
{
    Q_OBJECT
public:
    HttpDaemon(QObject *parent = 0);
    void newConnection(int socket);

signals:
    void newConnect();
    void endConnect();
    void wroteToClient();

private slots:
    void readClient();
    void discardClient();
};
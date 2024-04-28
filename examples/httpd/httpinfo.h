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

#include "httpd.h"

class HttpInfo : public QVBox
{
    Q_OBJECT
public:
    HttpInfo();
    ~HttpInfo();

private slots:
    void newConnect();
    void endConnect();
    void wroteToClient();

private:
    QTextView *infoText;
};
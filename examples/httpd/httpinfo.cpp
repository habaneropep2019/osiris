#include "httpinfo.h"

HttpInfo::HttpInfo()
{
    HttpDaemon *httpd = new HttpDaemon(this);

    QString itext = QString(
                        "This is a small httpd example.\n"
                        "You can connect with your\n"
                        "web browser to port %1")
                        .arg(httpd->port());
    QLabel *lb = new QLabel(itext, this);
    lb->setAlignment(AlignHCenter);
    infoText = new QTextView(this);
    QPushButton *quit = new QPushButton("quit", this);

    connect(httpd, SIGNAL(newConnect()), SLOT(newConnect()));
    connect(httpd, SIGNAL(endConnect()), SLOT(endConnect()));
    connect(httpd, SIGNAL(wroteToClient()), SLOT(wroteToClient()));
    connect(quit, SIGNAL(pressed()), qApp, SLOT(quit()));
}

HttpInfo::~HttpInfo()
{
}

void HttpInfo::newConnect()
{
    infoText->append("New connection");
}
void HttpInfo::endConnect()
{
    infoText->append("Connection closed");
}
void HttpInfo::wroteToClient()
{
    infoText->append("Wrote to client");
}

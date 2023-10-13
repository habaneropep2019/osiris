/****************************************************************************
** $Id: qdns.h,v 2.2 1999/06/03 01:42:01 hanord Exp $
**
** Definition of something or other
**
** Created : 979899
**
** Copyright (C) 1997 by Troll Tech AS.  All rights reserved.
**
****************************************************************************/

#ifndef QDNS_H
#define QDNS_H

#include "qobject.h"


class Q_EXPORT QDns: public QObject
{
    Q_OBJECT
public:
    QDns( QObject  );

    void setName( const QString & name );
    QString name();

    // insert a method to get the IP address list associated with the
    // list.  This is generally 0 or 1, but can be more - www.vg.no
    // has two.

    void query( QObject * receiver, const char * slot );

    enum Status { Ready, Waiting, Error, Nonexistent };
    Status status() const;

signals:
    void statusChanged();

private:
    
};


#endif

/****************************************************************************
** $Id: qt/examples/aclock/main.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "aclock.h"
#include <qapplication.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include "qvaluestack.h"
#include <iostream>
using namespace std;

void test1(){
   std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int x;
    while( !st.empty() ){
       x = st.top();
       printf("Int: %d\n",x);
       st.pop();
    }
}

void test3(){
   QValueStack<QString> st2;
    st2.push("111111");
    st2.push("222222");
    st2.push("333333");
    st2.push("444444");
    st2.push("555555");
    int c=0;
    while( !st2.isEmpty() ){
       //st2.pop2();
       QString qs  = st2.pop2();
       cout << qs.latin1() << "\n";
       //printf("Qstrs: %d\n",c++);
    }

}

void test2(){
   QValueStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int c=0;
    while( !st.isEmpty() ){
       int x = st.pop2();
       printf("Ints: %d\n",x);
    }
}


int main( int argc, char **argv )
{
   //emit message( "Printing completed", 2000 );
   test1();
   test2();
   test3();
    
   /*
    QApplication a( argc, argv );
    AnalogClock *clock = new AnalogClock;
    if ( argc == 2 && strcmp( argv[1], "-transparent" ) == 0 )
	clock->setAutoMask( TRUE );
    clock->resize( 100, 100 ); 

    a.setMainWidget( clock );
    clock->setCaption("Qt Example - Analog Clock");
    clock->show();
    int result = a.exec();
    delete clock;
    return result;
   */
}  // main


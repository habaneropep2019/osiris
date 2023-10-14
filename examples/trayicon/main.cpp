/* XPM */
static char *up_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 46 1",
"  c #16163636ebeb",
". c #17173a3aecec",
"X c #1a1a3f3ff3f3",
"o c #1b1b4343fefe",
"O c #3f3f5656d1d1",
"+ c #2b2b5c5cffff",
"@ c #31315f5fffff",
"# c #36366767fefe",
"$ c #3b3b6666ffff",
"% c #3f3f6e6effff",
"& c #69697b7bb8b8",
"* c #4d4d6565cccc",
"= c #51516c6ccece",
"- c #55557272cece",
"; c #58587171c7c7",
": c #42426d6deded",
"> c #47477777ffff",
", c #4a4a7a7affff",
"< c #64647b7bc0c0",
"1 c #72728787bbbb",
"2 c #50508585ffff",
"3 c #5c5c8a8af7f7",
"4 c #6a6a8989d7d7",
"5 c #60608e8effff",
"6 c #66669797ffff",
"7 c #67679898ffff",
"8 c #6a6a9b9bf4f4",
"9 c #6e6e9e9effff",
"0 c #7676a7a7ffff",
"q c #7777a9a9ffff",
"w c #7878a1a1f7f7",
"e c #7e7eafafffff",
"r c #8989bdbdffff",
"t c #9090c6c6ffff",
"y c #9696ccccffff",
"u c #9999c9c9f9f9",
"i c #9d9dd1d1ffff",
"p c #b2b2c6c6f4f4",
"a c #bfbfe6e6fefe",
"s c #c0c0c0c0c0c0",
"d c #d1d1e0e0fcfc",
"f c #dbdbf9f9ffff",
"g c #e4e4ebebfcfc",
"h c #e7e7ffffffff",
"j c Gray100",
"k c None",
/* pixels */
"kkkkkk1pw1kkkkkk",
"kkkkk1gfi>;kkkkk",
"kkkk1ghure>&kkkk",
"kkk1ghte009@<kkk",
"kk1jhr009999#&kk",
"k1dhy00999999+&k",
"k4auq09999763$.k",
"k1k1k1>99$*kw11k",
"kkkkkk:q7o1kkkkk",
"kkkkkk3e6+1kkkkk",
"kkkkk18e9@;kkkkk",
"kkkkk1eq6$Okkkkk",
"kkkkk1r06>.kkkkk",
"kkkkk4e65,.kkkkk",
"kkkkk-2%##X1kkkk",
"kkkkk1... =kkkkk"
};


/* XPM */
static char *down_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 49 1",
"  c #06062d2dffff",
". c #08082e2effff",
"X c #1b1b3f3ff1f1",
"o c #3d3d4e4ebbbb",
"O c #2f2f5050e1e1",
"+ c #26265151fbfb",
"@ c #2b2b5959fefe",
"# c #31315454e2e2",
"$ c #37375e5ef3f3",
"% c #3c3c6565eeee",
"& c #3a3a6565ffff",
"* c #44445b5bc2c2",
"= c #48486060c5c5",
"- c #50506f6fcccc",
"; c #47477575ffff",
": c #4d4d7d7dffff",
"> c #53537c7cebeb",
", c #6c6c8484baba",
"< c #6e6e8787c7c7",
"1 c #6b6b9292e2e2",
"2 c #65659797ffff",
"3 c #6c6c9d9dffff",
"4 c #6c6ca1a1ffff",
"5 c #7e7ea2a2eaea",
"6 c #7676a6a6fefe",
"7 c #7f7fafafffff",
"8 c #8f8f9999b7b7",
"9 c #9f9fa2a2b3b3",
"0 c #8e8e9e9ec0c0",
"q c #8282a9a9e8e8",
"w c #8787b7b7ffff",
"e c #8787b8b8ffff",
"r c #8e8ebebeffff",
"t c #a4a4b4b4cdcd",
"y c #a6a6babaecec",
"u c #9797c8c8ffff",
"i c #9d9dceceffff",
"p c #9f9fd3d3ffff",
"a c #a2a2cecef6f6",
"s c #a2a2d1d1ffff",
"d c #b2b2c9c9eeee",
"f c #b9b9cacaeeee",
"g c #babad6d6f8f8",
"h c #b5b5ebebffff",
"j c #c0c0c0c0c0c0",
"k c #dadafafaffff",
"l c #e1e1fafaffff",
"z c #f6f6ffffffff",
"x c None",
/* pixels */
"xxxxx9yfdq8xxxxx",
"xxxxx5zlks#9xxxx",
"xxxxt1hpu2Oxxxxx",
"xxxxx<uir:otxxxx",
"xxxxx0wuw;-xxxxx",
"xxxxx8wuw&,xxxxx",
"xxxxxt5u7$9xxxxx",
"xxxxxtqi7$9xxxxx",
"xtxxx8aiw:,txxtx",
"x<agywrwww655>*x",
"x,%4eeww7w76& -x",
"xx,@3www776;.=9x",
"xxx,@37766: otxx",
"xxxx,+262; o9xxx",
"xxxxx,+::.otxxxx",
"xxxxxx<OX-9xxxxx"
};

#include "trayicon.h"

#include <qapplication.h>
#include <qpixmap.h>
#include <qpopupmenu.h>
#include <qmainwindow.h>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QMainWindow mw;
    app.setMainWidget( &mw );

    QPopupMenu menu;
    menu.insertItem( "Test 1" );
    menu.insertSeparator();
    menu.insertItem( "&Quit", &app, SLOT(quit()) );
    TrayIcon tray( QPixmap( (const char**)up_xpm ), "Show MainWindow", &menu );
    QObject::connect(&tray,SIGNAL(clicked(const QPoint&)),&mw,SLOT(show()));

    QPopupMenu menu2;
    menu2.insertItem( "Test 2" );
    TrayIcon tray2( QPixmap( (const char**)down_xpm ), "Hide MainWindow", &menu );
    QObject::connect(&tray2,SIGNAL(clicked(const QPoint&)),&mw,SLOT(hide()));

    mw.show();
    tray.show();
    tray2.show();

    return app.exec();
}

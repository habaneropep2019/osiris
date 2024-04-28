#include "listendnd.h"

ListenDND::ListenDND(QWidget *w)
    : view(w)
{
}

void ListenDND::dropped(QDropEvent *mime)
{
    printf("Dropped Mimesource %p into the view %p\n", mime, view);
    printf("  Formats:\n");
    int i = 0;
    const char *str = mime->format(i);
    printf("    %s\n", str);
    while (str)
    {
        printf("    %s\n", str);
        str = mime->format(++i);
    }
}

void ListenDND::moved()
{
    printf("All selected items were moved to another widget\n");
}

#include <qapplication.h>

#include <cstdio>
#include "dir.h"

int main(int argc, char **argv)
{
    QFileDialog::Mode mode = QFileDialog::ExistingFile;
    QString start;
    QString filter;
    QString caption;
    bool preview = FALSE;
    bool custom = FALSE;
    QApplication a(argc, argv);
    for (int i = 1; i < argc; i++)
    {
        QString arg = argv[i];
        if (arg == "-any")
            mode = QFileDialog::AnyFile;
        else if (arg == "-dir")
            mode = QFileDialog::Directory;
        else if (arg == "-default")
            start = argv[++i];
        else if (arg == "-filter")
            filter = argv[++i];
        else if (arg == "-preview")
            preview = TRUE;
        else if (arg == "-custom")
            custom = TRUE;
        else if (arg[0] == '-')
        {
            qDebug("Usage: qdir [-any | -dir | -custom] [-preview] [-default f] {-filter f} [caption ...]\n"
                   "      -any         Get any filename, need not exist.\n"
                   "      -dir         Return a directory rather than a file.\n"
                   "      -custom      Opens a customized QFileDialog with \n"
                   "                   dir browser, bookmark menu, etc.\n"
                   "      -preview     Show a preview widget.\n"
                   "      -default f   Start from directory/file f.\n"
                   "      -filter f    eg. '*.gif' '*.bmp'\n"
                   "      caption ...  Caption for dialog.\n");
            return 1;
        }
        else
        {
            if (!caption.isNull())
                caption += ' ';
            caption += arg;
        }
    }

    if (!start)
        start = QDir::currentDirPath();

    if (!caption)
        caption = mode == QFileDialog::Directory
                      ? "Choose directory..."
                      : "Choose file...";

    if (!custom)
    {
        QFileDialog fd(QString::null, filter, 0, 0, TRUE);
        fd.setMode(mode);
        if (preview)
        {
            fd.setContentsPreviewEnabled(TRUE);
            PreviewWidget *pw = new PreviewWidget(&fd);
            fd.setContentsPreview(pw, pw);
            fd.setViewMode(QFileDialog::List);
            fd.setPreviewMode(QFileDialog::Contents);
        }
        fd.setCaption(caption);
        fd.setSelection(start);
        if (fd.exec() == QDialog::Accepted)
        {
            QString result = fd.selectedFile();
            printf("%s\n", (const char *)result);
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        CustomFileDialog fd;
        fd.exec();
        return 1;
    }
}

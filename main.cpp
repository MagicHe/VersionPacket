#include "frmmain.h"
#include <QApplication>
#include "api/appinit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppInit *initApp = new AppInit;
    initApp->loadInfo();
    FrmMain w;
    w.show();
    return a.exec();
}

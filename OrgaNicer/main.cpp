#include "organicer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrgaNicer w;
    w.show();
    return a.exec();
}

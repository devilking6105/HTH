#include "treewidgetbutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeWidgetButton w;
    w.show();

    return a.exec();
}

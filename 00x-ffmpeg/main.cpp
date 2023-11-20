#include <QApplication>
#include <QPushButton>
#include <QtLogging>
#include <QDebug>

#include "MainWindow.h"

extern "C" {
#include <libavcodec/avcodec.h>
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow m;
    m.show();
    return QApplication::exec();
}

#include "cjlu_usart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cjlu_usart w;
    w.show();

    return a.exec();
}

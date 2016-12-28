#include "fenetre.h"  
#include <QApplication>
#include <QtWidgets>
using namespace std ;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    fenetre w;

    w.show();

    return app.exec();
}

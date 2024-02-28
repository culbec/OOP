#include <QApplication>
#include "Tester.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    Tester::testAll();

    Repository repository{"tractoare.txt"};
    Service service{repository};
    GUI gui{service};

    gui.show();

    return QApplication::exec();
}

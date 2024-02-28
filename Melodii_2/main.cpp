#include <QApplication>
#include "./headers/tester.h"
#include "./headers/GUI.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    Tester::testAll();

    Repository repository{"melodii_2.txt"};
    Service service{repository};
    GUI gui{service};

    gui.show();

    return QApplication::exec();
}

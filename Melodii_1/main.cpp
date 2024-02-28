#include <QApplication>
#include "./headers/tester.h"
#include "./headers/GUI.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    /*Tester tester;
    tester.testAll();*/

    Repository repository{"melodii_1.txt"};
    Service service{repository};

    GUI gui{service};

    gui.show();

    return QApplication::exec();
}

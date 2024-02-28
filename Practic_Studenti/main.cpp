#include <QApplication>
#include "./headers/Tester.h"
#include "./headers/GUI.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    Tester::testAll();

    Repository repository{"studenti.txt"};
    Service service{repository};
    GUI gui{service};

    gui.show();

    return QApplication::exec();
}

cmake_minimum_required(VERSION 3.25)
project(produse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/culbec/Qt/6.5.0/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(produse main.cpp headers/produs.h sources/produs.cpp headers/tester.h sources/tester.cpp headers/repo.h sources/repo.cpp headers/service.h sources/service.cpp headers/GUI.h headers/Observer.h headers/Observable.h headers/TableModel.h sources/GUI.cpp)
target_link_libraries(produse
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


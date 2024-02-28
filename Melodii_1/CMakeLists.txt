cmake_minimum_required(VERSION 3.25)
project(melodii_1)

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

add_executable(melodii_1 main.cpp headers/melodie.h sources/melodie.cpp headers/tester.h sources/tester.cpp headers/repository.h sources/repository.cpp headers/service.h sources/service.cpp headers/GUI.h headers/TableModel.h headers/Observer.h headers/Observable.h sources/GUI.cpp)
target_link_libraries(melodii_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


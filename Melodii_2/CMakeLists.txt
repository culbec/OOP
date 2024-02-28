cmake_minimum_required(VERSION 3.25)
project(melodii_2)

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

add_executable(melodii_2 main.cpp headers/melodie.h sources/melodie.cpp headers/repo.h headers/service.h headers/tester.h sources/repo.cpp sources/service.cpp sources/tester.cpp headers/GUI.h headers/model.h sources/GUI.cpp)
target_link_libraries(melodii_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


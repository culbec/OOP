cmake_minimum_required(VERSION 3.25)
project(tractoare)

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

add_executable(tractoare main.cpp Tractor.cpp Tractor.h Tester.cpp Tester.h Repository.cpp Repository.h Service.cpp Service.h GUI.cpp GUI.h Model.cpp Model.h)
target_link_libraries(tractoare
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


cmake_minimum_required(VERSION 3.25)
project(practic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/culbec/Qt/6.5.0/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(practic main.cpp headers/Student.h sources/Student.cpp headers/Tester.h sources/Tester.cpp headers/Repository.h sources/Repository.cpp headers/Service.h sources/Service.cpp headers/Undo_Redo.h sources/Undo_Redo.cpp headers/GUI.h headers/Model.h sources/GUI.cpp)
target_link_libraries(practic
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


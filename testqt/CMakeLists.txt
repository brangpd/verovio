project(testqtvrv)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(
    ../include/vrv
    ../include/json
    ../include/zip
    ../include/hum
    ../include/midi
    ../include/utf8
    include/vrv ../libmei)
add_executable(qttest qttest.cpp src/qtpainterdevicecontext.cpp
    MainWindow.cpp MainWindow.h MainWindow.ui)
target_link_libraries(qttest PUBLIC Qt5::Widgets verovio)

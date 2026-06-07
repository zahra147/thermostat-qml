cmake_minimum_required(VERSION 3.16)
project(cloudTest1 VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Network)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appcloudTest1
    main.cpp
)

qt_add_qml_module(appcloudTest1
    URI cloudTest1
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES thermostatbackend.h thermostatbackend.cpp
        SOURCES weatherservice.h weatherservice.cpp
        SOURCES config.h
)

set_target_properties(appcloudTest1 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcloudTest1
    PRIVATE Qt6::Quick Qt6::Network
)
target_link_libraries(appcloudTest1 PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appcloudTest1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

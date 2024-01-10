cmake_minimum_required(VERSION 3.14)
project(fit_application)

# Укажите использование Qt5 или Qt6 в зависимости от вашей версии Qt
set(QT_VERSION 6)
# Укажите компоненты Qt, которые вы используете
set(REQUIRED_LIBS Core Gui Widgets Sql)
# Укажите минимальную версию Qt
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включите здесь исходные файлы вашего проекта
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        schedule.cpp
        sets.cpp
        calendaractivity.cpp
        mainwindow.ui
        schedule.ui
        sets.ui
        calendaractivity.ui
)

if(${QT_VERSION} EQUAL 6)
    qt_add_executable(fit_application
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET fit_application APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

else()
    if(ANDROID)
        add_library(fit_application SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(fit_application
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(fit_application PRIVATE ${REQUIRED_LIBS_QUALIFIED})

set_target_properties(fit_application PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION EQUAL 6)
    qt_finalize_executable(fit_application)
endif()

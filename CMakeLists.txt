cmake_minimum_required(VERSION 3.8)

project(ft_retro)

set(CMAKE_CXX_STANDARD 98)

set(MODELS_SOURCES_FILES
        src/model/Unit.cpp
        src/model/Unit.hpp
        src/model/Object.hpp
        src/model/Object.cpp
        src/model/INcursesView.hpp
        src/model/Player.cpp
        src/model/Player.hpp
        src/model/Position.cpp
        src/model/Position.hpp
        src/model/Simbol.cpp
        src/model/Simbol.hpp
        src/model/Size.cpp
        src/model/Size.hpp
        )

set(UTILS_SOURCES_FILES
        src/utils/List.hpp
        src/utils/ListNode.hpp
        )

set(CORE_SOURCES_FILES
        src/core/Application.cpp
        src/core/Application.hpp
        src/core/TickRate.cpp
        src/core/TickRate.hpp
        )

set(SOURCE_FILES src/main.cpp src/control/IController.hpp src/control/BaseController.cpp src/control/BaseController.hpp src/control/ExitController.cpp src/control/ExitController.hpp src/utils/IIterrator.hpp)

add_executable(ft_retro ${MODELS_SOURCES_FILES}
        ${UTILS_SOURCES_FILES}
        ${CORE_SOURCES_FILES}
        ${SOURCE_FILES}
        )

target_link_libraries(ft_retro ncurses)
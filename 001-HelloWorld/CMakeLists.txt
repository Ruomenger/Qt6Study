set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(001-HelloWorld
        main.cpp
)

target_link_libraries(001-HelloWorld
        PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    message(STATUS "${CMAKE_TOOLCHAIN_FILE}")
    cmake_path(GET CMAKE_TOOLCHAIN_FILE PARENT_PATH BUILDSYSTEMS_PATH)
    cmake_path(GET BUILDSYSTEMS_PATH PARENT_PATH SCRIPTS_PATH)
    cmake_path(GET SCRIPTS_PATH PARENT_PATH VCPKG_ROOT)
    message(STATUS "${VCPKG_ROOT}")
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        cmake_path(APPEND VCPKG_ROOT "installed" "x64-windows")
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
        cmake_path(APPEND VCPKG_ROOT "installed" "x86-windows")
    endif ()
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        cmake_path(APPEND VCPKG_ROOT "debug")
    endif ()
    cmake_path(APPEND VCPKG_ROOT "Qt6" "plugins" "platforms")
    message(STATUS "${VCPKG_ROOT}")
    message(STATUS "${CMAKE_CURRENT_BINARY_DIR}")
    if (EXISTS "${VCPKG_ROOT}")
        file(COPY "${VCPKG_ROOT}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
    endif ()
endif ()

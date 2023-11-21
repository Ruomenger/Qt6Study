project(002x_sdl2)

find_package(SDL2 CONFIG REQUIRED)

add_executable(002x_sdl2
        main.cpp
)

target_link_libraries(002x_sdl2
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

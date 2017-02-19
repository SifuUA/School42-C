cmake_minimum_required(VERSION 3.6)
project(PushSwap)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES push_swap/main.c push_swap/author push_swap/cheker.c)

include_directories("../libft")
link_directories("../libft/cmake-build-debug")

add_executable(PushSwap ${SOURCE_FILES})
target_link_libraries(PushSwap ft)
cmake_minimum_required(VERSION 3.6)
project(PushSwap)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES push_swap/main.c push_swap/author push_swap/push_swap.h push_swap/sa_sb_ss.c push_swap/pa_pb.c push_swap/ft_intarr_len.c push_swap/creat_list.c)

include_directories("../libft")
link_directories("../libft/cmake-build-debug")

add_executable(PushSwap ${SOURCE_FILES})
target_link_libraries(PushSwap ft)
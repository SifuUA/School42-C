cmake_minimum_required(VERSION 3.6)
project(PushSwap)


set(MY_LIB C:/Users/Alex/CLionProjects/School42-C/libft/libft.a)
set(SOURCE_FILES push_swap/main.c push_swap/put.c push_swap/ra_rb.c push_swap/rra_rrb_rrr.c.c)
add_executable(PushSwap ${SOURCE_FILES})
target_link_libraries(PushSwap ${MY_LIB})
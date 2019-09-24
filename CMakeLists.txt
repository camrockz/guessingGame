cmake_minimum_required(VERSION 3.0)

project(guessinggame LANGUAGES C)

add_executable(guessinggame main.c)

install(TARGETS guessinggame RUNTIME DESTINATION bin)

target_link_libraries(guessinggame m)

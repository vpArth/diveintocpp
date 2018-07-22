include_directories(../include)
set(core_SRCS
        ../include/A.h A.cpp
        )

add_library(core ${core_SRCS})
#add_executable(exe main.cpp)

target_link_libraries(core)
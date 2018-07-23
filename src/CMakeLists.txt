include_directories(../include)

file(GLOB core_SRCS
        "*.cpp"
        "../include/*.h"
        "../include/*.hpp"
        )

add_library(core ${core_SRCS})

target_link_libraries(core)
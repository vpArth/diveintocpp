include_directories(../include)

file(GLOB core_SRCS
        "**/*.cpp"
        "../include/**/*.h"
        "../include/**/*.hpp"
        )

add_library(core ${core_SRCS})
add_executable(PT_FM "../patterns/creational/FactoryMethod.cpp")
add_executable(PT_AF "../patterns/creational/AbstractFactory.cpp")
add_executable(PT_BD "../patterns/creational/Builder.cpp")
add_executable(PT_AD "../patterns/structural/Adapter.cpp")
add_executable(PT_BG "../patterns/structural/Bridge.cpp"
        "../patterns/structural/logger/Logger.cpp"
        "../patterns/structural/logger/LoggerImpl.cpp"
        )

target_link_libraries(core)
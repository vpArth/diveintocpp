cmake_minimum_required(VERSION 3.3)

set(REPO ${PROJECT_SOURCE_DIR}/vendor)

project(Test)

project(Example)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else ()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif ()

download_project(
        PROJ googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

include_directories(../include)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

file(GLOB test_SRCS "*.test.cpp"
        )

add_executable(runUnitTests gtest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
#add_test(runUnitTests runUnitTests COMMAND runUnitTests)
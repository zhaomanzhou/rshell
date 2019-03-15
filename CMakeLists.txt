CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Command.cpp
    src/Lexical.cpp
    src/Connector.h
    src/Connector.cpp

)

ADD_EXECUTABLE(test
    unit_tests/Test.cpp
    src/Command.h
    src/Command.cpp
    src/Lexical.cpp
    src/Connector.h
    src/Connector.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

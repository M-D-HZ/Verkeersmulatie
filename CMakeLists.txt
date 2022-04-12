cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES src/VerkeerTests.cpp src/DesignByContract.cpp src/DesignByContract.h src/VoertuigGenerator.cpp src/VoertuigGenerator.h src/Voertuig.cpp src/Voertuig.h src/VerkeersLicht.cpp
        src/VerkeersLicht.h src/Baan.cpp src/Baan.h src/ReadFile.cpp src/ReadFile.h src/VerkeerSituatie.cpp src/VerkeerSituatie.h
        src/main.cpp tinyxml/tinystr.h tinyxml/tinyxml.h tinyxml/tinystr.cpp tinyxml/tinyxml.cpp tinyxml/tinyxmlerror.cpp
        tinyxml/tinyxmlparser.cpp)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES src/VoertuigGenerator.cpp src/VoertuigGenerator.h src/Voertuig.cpp src/Voertuig.h src/VerkeersLicht.cpp
        src/VerkeersLicht.h src/Baan.cpp src/Baan.h src/ReadFile.cpp src/ReadFile.h src/VerkeerSituatie.cpp src/VerkeerSituatie.h src/main.cpp
        tinyxml/tinystr.h tinyxml/tinyxml.h tinyxml/tinystr.cpp tinyxml/tinyxml.cpp tinyxml/tinyxmlerror.cpp
        tinyxml/tinyxmlparser.cpp)

# Create RELEASE target
add_executable(verkeer ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(verkeer_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(verkeer_debug gtest)
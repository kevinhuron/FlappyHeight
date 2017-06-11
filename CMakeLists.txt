cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Entities/PlayerCaracter.cpp headers/PlayerCaracter.hh Entities/Game.cpp headers/Game.hh Entities/Pipes.cpp headers/Pipes.hh Entities/Results.cpp headers/Results.hh Entities/Character.cpp headers/Character.hh Entities/AbstractEntity.cpp headers/AbstractEntity.hh Interfaces/IObserver.hh Interfaces/IObservable.hh Entities/TimeManager.cpp headers/TimeManager.hh Entities/ScoreScreen.cpp headers/ScoreScreen.hh Entities/OptionScreen.cpp headers/OptionScreen.hh Entities/MenuScreen.cpp headers/MenuScreen.hh Entities/Star.cpp headers/Star.hh Entities/Logs.cpp headers/Logs.hh)
add_executable(game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
## FIND SFML MODULE
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(game ${SFML_LIBRARIES})
endif()
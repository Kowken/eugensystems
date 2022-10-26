cmake_minimum_required(VERSION 3.23)
project(eugensystems)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Personnage/chevalier)
include_directories(Personnage/orc)

add_executable(eugensystems
        Personnage/chevalier/chevalier.cpp
        Personnage/chevalier/chevalier.h
        Personnage/orc/orc.cpp
        Personnage/orc/orc.h
        builder.h
        capacite.cpp
        combat.cpp
        compteureffet.cpp
        head.h
        main.cpp
        personnage.cpp
        setup.cpp
        setup.h)

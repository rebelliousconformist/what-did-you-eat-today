cmake_minimum_required(VERSION 3.10.0)
project(what-did-you-eat-today VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#main executable
add_executable(what-did-you-eat-today main.cpp 
    FileLogger.cpp 
    ConsoleLogger.cpp
    RecepieTree.cpp 
    Recepie.cpp)




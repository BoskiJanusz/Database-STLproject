cmake_minimum_required(VERSION 3.10)
project(database VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(SRC
    main.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
    Database.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
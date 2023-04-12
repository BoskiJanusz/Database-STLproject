cmake_minimum_required(VERSION 3.14)
project(database VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(SRC
    src/Person.cpp
    src/Student.cpp
    src/Employee.cpp
    src/Database.cpp
)

set(FLAGS -Wall -Wextra -Wpedantic -std=c++2a)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} ${SRC} src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

enable_testing()

add_executable(${PROJECT_NAME}-ut ${SRC} src/tests.cpp )
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

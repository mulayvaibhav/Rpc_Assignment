# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.16.3)

project(DREAM)

include_directories(
    include/Rpc/ClientRpc
    include/Rpc/ServerRpc
    include/Transport/ClientTransport
    include/Transport/ServerTransport
)

add_executable(DreamRpc 
    main.cpp 
    src/Rpc/ClientRpc/ClientRpc.cpp
    src/Rpc/ClientRpc/ClientDreamRpc.cpp)

# Link any necessary libraries (e.g., pthread for threading, networking libraries, etc.)
target_link_libraries(DreamRpc pthread)


# Optional: Set compiler warnings
if (MSVC)
    target_compile_options(DreamRpc PRIVATE /W4 /WX)
else()
    target_compile_options(DreamRpc PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Optional: Install target configuration
install(TARGETS DreamRpc DESTINATION bin)
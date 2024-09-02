# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.16.3)

project(DREAM)

include_directories(
    include/Rpc
    include/Transport
)

add_executable(DreamRpc 
    main.cpp 
    src/Rpc/ClientRpcInterface.cpp
    src/Rpc/ClientDreamRpc.cpp
    src/Transport/ClientTransportInterface.cpp
    src/Transport/ClientBadDreamHTTP.cpp)

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
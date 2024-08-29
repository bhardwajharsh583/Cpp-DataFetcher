cmake_minimum_required(VERSION 3.10)
project(JsonFetcher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the nlohmann JSON library
include_directories(${CMAKE_SOURCE_DIR}/nlohmann)

message(STATUS "Nlohmann include directory: ${CMAKE_SOURCE_DIR}/nlohmann")

# Link the curl library
find_library(CURL_LIB
  NAMES libcurl
  PATHS ${CMAKE_SOURCE_DIR}/curl_cpp/lib
)

include_directories(${CMAKE_SOURCE_DIR}/curl_cpp/include)
message(STATUS "curl include directory: ${CMAKE_SOURCE_DIR}/curl_cpp/include")


add_executable(JsonFetcher src/main.cpp)

# Link to the curl library
target_link_libraries(JsonFetcher PRIVATE ${CURL_LIB})

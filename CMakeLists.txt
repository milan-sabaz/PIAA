cmake_minimum_required(VERSION 3.20)
project(piaa_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    add_link_options(-static)
endif()

add_subdirectory(01-lzw-compression)
add_subdirectory(02-kmp-levenshtein)
add_executable(lzw
    src/main.cpp
    src/LZWCompressor.cpp
)
target_include_directories(lzw PRIVATE include)
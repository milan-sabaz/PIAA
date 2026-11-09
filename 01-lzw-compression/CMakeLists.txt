add_executable(lzw
     src/main.cpp
     src/lzw_compressor.cpp
)

add_executable(randomGen
    tools/random_gen.cpp)

add_executable(loremGen
    tools/lorem_gen.cpp)

target_include_directories(lzw PRIVATE include)
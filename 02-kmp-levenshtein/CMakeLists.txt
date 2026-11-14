add_executable(kmp_levenshtein
        src/kmp.cpp
        src/levenshtein.cpp
        src/main.cpp
)

add_executable(txtGen
    tools/textGenerator.cpp)
add_executable(hexGen
     tools/hexTextGenerator.cpp)

target_include_directories(kmp_levenshtein PRIVATE include)
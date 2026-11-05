//
// Created by milan on 30-Oct-26.
//

#ifndef PIAA_LAB_LZW_LZWCOMPRESSOR_H
#define PIAA_LAB_LZW_LZWCOMPRESSOR_H

#include <fstream>

class LZWCompressor {
public:
    static bool compress(std::ifstream& input, std::ofstream& output);
    static bool decompress(std::ifstream& input, std::ofstream& output);

    static bool compress(const std::string &inputFileName, const std::string &outputFileName);
    static bool decompress(const std::string &inputFileName, const std::string &outputFileName);
};


#endif //PIAA_LAB_LZW_LZWCOMPRESSOR_H
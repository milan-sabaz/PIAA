//
// Created by milan on 01-Nov-26.
//

#ifndef PIAA_LAB_LZW_CODEREADER_H
#define PIAA_LAB_LZW_CODEREADER_H

#include <cstdint>
#include <fstream>

using namespace std;

class CodeReader {
    istream& in;
    uint64_t buffer = 0;
    int count = 0;
public:
    CodeReader(istream& o) : in(o) {}
    int read(int codeLength) {
        //cita bitove dok nema dovoljno bitova u bafferu
        while (count < codeLength) {
            // in.get() vraca iskljucivo 0-255 ili -1 (EOF)
            int byte = in.get();
            if (byte == EOF) return -1;
            buffer = (buffer << 8) | byte;
            count += 8;
        }
        // (1 << codeLength)-1  pravi masku sa codeLength jedinica
        int code = static_cast<int>(buffer >> (count - codeLength)) & ((1 << codeLength) -1);
        count -= codeLength;

        //brise procitane bitove
        buffer = buffer & ((1ULL << count) - 1);
        return code;
    }
};

#endif //PIAA_LAB_LZW_CODEREADER_H
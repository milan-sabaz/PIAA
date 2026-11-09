//
// Created by milan on 01-Nov-26.
//

#ifndef PIAA_LAB_LZW_CODEWRITER_H
#define PIAA_LAB_LZW_CODEWRITER_H

#include <cstdint>
#include <fstream>

using namespace std;

class CodeWriter {
    ostream& out;
    uint64_t buffer = 0;
    int count = 0;
public:
    CodeWriter(ostream& o) : out(o) {}

    void write(int code, int codeLength) {
        // dodaje novi kod na LSB stranu buffera
        buffer = (buffer << codeLength) | code;
        count += codeLength;

        //dok ima bar 8 bitova, uzimamo ih sa MSB strane
        while (count >= 8) {
            out.put(static_cast<char>((buffer >> (count - 8)) & 0xFF));
            count -= 8;
        }
    }

    // upisuje zaostalih 0-7 bitova iz buffera (poziva se na kraju kodiranja)
    void upisiOstatak() {
        if (count > 0) {
            out.put(static_cast<char>((buffer << (8 - count)) & 0xFF));  // dopuni nulama
            count = 0;
        }
    }
};



#endif //PIAA_LAB_LZW_CODEWRITER_H
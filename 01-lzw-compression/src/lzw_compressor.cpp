//
// Created by milan on 31-Oct-26.
//

#include <unordered_map>
#include "lzw_compressor.h"
#include "code_writer.h"
#include "code_reader.h"

using namespace std;

//fiksna duzina koda
const int bits = 12;

bool LZWCompressor::compress(ifstream &input, ofstream &output) {
    if (!input.is_open() || !output.is_open()) return false;

    const int maxCodes = 1 << bits;

    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; i++)
        dictionary[string(1, static_cast<char>(i))] = i;

    int sledeciKod = 256;

    CodeWriter codeWriter(output);

    string w, wc;
    char c;

    while (input.get(c)) {
        wc = w + c;
        if (dictionary.contains(wc)) {
            w = wc;
        } else {
            codeWriter.write(dictionary[w], bits);

            if (sledeciKod >= maxCodes) {
                dictionary.clear();
                for (int i = 0; i < 256; i++)
                    dictionary[string(1, static_cast<char>(i))] = i;
                sledeciKod = 256;
            }
            dictionary[wc] = sledeciKod++;

            w = c;
        }
    }

    if (!w.empty())
        codeWriter.write(dictionary[w], bits);
    codeWriter.upisiOstatak();

    return output.good();

}

bool LZWCompressor::decompress(ifstream &input, ofstream &output) {
    if (!input.is_open() || !output.is_open()) return false;
    const int maxCodes = 1 << bits;

    unordered_map<int, string> dictionary;
    for (int i = 0; i < 256; i++)
        dictionary[i] = string(1, static_cast<char>(i));

    int sledeciKod = 256;

    CodeReader codeReader(input);

    string entry;
    int k = codeReader.read(bits);

    if (k == -1) return true;   // prazan fajl
    if (k >= 256) return false;     // ostecen ili nekompresovan fajl

    string w = dictionary[k];
    output << w;

    k = codeReader.read(bits);
    while (k != -1) {

        if (sledeciKod >= maxCodes) {
            dictionary.clear();
            for (int i = 0; i < 256; i++)
                dictionary[i] = string(1, static_cast<char>(i));
            sledeciKod = 256;
        }
        if (dictionary.contains(k)) {
            entry = dictionary[k];
        } else if (k == sledeciKod) {
            entry = w + w[0];
        } else {
            return false;
        }

        output << entry;

        dictionary[sledeciKod] = w + entry[0];
        sledeciKod++;

        w = entry;

        k = codeReader.read(bits);
    }

    return output.good();
}

bool LZWCompressor::compress(const string &inputFileName, const string &outputFileName) {
    ifstream input(inputFileName, ios::binary);
    if (!input.is_open())
        return false;

    ofstream output(outputFileName, ios::binary);
    if (!output.is_open())
        return false;

    bool ok = compress(input, output);

    input.close();
    output.close();

    return ok;
}

bool LZWCompressor::decompress(const string &inputFileName, const string &outputFileName) {
    ifstream input(inputFileName, ios::binary);
    if (!input.is_open())
        return false;

    ofstream output(outputFileName, ios::binary);
    if (!output.is_open())
        return false;

    bool ok = decompress(input, output);

    input.close();
    output.close();

    return ok;
}

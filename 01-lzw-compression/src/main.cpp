#include <iostream>
#include "LZWCompressor.h"

using namespace std;

static void printUsage(const char *prog) {
    cerr << "Upotreba:\n"
         << "  " << prog << " compress   <ulaz> <izlaz>\n"
         << "  " << prog << " decompress <ulaz> <izlaz>\n";
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return 1;
    }

    const string command = argv[1];
    const string inputFile = argv[2];
    const string outputFile = argv[3];

    bool ok;

    if (command == "compress") {
        ok = LZWCompressor::compress(inputFile, outputFile);
    } else if (command == "decompress") {
        ok = LZWCompressor::decompress(inputFile, outputFile);
    } else {
        cerr << "Nepoznata komanda: " << command << "\n";
        printUsage(argv[0]);
        return 1;
    }

    if (!ok) {
        cerr << "Greska: operacija nije uspela (proveri putanje i format fajla).\n";
        return 1;
    }

    cout << "Gotovo.\n";
    return 0;
}
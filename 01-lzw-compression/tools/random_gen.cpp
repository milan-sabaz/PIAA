//
// Created by milan on 08-Nov-26.
//
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>


bool generisiTxtFajlRandom(const std::string& imeFajla, long duzina) {
    if (duzina < 1) return false;

    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        ",.-;:(){}/";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, chars.size() - 1);

    std::string s;
    s.reserve(duzina);
    for (long i = 0; i < duzina; ++i)
        s.push_back(chars[dis(gen)]);

    std::ofstream file(imeFajla);
    if (!file.is_open()) return false;
    file << s;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Upotreba: " << argv[0] << " <imefajla.txt> <duzina>\n";
        return 1;
    }

    long duzina = std::strtol(argv[2], nullptr, 10);
    if (duzina < 1) {
        std::cerr << "Duzina mora biti pozitivan ceo broj.\n";
        return 1;
    }

    std::string imeIzlaza = argv[1];
    if (!generisiTxtFajlRandom(imeIzlaza, duzina)) {
        std::cerr << "Ne mogu da napravim fajl: " << imeIzlaza << "\n";
        return 1;
    }

    std::cout << "Generisano " << duzina << " random karaktera u fajl " << imeIzlaza << "\n";
    return 0;
}
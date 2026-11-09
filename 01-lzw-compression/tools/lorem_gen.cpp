//
// Created by milan on 08-Nov-26.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool generisiTxtFajlLorem(const std::string& imeFajla, long duzina) {
    if (duzina < 1) return false;

    const std::string lorem =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
        "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, "
        "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo "
        "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse "
        "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat "
        "non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. ";

    std::string s;
    s.reserve(duzina + lorem.size());
    while (s.size() < static_cast<size_t>(duzina)) {
        s += lorem;
    }
    s.resize(duzina);

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
    if (!generisiTxtFajlLorem(imeIzlaza, duzina)) {
        std::cerr << "Ne mogu da napravim fajl: " << imeIzlaza << "\n";
        return 1;
    }

    std::cout << "Generisano karaktera: " << duzina << " u fajl " << imeIzlaza << "\n";
    return 0;
}
//
// Created by milan on 06-Nov-26.
//

#include <iostream>
#include <fstream>
#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Upotreba: " << argv[0] << " <ulaz.txt> <N> <izlaz.txt>\n";
        return 1;
    }

    std::string imeFajla = argv[1];
    long n = std::strtol(argv[2], nullptr, 10);
    std::string imeIzlaza = argv[3];

    if (n < 0) {
        std::cerr << "N mora biti nenegativan broj.\n";
        return 1;
    }

    std::ifstream ulaz(imeFajla, std::ios::binary);

    if (!ulaz) {
        std::cerr << "Ne mogu da otvorim fajl: " << imeFajla << "\n";
        return 1;
    }

    std::ofstream izlaz(imeIzlaza, std::ios::binary);
    if (!izlaz) {
        std::cerr << "Ne mogu da napravim fajl: " << imeIzlaza << "\n";
        return 1;
    }

    std::string rec;
    long brojac = 0;
    while (brojac < n && ulaz >> rec) {
        if (brojac > 0)
            izlaz << ' ';
        izlaz << rec;
        brojac++;
    }
    izlaz << '\n';

    std::cout << "Upisano " << brojac << " reci u fajl " << imeIzlaza << "\n";
    return 0;
}
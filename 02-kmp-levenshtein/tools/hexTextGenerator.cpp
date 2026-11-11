//
// Created by milan on 06-Nov-26.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 5) {
        std::cerr << "Upotreba: " << argv[0]
                  << " <izlaz.txt> <N> [minDuzina] [maxDuzina]\n";
        return 1;
    }

    std::string imeIzlaza = argv[1];
    long n = std::strtol(argv[2], nullptr, 10);
    int minDuzina = (argc >= 4) ? std::atoi(argv[3]) : 1;
    int maxDuzina = (argc == 5) ? std::atoi(argv[4]) : 8;

    if (n < 0 || minDuzina < 1 || maxDuzina < minDuzina) {
        std::cerr << "Neispravni parametri.\n";
        return 1;
    }

    std::ofstream izlaz(imeIzlaza, std::ios::binary);
    if (!izlaz) {
        std::cerr << "Ne mogu da napravim fajl: " << imeIzlaza << "\n";
        return 1;
    }

    const char hex[] = "0123456789ABCDEF";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> cifra(0, 15);
    std::uniform_int_distribution<int> duzina(minDuzina, maxDuzina);

    for (long i = 0; i < n; ++i) {
        int d = duzina(gen);
        std::string rec;
        for (int j = 0; j < d; ++j) {
            rec += hex[cifra(gen)];
        }
        if (i > 0) izlaz << ' ';
        izlaz << rec;
    }
    izlaz << '\n';

    std::cout << "Upisano " << n << " hex reci u fajl " << imeIzlaza << "\n";
    return 0;
}
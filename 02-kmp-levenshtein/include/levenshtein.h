//
// Created by milan on 09-Nov-26.
//

#ifndef PIAA_LAB_LEVENSHTEIN_H
#define PIAA_LAB_LEVENSHTEIN_H
#include <string>
#include <vector>

int levenshteinDistance(const std::string& s1, const std::string& s2);
std::vector<int> levenshteinSearch(std::ifstream &file, const std::string& pattern);

#endif //PIAA_LAB_LEVENSHTEIN_H
//
// Created by milan on 08-Nov-26.
//

#ifndef PIAA_LAB_KMP_H
#define PIAA_LAB_KMP_H

#include <string>
#include <vector>
#include <fstream>

std::vector<int> computePrefixFunction(const std::string& pattern);
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern);
std::vector<int> kmpSearch(std::ifstream& file, const std::string& pattern);

#endif //PIAA_LAB_KMP_H
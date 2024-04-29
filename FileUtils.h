#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void addWrongWordsToFile(const vector<pair<string, vector<string>>>& wrongWordsWithSuggestions);
void updateStatistics(int& rightCount, int& wrongCount);
void printColored(const string& wd, const string& color);

#endif // FILE_UTILS_H

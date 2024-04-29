#include "FileUtils.h"

void addWrongWordsToFile(const vector<pair<string, vector<string>>>& wrongWordsWithSuggestions) {
    ofstream wrongWordsFile("wrong_words.txt", ios::app);
    if (wrongWordsFile.is_open()) {
        for (const auto& entry : wrongWordsWithSuggestions) {
            wrongWordsFile << entry.first << " Suggestions: ";
            for (const string& suggestion : entry.second) {
                wrongWordsFile << suggestion << " ";
            }
            wrongWordsFile << "\n";
        }
        wrongWordsFile.close();
    } else {
        cerr << "Unable to open the file for writing wrong words." << endl;
    }
}

void updateStatistics(int& rightCount, int& wrongCount) {
    ifstream statsFile("statistics.txt");
    if (statsFile.is_open()) {
        // Read existing statistics
        string line;
        statsFile.close();
    } else {
        cerr << "Unable to open the file for reading statistics." << endl;
    }

    // Update the file with new statistics
    ofstream statsFileOut("statistics.txt");
    if (statsFileOut.is_open()) {
        statsFileOut << "Right Words: " << rightCount << "\n";
        statsFileOut << "Wrong Words: " << wrongCount << "\n";
        if (wrongCount > 0) {
            statsFileOut << "Percentage of Right words: " << static_cast<double>(rightCount) / (rightCount + wrongCount) << "\n";
        } else {
            statsFileOut << "Ratio (Right:Wrong): Undefined (No wrong words encountered)\n";
        }
        statsFileOut.close();
    } else {
        cerr << "Unable to open the file for writing statistics." << endl;
    }
}

void printColored(const string& wd, const string& color) {
    cout << "\033[" << color << "m" << wd << "\033[0m";
}

#include "Trie.h"
#include "FileUtils.h"
#include <sstream>

int main() {
    Trie trie;
    ifstream dictFile("top-10000-words-in-english.txt");
    string wd;
    while (getline(dictFile, wd)) {
        trie.insert(wd);
    }
    dictFile.close();

    int rightWordCount = 0;
    int wrongWordCount = 0;

    // Initialize statistics with existing data
    updateStatistics(rightWordCount, wrongWordCount);

    string sentence;
    while (true) {
        cout << "Enter a word or a sentence (type 'exit' to end): ";
        getline(cin, sentence);

        if (sentence == "exit") {
            break; // Exit the loop if the user enters 'exit'
        }

        for (char& c : sentence) {
            c = tolower(c);
        }

        stringstream ss(sentence);
        bool firstWd = true;
        vector<string> misspelled;
        vector<pair<string, vector<string>>> misspelledWithSuggestions;  // Pair of wrong word and its suggestions

        while (ss >> wd) {
            if (!trie.search(wd)) {
                if (!firstWd) {
                    cout << " ";
                }
                printColored(wd, "31"); // Red color for incorrect words
                misspelled.push_back(wd);
                wrongWordCount++;

                // Add suggestions to the vector
                vector<string> suggestions = trie.suggest(wd);
                misspelledWithSuggestions.emplace_back(wd, suggestions);
            } else {
                if (!firstWd) {
                    cout << " ";
                }
                printColored(wd, "32"); // Green color for correct words
                rightWordCount++;
            }
            firstWd = false;
        }
        cout << endl;

        // Add wrong words and suggestions to the file for memorization
        if (!misspelledWithSuggestions.empty()) {
            addWrongWordsToFile(misspelledWithSuggestions);
        }

        for (const string& misspelledWd : misspelled) {
            vector<string> suggestions = trie.suggest(misspelledWd);
            if (!suggestions.empty()) {
                cout << "Suggestions for " << misspelledWd << ": ";
                for (const string& suggestion : suggestions) {
                    cout << suggestion << " ";
                }
                cout << endl;
            } else {
                cout << "No suggestions for " << misspelledWd << endl;
            }
        }
        cout << endl;

        // Update statistics
        updateStatistics(rightWordCount, wrongWordCount);
    }

    return 0;
}

# Spell Checker

## Overview

The Spell Checker Program utilizes a trie data structure to provide efficient and accurate spell-checking functionality for English essays or texts. By leveraging the trie's hierarchical organization, the program offers fast insertion and retrieval of words, enabling quick verification of word correctness. Alongside basic spell-checking capabilities, the program also suggests corrections for misspelled words, enhancing its utility for users striving for grammatical accuracy and clarity in their writing. 

## Problem Addressed
The spell checker aims to efficiently store and retrieve large word datasets, addressing the limitations of traditional linear structures like arrays or linked lists, which suffer from slow search times. This issue is particularly critical in applications requiring rapid data access, such as search engine autocomplete features.

The trie, or prefix tree, tackles this problem by organizing data hierarchically, enabling faster search operations for words and prefixes. Each node in the trie corresponds to a character, with paths from the root to leaf nodes representing stored words. This hierarchical structure significantly reduces search time complexity compared to linear structures, making it ideal for large datasets. Additionally, the trie's ability to quickly locate words with a given prefix makes it suitable for features like predictive text and spell-checking in applications.

## Usage

### Compilation

To compile the project, ensure that you have the necessary dependencies installed and then run the following command:

```bash
g++ main.cpp Trie.cpp FileUtils.cpp -o trie_project
```

### Execution

After compilation, execute the compiled binary `trie_project`:

```bash
./trie_project
```

### Input

The project reads a file named `top-10000-words-in-english.txt`, which contains a list of words to populate the trie. This file should be present in the same directory as the executable.

### Usage Instructions

Upon execution, the program prompts the user to enter a word or a sentence. Words are separated by whitespace. To exit the program, type 'exit'.

### Output

- Correctly spelled words are printed in green color.
- Incorrectly spelled words are printed in red color, along with suggestions if available.
- Statistics regarding the number of correct and incorrect words encountered during the session are updated and stored in a file named `statistics.txt`.
- Incorrectly spelled words along with their suggestions are stored in a file named `wrong_words.txt`.

## Contributors
- Saif Abd Elfattah 
- Alyaman Huzaifa Massarani 
- Mohamed Ibrahim Abdelmagid 
- Mohamed Khalil Brik

Feel free to contribute to this project by forking it and submitting pull requests with improvements or bug fixes.


#include <iostream>
#include <regex>
using namespace std;

int main() {

    string sentence = "A quick brown dog jumps over the lazy fox";

    // Creating a object of regex and giving it the word for match.
    regex reg("fox");

    // Using the function regex_search("Where word has to be found", "The word
    // for which we are looking for");
    if (regex_search(sentence, reg)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
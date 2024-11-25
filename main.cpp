#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

string cleanWord(const string& word) {
    string cleaned;
    for (unsigned char ch : word) { 
        if (isalpha(ch) || (ch >= 'À' && ch <= 'ÿ') || ch == 'º' || ch == '¿') {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    string text;
    map<string, int> wordFrequency;

    cout << "Enter text: ";
    getline(cin, text);

    stringstream ss(text);
    string word;
    while (ss >> word) {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            ++wordFrequency[cleanedWord];
        }
    }

    cout << "\nWord Frequency:\n";
    for (const auto& [key, value] : wordFrequency) {
        cout << key << " - " << value << endl;
    }

    return 0;
}

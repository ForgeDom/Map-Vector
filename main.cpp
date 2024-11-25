#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

void addBook(map<string, vector<string>>& library, const string& bookTitle, const vector<string>& authors) {
    library[bookTitle] = authors;
}

void findAuthors(const map<string, vector<string>>& library, const string& bookTitle) {
    auto it = library.find(bookTitle);
    if (it != library.end()) {
        cout << "Authors of \"" << bookTitle << "\": ";
        for (const string& author : it->second) {
            cout << author << " ";
        }
        cout << endl;
    }
    else {
        cout << "Book \"" << bookTitle << "\" not found in the library.\n";
    }
}

void displayLibrary(const map<string, vector<string>>& library) {
    if (library.empty()) {
        cout << "The library is empty.\n";
        return;
    }
    cout << "\nLibrary:\n";
    for (map<string, vector<string>>::const_iterator it = library.begin(); it != library.end(); ++it) {
        cout << it->first << " — ";
        for (size_t i = 0; i < it->second.size(); ++i) {
            cout << it->second[i];  
            if (i < it->second.size() - 1) {
                cout << ", ";  
            }
        }
        cout << endl; 
    }

}

int main() {
    map<string, vector<string>> library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Find authors of a book\n";
        cout << "3. Display all books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title;
            string authorsLine;
            vector<string> authors;

            cout << "Enter the book title: ";
            getline(cin, title);

            cout << "Enter authors (comma separated): ";
            getline(cin, authorsLine);

            stringstream ss(authorsLine);
            string author;
            while (getline(ss, author, ',')) {
                authors.push_back(author);
            }

            addBook(library, title, authors);
            cout << "Book \"" << title << "\" added successfully.\n";
        }
        else if (choice == 2) {
            string title;
            cout << "Enter the book title: ";
            getline(cin, title);

            findAuthors(library, title);
        }
        else if (choice == 3) {
            displayLibrary(library);
        }
        else if (choice == 4) {
            cout << "Exiting the program...\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void addStudents(map<string, vector<string>>& groups, const string& groupName, const vector<string>& students) {
    groups[groupName].insert(groups[groupName].end(), students.begin(), students.end());
}

void removeStudent(map<string, vector<string>>& groups, const string& groupName, const string& student) {
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        auto& students = it->second;
        auto studentIt = find(students.begin(), students.end(), student);
        if (studentIt != students.end()) {
            students.erase(studentIt);
            cout << "Студент " << student << " видалений з групи " << groupName << ".\n";
        }
        else {
            cout << "Студент " << student << " не знайдений у групі " << groupName << ".\n";
        }
    }
    else {
        cout << "Група " << groupName << " не знайдена.\n";
    }
}

void showGroupStudents(const map<string, vector<string>>& groups, const string& groupName) {
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        cout << "Група " << groupName << ": ";
        for (size_t i = 0; i < it->second.size(); ++i) {
            cout << it->second[i];
            if (i < it->second.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Група " << groupName << " не знайдена.\n";
    }
}

void addStudentsFromInput(map<string, vector<string>>& groups) {
    string groupName;
    string studentsLine;
    vector<string> students;

    cout << "Введіть назву групи: ";
    getline(cin, groupName);

    cout << "Введіть студентів (через кому): ";
    getline(cin, studentsLine);

    stringstream ss(studentsLine);
    string student;
    while (getline(ss, student, ',')) {
        students.push_back(student);
    }

    addStudents(groups, groupName, students);
    cout << "Студенти додані до групи " << groupName << ".\n";
}

int main() {
    map<string, vector<string>> groups;
    int choice;

    do {
        cout << "\nМенеджер студентських груп\n";
        cout << "1. Додати студентів\n";
        cout << "2. Видалити студента\n";
        cout << "3. Показати студентів у групі\n";
        cout << "4. Вийти\n";
        cout << "Виберіть дію: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            addStudentsFromInput(groups);
        }
        else if (choice == 2) {
            string groupName, student;
            cout << "Введіть назву групи: ";
            getline(cin, groupName);
            cout << "Введіть студента для видалення: ";
            getline(cin, student);
            removeStudent(groups, groupName, student);
        }
        else if (choice == 3) {
            string groupName;
            cout << "Введіть назву групи: ";
            getline(cin, groupName);
            showGroupStudents(groups, groupName);
        }
        else if (choice == 4) {
            cout << "Вихід з програми...\n";
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 4);

    return 0;
}

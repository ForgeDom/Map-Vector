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
            cout << "������� " << student << " ��������� � ����� " << groupName << ".\n";
        }
        else {
            cout << "������� " << student << " �� ��������� � ���� " << groupName << ".\n";
        }
    }
    else {
        cout << "����� " << groupName << " �� ��������.\n";
    }
}

void showGroupStudents(const map<string, vector<string>>& groups, const string& groupName) {
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        cout << "����� " << groupName << ": ";
        for (size_t i = 0; i < it->second.size(); ++i) {
            cout << it->second[i];
            if (i < it->second.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else {
        cout << "����� " << groupName << " �� ��������.\n";
    }
}

void addStudentsFromInput(map<string, vector<string>>& groups) {
    string groupName;
    string studentsLine;
    vector<string> students;

    cout << "������ ����� �����: ";
    getline(cin, groupName);

    cout << "������ �������� (����� ����): ";
    getline(cin, studentsLine);

    stringstream ss(studentsLine);
    string student;
    while (getline(ss, student, ',')) {
        students.push_back(student);
    }

    addStudents(groups, groupName, students);
    cout << "�������� ����� �� ����� " << groupName << ".\n";
}

int main() {
    map<string, vector<string>> groups;
    int choice;

    do {
        cout << "\n�������� ������������ ����\n";
        cout << "1. ������ ��������\n";
        cout << "2. �������� ��������\n";
        cout << "3. �������� �������� � ����\n";
        cout << "4. �����\n";
        cout << "������� ��: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            addStudentsFromInput(groups);
        }
        else if (choice == 2) {
            string groupName, student;
            cout << "������ ����� �����: ";
            getline(cin, groupName);
            cout << "������ �������� ��� ���������: ";
            getline(cin, student);
            removeStudent(groups, groupName, student);
        }
        else if (choice == 3) {
            string groupName;
            cout << "������ ����� �����: ";
            getline(cin, groupName);
            showGroupStudents(groups, groupName);
        }
        else if (choice == 4) {
            cout << "����� � ��������...\n";
        }
        else {
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;


const int SIZE = 49;


string course[SIZE] = {
    "CMP 120", "CMP 220", "COE 221", "ELE 211", "ELE 211",
    "COE 241", "COE 241", "ELE 241", "ELE 241L", "MTH 221",
    "NGN 211", "ENG 204", "CMP 305", "CMP 305", "COE 341",
    "ELE 320", "ELE 320", "CMP 310", "CMP 310", "COE 371",
    "COE 371", "COE 371", "ELE 340", "ELE 340", "IEN 301",
    "COE 411", "COE 411", "COE 421L", "COE 424", "COE 490",
    "COE 490", "COE 490", "COE 491", "NGN 397", "NGN 397",
    "COE 312", "COE 312", "COE 375", "COE 375", "COE 414",
    "COE 425", "COE 428", "COE 428", "COE 431", "COE 434",
    "COE 457", "COE 457", "COE 487", "COE 487"
};

string prereq[SIZE] = {
    "NGN 110 or sophomore standing", "CMP 120", "PHY 102 + PHY 102L or CMP 120", "PHY 102", "PHY 102L",
    "CMP 120", "COE 221", "ELE 211", "ELE 241", "MTH 104",
    "MTH 104", "WRI 102", "CMP 220", "MTH 213", "COE 241",
    "ELE 211", "MTH 205", "CMP 305", "COE 241 or COE 251", "COE 221",
    "CMP 305", "MTH 104", "ELE 241", "COE 221", "45 credits",
    "COE 341", "ELE 340", "COE 411", "COE 341", "90 credits",
    "IEN 301", "COE 420 or COE 421L", "COE 490", "60 credits", "ENG 204",
    "CMP 220", "COE 241", "NGN 211", "COE 371", "ELE 320",
    "COE 341", "COE 241", "ELE 241", "COE 411", "COE 371",
    "CMP 310", "COE 371", "CMP 305", "MTH 221"
};

string type[SIZE] = {
    "before", "before", "before", "before", "before",
    "before", "before", "before", "concurrent", "before",
    "before", "before", "before", "concurrent", "before",
    "before", "before", "before", "before", "before",
    "before", "before", "before", "before", "credits",
    "before", "before", "concurrent", "before or concurrent", "credits",
    "before", "before", "before", "credits", "before",
    "before", "before", "before", "before or concurrent", "before",
    "before", "before", "before", "before", "before",
    "before", "before", "before", "before"
};

int credit[SIZE] = {
    3, 3, 4, 3, 3,
    4, 4, 3, 1, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    4, 4, 1, 3, 1,
    1, 1, 2, 0, 0,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3
};


void findPrereq(string name) {
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        if (course[i] == name) {
            if (!found) {   
                cout << name << " (" << credit[i] << " credits) needs:" << endl;
            }
            cout << "  - " << prereq[i] << " [" << type[i] << "]" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No prerequisites found for " << name << endl;
    }
}


void findOpens(string name) {
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
       
        if (prereq[i].find(name) != string::npos) {
            if (!found) {
                cout << name << " opens:" << endl;
            }
            cout << "  - " << course[i] << " (" << credit[i] << " credits) [" << type[i] << "]" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << name << " doesn't open any course in the list" << endl;
    }
}


int main() {
    string choice;
    string name;

    do {
        cout << "\n===== AUS COE Prerequisite Checker =====" << endl;
        cout << "1. What does a course need?" << endl;
        cout << "2. What does a course open?" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";
        getline(cin, choice);

        if (choice == "1" || choice == "2") {
            cout << "Enter course (e.g. COE 241): ";
            getline(cin, name);

            if (choice == "1") {
                findPrereq(name);
            }
            else {
                findOpens(name);
            }
        }
        else if (choice != "3") {
            cout << "Invalid choice, pick 1, 2 or 3" << endl;
        }

    } while (choice != "3");

    cout << "Bye!" << endl;
    return 0;
}
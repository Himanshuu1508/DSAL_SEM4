#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // For remove and rename functions
using namespace std;

struct node {
    int rno;
    string name;
    string address;
    char division;
};

void createFile() {
    ofstream f;
    f.open("students.txt");
    if (!f) {
        cout << "Failed to open file!" << endl;
        return;
    }
    f.close();
}

void add() {
    ofstream f;
    f.open("students.txt", ios::app);
    if (!f) {
        cout << "Failed to open file!" << endl;
        return;
    }
    node s;
    cout << "Enter roll number of student: ";
    cin >> s.rno;
    cout << "Enter name of student: ";
    cin >> s.name;
    cout << "Enter address of student: ";
    cin.ignore(); // Ignore the newline character from previous input
    getline(cin, s.address);
    cout << "Enter division of student: ";
    cin >> s.division;
    f << s.rno << " " << s.name << " " << s.address << " " << s.division << endl;
    f.close();
}

void display() {
    ifstream inf;
    inf.open("students.txt");
    if (!inf) {
        cout << "Failed to open file!" << endl;
        return;
    }
    node n;
    while (inf >> n.rno >> n.name >> n.address >> n.division) {
        cout << "Name: " << n.name << "\n"
             << "Roll Number: " << n.rno << "\n"
             << "Address: " << n.address << "\n"
             << "Division: " << n.division << "\n"
             << endl;
    }
    inf.close();
}

void searchAndRemove(int r) {
    ifstream inf;
    ofstream temp;
    inf.open("students.txt");
    temp.open("temp.txt");
    if (!inf || !temp) {
        cout << "Error opening files." << endl;
        return;
    }
    node n;
    bool found = false;
    while (inf >> n.rno >> n.name >> n.address >> n.division) {
        if (n.rno != r) {
            temp << n.rno << " " << n.name << " " << n.address << " " << n.division << endl;
        } else {
            found = true;
            cout << "Found roll number: " << n.rno << ", Name: " << n.name << ", Address: " << n.address << ", Division: " << n.division << endl;
        }
    }
    inf.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (!found) {
        cout << "Not found!" << endl;
    }
}

void editInformation(int r) {
    ifstream inf;
    ofstream temp;
    inf.open("students.txt");
    temp.open("temp.txt");
    if (!inf || !temp) {
        cout << "Error opening files." << endl;
        return;
    }
    node n;
    bool found = false;
    while (inf >> n.rno >> n.name >> n.address >> n.division) {
        if (n.rno == r) {
            found = true;
            cout << "Found roll number: " << n.rno << ", Name: " << n.name << ", Address: " << n.address << ", Division: " << n.division << endl;
            cout << "Enter new name: ";
            cin >> n.name;
            cout << "Enter new address: ";
            cin.ignore(); // Ignore the newline character from previous input
            getline(cin, n.address);
            cout << "Enter new division: ";
            cin >> n.division;
        }
        temp << n.rno << " " << n.name << " " << n.address << " " << n.division << endl;
    }
    inf.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (!found) {
        cout << "Roll number not found!" << endl;
    } else {
        cout << "Information updated successfully!" << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "1. Create file" << endl
             << "2. Add student" << endl
             << "3. Display" << endl
             << "4. Search and remove" << endl
             << "5. Edit information" << endl
             << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                createFile();
                break;
            case 2:
                add();
                break;
            case 3:
                display();
                break;
            case 4:
                int r;
                cout << "Enter roll number to search and remove: ";
                cin >> r;
                searchAndRemove(r);
                break;
            case 5:
                cout << "Enter roll number to edit information: ";
                cin >> r;
                editInformation(r);
                break;
        }
    } while (ch < 6 && ch > 0);
    return 0;
}

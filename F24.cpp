#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct employee {
    int id;
    string name;
    string designation;
    double salary;
};

struct index {
    int id;
    int position;
};

void addEmployee(vector<index>& vectorIndex) {
    ofstream outf;
    outf.open("sample.txt", ios::app);
    int offset = outf.tellp();
    employee e1;
    cout << "Enter name: ";
    cin >> e1.name;
    cout << "Enter ID: ";
    cin >> e1.id;
    cout << "Enter designation: ";
    cin >> e1.designation;
    cout << "Enter salary: ";
    cin >> e1.salary;
    outf << e1.id << " " << e1.name << " " << e1.designation << " " << e1.salary << endl;
    index i1;
    i1.id = e1.id;
    i1.position = offset;
    vectorIndex.push_back(i1);
    outf.close();
}

void displayEmployee() {
    ifstream inf;
    inf.open("sample.txt");
    if (!inf) {
        cout << "Failed to open file!" << endl;
        return;
    }
    employee e1;
    while (inf >> e1.id >> e1.name >> e1.designation >> e1.salary) {
        cout << "Name: " << e1.name << ", ID: " << e1.id << ", Designation: " << e1.designation << ", Salary: " << e1.salary << endl;
    }
    inf.close();
}

void search(vector<index>& v1, int id1) {
    int pos;
    bool found = false;
    for (auto it : v1) {
        if (it.id == id1) {
            pos = it.position;
            found = true;
            break;
        }
    }
    if (found) {
        ifstream inf;
        inf.open("sample.txt", ios::in);
        inf.seekg(pos);
        string line;
        getline(inf, line);
        cout << "Found: " << line << endl;
        inf.close();
    } else {
        cout << "Not found!" << endl;
    }
}

void deleteEmployee(vector<index>& v1, int id1) {
    int j = -1;
    bool found = false;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i].id == id1) {
            j = i;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Not found!" << endl;
        return;
    }
    v1.erase(v1.begin() + j);
    ifstream inf;
    inf.open("sample.txt", ios::in);
    ofstream temp;
    temp.open("temp.txt", ios::out);
    for (int i = 0; i < v1.size(); ++i) {
        int pos = v1[i].position;
        inf.seekg(pos);
        string line;
        getline(inf, line);
        temp << line << endl;
    }
    inf.close();
    temp.close();
    remove("sample.txt");
    rename("temp.txt", "sample.txt");
}

int main() {
    vector<index> v1;
    int choice;
    int id;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add an employee\n";
        cout << "2. Display all employees\n";
        cout << "3. Search for an employee by ID\n";
        cout << "4. Delete an employee by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(v1);
                break;
            case 2:
                displayEmployee();
                break;
            case 3:
                cout << "Enter employee ID to search: ";
                cin >> id;
                search(v1, id);
                break;
            case 4:
                cout << "Enter employee ID to delete: ";
                cin >> id;
                deleteEmployee(v1, id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

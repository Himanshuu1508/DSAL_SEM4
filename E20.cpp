#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    int priority;
    node* next;

    node() {
        priority = 3;
        name = "";
        next = nullptr;
    }

    node(string name, int n) {
        this->name = name;
        this->priority = n;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    node* front;
    node* rear;

public:
    PriorityQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(node patient) {
        if (front == nullptr && rear == nullptr) {
            front = rear = new node(patient.name, patient.priority);
        } else {
            if (patient.priority == 1) {
                node* temp = front;
                front = new node(patient.name, patient.priority);
                front->next = temp;
                rear = front;
                while (rear->next != nullptr) {
                    rear = rear->next;
                }
            } else if (patient.priority == 3) {
                rear->next = new node(patient.name, patient.priority);
                rear = rear->next;
            } else if (patient.priority == 2) {
                node* temp = front;
                node* prev = nullptr;
                while (temp != nullptr && temp->priority != 3) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = new node(patient.name, patient.priority);
                prev = prev->next;
                prev->next = temp;
                rear = front;
                while (rear->next != nullptr) {
                    rear = rear->next;
                }
            } else {
                cout << "Invalid priority" << endl;
            }
        }
    }

    void display() {
        if (front == nullptr && rear == nullptr) {
            cout << "Empty" << endl;
        } else {
            cout << "Priority Queue:" << endl;
            node* current = front;
            while (current != nullptr) {
                cout << "Name: " << current->name << ", Priority: " << current->priority << endl;
                current = current->next;
            }
        }
    }

    void deque() {
        if (front == nullptr && rear == nullptr) {
            cout << "Empty" << endl;
        } else {
            node* temp = front;
            front = front->next;
            cout << "Patient: " << temp->name << ", Priority: " << temp->priority << " checked" << endl;
            delete temp;
        }
    }
};

int main() {
    int ch;
    PriorityQueue pq;
    node p1; // Declare p1 outside the switch block
    do {
        cout << "1. Enter patient\n2. Display\n3. Check a patient\n4. Exit\n";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter name: ";
                cin >> p1.name;
                cout << "Enter priority: ";
                cin >> p1.priority;
                pq.enqueue(p1);
                break;
            case 2:
                pq.display();
                break;
            case 3:
                pq.deque();
                break;
            case 4:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (ch != 4);
    return 0;
}

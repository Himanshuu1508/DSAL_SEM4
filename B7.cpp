#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    string key;
    string value;
    node* left;
    node* right;

    node(string key, string value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class DictionaryBST {
private:
    node* root;

public:
    DictionaryBST() {
        root = nullptr;
    }

    void insert(string, string);
    int find(string);
    void print();

    void remove(string);

    friend void del(node*&, string);
    friend node* insuccessor(node*);
};

void DictionaryBST::insert(string key, string value) {
    if (root == nullptr) {
        root = new node(key, value);
        return;
    }

    node* temp = root;
    while (true) {
        if (key < temp->key) {
            if (temp->left == nullptr) {
                temp->left = new node(key, value);
                break;
            }
            temp = temp->left;
        } else if (key > temp->key) {
            if (temp->right == nullptr) {
                temp->right = new node(key, value);
                break;
            }
            temp = temp->right;
        } else {
            // updates the value at key
            temp->value = value;
            cout << "Found!! updated!" << endl;
            return;
        }
    }
}

node* insuccessor(node* curr) {
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

void del(node*& curr, string key) {
    if (curr == nullptr) {
        return;
    }

    if (key < curr->key) {
        del(curr->left, key);
    } else if (key > curr->key) {
        del(curr->right, key);
    } else {
        if (curr->left == nullptr) {
            node* temp = curr->right;
            delete curr;
            curr = temp;
        } else if (curr->right == nullptr) {
            node* temp = curr->left;
            delete curr;
            curr = temp;
        } else {
            node* temp = insuccessor(curr->right);
            curr->key = temp->key;
            curr->value = temp->value;
            del(curr->right, temp->key);
        }
    }
}

void DictionaryBST::remove(string key) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    del(root, key);
}

void DictionaryBST::print() {
    if (root == nullptr) {
        cout << "----" << endl;
        return;
    }

    stack<node*> s;
    vector<pair<string, string>> v;
    node* curr = root;
    while (curr != nullptr || !s.empty()) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        v.push_back({curr->key, curr->value});

        curr = curr->right;
    }

    cout << endl
         << "ascending, " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << "Key: " << v[i].first << ", Value: " << v[i].second << endl;
    }

    cout << endl
         << "descending, " << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << "Key: " << v[i].first << ", Value: " << v[i].second << endl;
    }
}

int DictionaryBST::find(string key) {
    if (root == nullptr) {
        return -1;
    }

    int com = 1;
    node* temp = root;
    while (temp) {
        com += 1;
        if (key < temp->key) {
            temp = temp->left;
        } else if (key > temp->key) {
            temp = temp->right;
        } else {
            return com;
        }
    }
    return -1;
}

int main() {
    DictionaryBST bst;
    int choice;
    string key, value;
    int comparisons;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a keyword\n";
        cout << "2. Remove a keyword\n";
        cout << "3. Find a keyword\n";
        cout << "4. Display dictionary\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword and its meaning: ";
                cin >> key >> value;
                bst.insert(key, value);
                break;
            case 2:
                cout << "Enter keyword to remove: ";
                cin >> key;
                bst.remove(key);
                break;
            case 3:
                cout << "Enter keyword to find: ";
                cin >> key;
                comparisons = bst.find(key);
                if (comparisons == -1) {
                    cout << "Keyword not found!" << endl;
                } else {
                    cout << "Keyword found in " << comparisons << " comparisons." << endl;
                }
                break;
            case 4:
                cout << "Dictionary:" << endl;
                bst.print();
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

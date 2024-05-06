#include <iostream>
#include <cstring>
using namespace std;

struct HBTNode {
    int Key;
    char Mean[10];
    HBTNode *left;
    HBTNode *right;
} *Root;

void create_HBT() {
    int i, nodes, done;
    struct HBTNode *Newnode, *current;
    cout << "\n\n Enter the number of nodes to insert in HBT: ";
    cin >> nodes;
    for (i = 0; i < nodes; i++) {
        Newnode = new struct HBTNode;
        cout << "\n\t Enter Keyword: ";
        cin >> Newnode->Key;
        cout << "\n\t Enter Meaning: ";
        cin >> Newnode->Mean;
        Newnode->left = NULL;
        Newnode->right = NULL;
        if (Root == NULL) {
            Root = Newnode;
        } else {
            done = 0;
            current = Root;
            while (!done) {
                if (Newnode->Key < current->Key) {
                    if (current->left == NULL) {
                        current->left = Newnode;
                        done = 1;
                    } else
                        current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = Newnode;
                        done = 1;
                    } else
                        current = current->right;
                }
            }
        }
    }
}

void display_HBT(struct HBTNode *root) {
    if (root) {
        cout << "\n\t" << root->Key << " - " << root->Mean;
        display_HBT(root->left);
        display_HBT(root->right);
    }
}

void Sorted_List(struct HBTNode *root) {
    if (root) {
        Sorted_List(root->left);
        cout << "\n\t" << root->Key << " - " << root->Mean;
        Sorted_List(root->right);
    }
}

void insertKeyword() {
    int key;
    char meaning[10];
    struct HBTNode *Newnode, *current, *parent;
    Newnode = new struct HBTNode;
    cout << "\n\t Enter Keyword: ";
    cin >> key;
    cout << "\n\t Enter Meaning: ";
    cin >> meaning;
    Newnode->Key = key;
    strcpy(Newnode->Mean, meaning);
    Newnode->left = NULL;
    Newnode->right = NULL;

    if (Root == NULL) {
        Root = Newnode;
    } else {
        current = Root;
        while (current) {
            parent = current;
            if (key < current->Key)
                current = current->left;
            else
                current = current->right;
        }
        if (key < parent->Key)
            parent->left = Newnode;
        else
            parent->right = Newnode;
    }
}

struct HBTNode *deleteNode(struct HBTNode *root, int key) {
    if (root == NULL) return root;
    if (key < root->Key)
        root->left = deleteNode(root->left, key);
    else if (key > root->Key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct HBTNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct HBTNode *temp = root->left;
            delete root;
            return temp;
        }
        struct HBTNode *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->Key = temp->Key;
        strcpy(root->Mean, temp->Mean);
        root->right = deleteNode(root->right, temp->Key);
    }
    return root;
}

void updateMeaning(int key) {
    char meaning[10];
    struct HBTNode *current = Root;
    while (current) {
        if (key == current->Key) {
            cout << "\n\t Enter New Meaning: ";
            cin >> meaning;
            strcpy(current->Mean, meaning);
            cout << "\n\t Meaning Updated Successfully!";
            return;
        } else if (key < current->Key)
            current = current->left;
        else
            current = current->right;
    }
    cout << "\n\t Keyword not found!";
}

void Find_Keyword(int key) {
    int comp = 0;
    int level = 0;
    int done;
    struct HBTNode *current;
    done = 0;
    current = Root;
    while (!done) {
        if (key < current->Key) {
            current = current->left;
            level++;
            comp++;
        } else if (key > current->Key) {
            current = current->right;
            level++;
            comp++;
        } else {
            done = 1;
            comp++;
            cout << "\n\t Key : " << key;
            cout << "\n\t Found at Level: " << level;
            cout << "\n\t No. of Comparisons: " << comp;
        }
    }
}

int main() {
    int choice, key;
    cout << "\n -------***A C++ Program to Implement Dictionary using Height-Balanced Tree.***-------\n ";
    while (1) {
        cout << "\n\n 1. Create Height-Balanced Tree";
        cout << "\n 2. Display Keywords and Meanings in Height-Balanced Tree";
        cout << "\n 3. Display a Sorted List of Keywords and Meanings";
        cout << "\n 4. Add New Keyword";
        cout << "\n 5. Delete Keyword";
        cout << "\n 6. Update Meaning of Keyword";
        cout << "\n 7. Find Keyword";
        cout << "\n 8. Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                create_HBT();
                break;
            case 2:
                cout << "\n Keyword - Meaning";
                display_HBT(Root);
                break;
            case 3:
                cout << "\n Keyword - Meaning";
                Sorted_List(Root);
                break;
            case 4:
                insertKeyword();
                break;
            case 5:
                cout << "\n Enter the keyword to delete: ";
                cin >> key;
                Root = deleteNode(Root, key);
                cout << "\n Keyword deleted successfully!";
                break;
            case 6:
                cout << "\n Enter the keyword to update meaning: ";
                cin >> key;
                updateMeaning(key);
                break;
            case 7:
                cout << "\n Enter the keyword to find: ";
                cin >> key;
                Find_Keyword(key);
                break;
            case 8:
                exit(0);
            default:
                cout << "\n Invalid choice!";
        }
    }
    return 0;
}

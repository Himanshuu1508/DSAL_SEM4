#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
    void create();
    void insert();
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    bool search(Node*,int val);
    void mini(Node*);
    int height(Node*);
    void swap(Node*);
};

void BST::create(){
    int n;
    cout<<"Enter number of nodes to create: ";
    cin>>n;
    for(int i = 0;i<n;i++){
        insert();
    }
}

void BST::insert() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp != NULL) {
        if (val < temp->data) {
            if (temp->left == NULL) {
                temp->left = new Node(val);
                return;
            }
            temp = temp->left;
        } else if (val > temp->data) {
            if (temp->right == NULL) {
                temp->right = new Node(val);
                return;
            }
            temp = temp->right;
        } else if (val == temp->data) {
            cout << "Value already inserted " << endl;
            return; // Return after handling the case of duplicate value
        }
    }
}


bool BST::search(Node* root,int val){
    Node* temp = root;
    while(temp!= NULL){
        if(val== temp->data){
            cout<<"Value found!!";
            return true;
        }
        else if(val<temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    cout<<"Not found in tree!!";
    return false;
}

void BST::mini(Node* root){
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return; // Return some default value to indicate error or handle it differently
    }

    Node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    cout << "The minimum value in the tree is: "<<temp->data;
    return;
}
int BST::height(Node* root){
    if(root == NULL){
        return -1;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh > rh){
        return lh + 1;
    }
    else{
        return rh + 1;
    }
}
void BST:: swap(Node* root){
    if(root == NULL){
        return;
    }
    Node* temp = root->right;
    root->right = root->left;
    root->left= temp;
    
    swap(root->left);
    swap(root->right);
    
};
int main(){
    int ch;
    cout<<"\t\t\t**MENU**\t\t\t"<<endl;
    BST t1;
    do{
        cout<<"Enter: "<<endl;
        cout<<"1)Create tree\n2)Insert Node\n3)Search\n4)Find minimum element\n5)Find height of tree\n6)Mirror tree\n";
        cin>>ch;
        switch(ch){
            case 1:
                t1.create();
                break;
            case 2:
                t1.insert();
                break;
            case 3:
                int find;
                cout<<"Enter value to find: ";
                cin>>find;
                t1.search(t1.root,find);
                break;
            case 4:
                t1.mini(t1.root);
                break;
            case 5:
                cout<<"Height of tree is: "<<endl;
                cout<<t1.height(t1.root)<<endl;
                break;
            case 6:
                t1.swap(t1.root);
                break;
        }
    }
    while(ch>0 && ch<7);
    return 0;
}

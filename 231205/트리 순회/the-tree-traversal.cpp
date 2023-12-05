#include <iostream>
#include <unordered_map>

using namespace std;

//var
int n;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char data): data(data), left(nullptr), right(nullptr) {}
};

class Dtree{
public:
    Node* root;
    Dtree(): root(nullptr) {}

    void preorder(Node* node){
        if(node != nullptr){
            cout << node->data;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node){
        if(node != nullptr){
            inorder(node->left);
            cout << node->data;
            inorder(node->right);
        }
    }

    void postorder(Node* node){
        if(node != nullptr){
            postorder(node->left);
            postorder(node->right);
            cout << node->data;
        }
    }
};

Dtree tree;
unordered_map<char, Node*> nodes;

void run(){
    tree.preorder(tree.root);
    cout << endl;
    tree.inorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;
}

void init(){
    cin >> n;
    char a, b, c;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if(nodes.find(a) == nodes.end()){
            nodes[a] = new Node(a);
            if(tree.root == nullptr) tree.root = nodes[a];
        }

        if(b != '.'){
            if(nodes.find(b) == nodes.end()) nodes[b] = new Node(b);
            nodes[a]->left = nodes[b];
        }

        if(c != '.'){
            if(nodes.find(c) == nodes.end()) nodes[c] = new Node(c);
            nodes[a]->right = nodes[c];
        }
    }
}

int main() {
    init();
    run();
    return 0;
}
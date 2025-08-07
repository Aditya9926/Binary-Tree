#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

//Morris Inorder Treversal
vector<int> morrisInorderTraversal(Node* root) {
    vector<int> result;
    Node* current = root;
    
    while (current != NULL) {
        if (current->left == NULL) {
            result.push_back(current->data);
            current = current->right;
        } else {
            Node* pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                result.push_back(current->data);
                current = current->right;
            }
        }
    }
    return result;
}

// Stack Inorder Traversal
vector<int> stackInorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        result.push_back(current->data);
        current = current->right;
    }
    return result;
}

// Inorder Traversal Recursive
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Driver code
int main()
{
    // Build the tree
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Morris Inorder Traversal output
    vector<int> m = morrisInorderTraversal(root);
    cout << "Morris Inorder Traversal: ";
     for (int data : m) {
        cout << data << " ";
    }
    
    // Stack Inorder Traversal output
    vector<int> s = stackInorderTraversal(root);
    cout << "\nStack Inorder Traversal: ";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    // Recursive Inorder Traversal output
    cout << "\nInorder Traversal: ";
    printInorder(root);
    return 0;
}
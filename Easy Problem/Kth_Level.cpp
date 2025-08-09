// C++ Program of the above approach
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Recursive function to print all
// nodes of a Binary Tree at a
// given level using DFS traversal
void printNodes(Node* root, int level, int K)
{
    // Base Case
    if (root == NULL) {
        return;
    }

    // Recursive Call for
    // the left subtree
    printNodes(root->left, level + 1, K);

    // Recursive Call for
    // the right subtree
    printNodes(root->right, level + 1, K);

    // If current level is
    // the required level
    if (K == level) {
        cout << root->data << " ";
    }
}

// Function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver Code
int main()
{
    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(6);
    root->left->left = newNode(11);
    int K = 2;

    printNodes(root, 1, K);
    return 0;
}
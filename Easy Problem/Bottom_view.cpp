// C++ code to find the bottom view 
// using level-order traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to return the bottom view 
// of the binary tree
vector<int> bottomView(Node *root) {
    if (!root) return {};

    // Map to store the last node at each 
    // horizontal distance (HD)
    map<int, int> hdMap;
    
    // Queue to store nodes and their HD
    queue<pair<Node*, int>> q;
    
    // Start level order traversal with
  	// root at HD 0
    q.push({root, 0});
    
    while (!q.empty()) {
      
        // Get current node and its HD
        Node *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        // Update the map with the current
      	// node's data
        hdMap[hd] = curr->data;
        
        // Traverse the left subtree, HD - 1
        if (curr->left) {
            q.push({curr->left, hd - 1});
        }
        
        // Traverse the right subtree, HD + 1
        if (curr->right) {
            q.push({curr->right, hd + 1});
        }
    }
    
    // Extract bottom view nodes 
  	// from the map
    vector<int> result;
    
    // Iterate through the map in 
  	// sorted HD order
    for (auto it : hdMap) {
        result.push_back(it.second);
    }
    
    return result;
}

void printArray(vector<int>& arr) {
    
    cout << endl;
}

int main() {
  
    // Representation of the input tree:
    //       20
    //      /  \
    //     8   22
    //    / \    \
    //   5   3   25
    //      / \
    //     10 14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> result = bottomView(root);
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
// C++ program to print top
// view of binary tree
// using dfs

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// DFS Helper to store top view nodes
void dfs(Node* node, int hd, int level, 
         map<int, pair<int, int>>& topNodes) {
  
    if (!node) return;

    // If horizontal distance is encountered for 
    // the first time or if it's at a higher level
    if (topNodes.find(hd) == topNodes.end() || 
        topNodes[hd].second > level) {
        topNodes[hd] = {node->data, level};
    }

    // Recur for left and right subtrees
    dfs(node->left, hd - 1, level + 1, topNodes);
    dfs(node->right, hd + 1, level + 1, topNodes);
}

// DFS Approach to find the top view of a binary tree
vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;
    
    // Horizontal distance -> {node's value, level}
    map<int, pair<int, int>> topNodes; 
    
    // Start DFS traversal
    dfs(root, 0, 0, topNodes);

    // Collect nodes from the map
    for (auto it : topNodes) {
        result.push_back(it.second.first);
    }

    return result;
}


int main() {
    
  // Create a sample binary tree
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7

    Node* root = new Node(1);
    root->left = new Node(2);       
    root->right = new Node(3);            
    root->left->left = new Node(4);     
    root->left->right = new Node(5);   
    root->right->left = new Node(6);   
    root->right->right = new Node(7); 

    vector<int> result = topView(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
};
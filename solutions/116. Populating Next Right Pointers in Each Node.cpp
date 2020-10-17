/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
​
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
    int connectHelper(Node* root) {
       if (root == NULL) return 0;
        if (root->left == NULL) return 1;
        
        int height = connectHelper(root->left);
        connectHelper(root->right);
      
        Node* left = root->left;
        Node* right = root->right;
        for (int i = 0; i < height; ++i) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
         
        return height + 1;
    }
    
    Node* connect(Node* root) {
        connectHelper(root);
        return root;
    }
};

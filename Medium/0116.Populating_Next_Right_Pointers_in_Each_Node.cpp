/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        int total = q.size();
        Node* temp = nullptr;
        for(int i=0; i<total; ++i) {
            Node* now = q.front();
            q.pop();
            if(temp) temp->next = now;
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
            temp = now;
            if(i == total-1) {
                i = -1;
                total = q.size();
                temp = nullptr;
            }
        }
        return root;
    }
};
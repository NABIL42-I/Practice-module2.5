#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* Input_BT() {
    int val;
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if (l != -1) {
            p->left = new Node(l);
            q.push(p->left);
        }
        if (r != -1) {
            p->right = new Node(r);
            q.push(p->right);
        }
    }
    return root;
}

int sumNonLeafNodes(Node* root) {
    if (!root) return 0;
    int sum = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left!=NULL || current->right!=NULL) {
            sum += current->val;
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return sum;
}

int main() {
    Node* root = Input_BT();
    cout << sumNonLeafNodes(root) << endl;
    return 0;
}

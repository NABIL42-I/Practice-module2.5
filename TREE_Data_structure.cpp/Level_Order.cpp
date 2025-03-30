#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void level_order_print(Node* root){
    if(root == NULL){
        cout<<"No Tree";
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        cout<<p->val<<" ";
        if(p->left!=NULL) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}
int main(){
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);
    Node* f = new Node(70);
    root->left = a;
    root->right = b;
    a->left = c;
    c->left = f;
    b->left = d;
    b->right = e;
    level_order_print(root);
    return 0;
}
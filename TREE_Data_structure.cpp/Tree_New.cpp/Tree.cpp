#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* right;
    Node* left;
    Node(int val){
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};
Node* input(int val){
Node *root = new Node(val);
queue<Node*>q;
q.push(root);
while(!q.empty()){
    Node* par = q.front();
    q.pop();
    int lc,rc;cin>>lc>>rc;
    Node* mleft;Node* mright;
    if(lc==-1)  mleft = NULL;
    else  mleft = new Node(lc);
    if(rc == -1) mright = NULL;
    else  mright = new Node(rc);
    par->left = mleft;
    par->right = mright;
    if(par->left!=NULL) q.push(par->left);
    if(par->right!=NULL) q.push(par->right);
}
return root;
}
// Node* input() {
//     int val;
//     cin >> val;
//     if (val == -1) return NULL; // যদি ট্রি ফাঁকা হয়

//     Node* root = new Node(val);
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* parent = q.front();
//         q.pop();

//         int lc, rc;
//         cin >> lc >> rc;  // Left এবং Right Child ইনপুট নাও

//         if (lc != -1) {
//             parent->left = new Node(lc);
//             q.push(parent->left);
//         }
//         if (rc != -1) {
//             parent->right = new Node(rc);
//             q.push(parent->right);
//         }
//     }
//     return root;
// }
void print(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* par = q.front();
        q.pop();
        cout<<par->val<<" ";
        if(par->left) q.push(par->left);
        if(par->right) q.push(par->right);
    }
}
int main(){
    int val;cin>>val;
    Node* root = input(val);
    print(root);
}

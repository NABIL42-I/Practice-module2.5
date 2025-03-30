#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};
Node* input(){
    int val;cin>>val;
    if(val == -1) return 0;
    Node* root = new Node(val);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        int l,r;cin>>l>>r;
        Node* lc;Node* rc;
        if(l==-1) lc =NULL;
        else lc = new Node(l);
        if(r==-1) rc = NULL;
       else rc = new Node(r);
      p->left = lc;
      p->right = rc;
     if(p->left) q.push(p->left);
      if(p->right)q.push(p->right);
    }
    return root;
}
void outer_right(Node* root){
    // cout<<root->val<<" ";
    if(root->right){
        cout<<root->val<<" ";
        outer_right(root->right);
    }
    else if(root->left){
        cout<<root->val<<" ";
        outer_right(root->left);
    }
    else cout<<root->val<<" ";
}
void print(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
       Node* p = q.front();
       q.pop();
       cout<<p->val<<" ";
       if(p->left) q.push(p->left);
       if(p->right)q.push(p->right);
    }
}
int main(){
    Node* root = input();
    outer_right(root);
    // print(root);
    return 0;
}


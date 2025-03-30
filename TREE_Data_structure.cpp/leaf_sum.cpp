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
int leaf_sum(Node* root){
    if(root == NULL) return 0;
    if(root->right == NULL &&root->left == NULL) return root->val;
    int left = leaf_sum(root->left);
    int right = leaf_sum(root->right);
    return left+right;
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
    int count = leaf_sum(root);
    cout<<count<<endl;
    // print(root);
    return 0;
}


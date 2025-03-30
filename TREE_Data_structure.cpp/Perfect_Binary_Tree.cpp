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
int count(Node* root){
    if(root == NULL) return 0;
    int l = count(root->left);
    int r = count(root->right);
    return l+r+1;
}
int max_height(Node* root){
    if(root == NULL) return 0;
    if(root->left==NULL&&root->right==NULL) return 1;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l,r)+1;
}
Node* Input_BT(){
     int val;cin>>val;
     Node* root = new Node(val);
     queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        Node* lc;
        Node* rc;
        int l,r;cin>>l>>r;
        if(l==-1) lc = NULL;
        else lc = new Node(l);
        if(r==-1) rc = NULL;
        else rc = new Node(r);
       p->left = lc;
       p->right = rc;
       if(p->left) q.push(p->left);
       if(p->right) q.push(p->right);
    }
    return root;
}
int main(){ 
  Node* root = Input_BT();
  int total_Node = count(root);
  int depth = max_height(root);
  int perfect = pow(2,depth) - 1 ;
  if(total_Node == perfect) cout<<"YES";
  else cout<<"NO";
    return 0;
}
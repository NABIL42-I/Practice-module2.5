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
int max_height(Node* root){
    if(root == NULL) return 0;
    if(root->left==NULL&&root->right==NULL) return 0;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l,r)+1;
}
    void levelNode(Node* root,int idx) {
       queue<pair<Node*,int>>q;
       q.push({root,0});
       while(!q.empty()){
        pair<Node*,int>p = q.front();
        q.pop();
        Node* node = p.first;
        int level = p.second;
        if(level == idx){
            cout<<node->val<<" ";
        }
        if(node->left) q.push({node->left,level+1});
        if(node->right) q.push({node->right,level+1});
       }
    }

int main(){
    Node*root=input();
    int idx;cin>>idx;
    int mx = max_height(root);
    if(idx>mx){
       cout<<"Invalid";
       return 0;
    }
    levelNode(root,idx);
    return 0;
}

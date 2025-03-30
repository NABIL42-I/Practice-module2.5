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
void count(Node* root){
    if(root == NULL){
        cout<<"No Tree";
        return;
    }
    queue<Node*>q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        // cout<<p->val<<" ";
        count++;
        if(p->left!=NULL) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    cout<<"Total Node is : "<<count<<endl;
}
void Input_BT(Node* root){
    //  int val;cin>>val;
    //  Node* root = new Node(val);
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
}
int main(){ 
    int val ;cin>>val;
 Node* root = new Node(val);
 Input_BT(root);
    count(root);
    return 0;
}
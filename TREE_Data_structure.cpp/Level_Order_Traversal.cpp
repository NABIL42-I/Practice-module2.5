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
Node* level_order(){
   int val;cin>>val;
   if(val == -1 ) return NULL;
   Node* root = new Node(val);
   queue<Node*>q;
   if(root)
   q.push(root);
   while(!q.empty()){
     Node* p = q.front();
     q.pop();
     int l , r;cin>>l>>r;
     Node* lc ;
     Node* rc;
     if(l==-1) lc = NULL;
     else lc = new Node(l);
     if(r==-1) rc = NULL;
     else rc = new Node(r);
     if(lc) p->left = lc;
     if(rc) p->right = rc;
     if(lc)
     q.push(p->left);
     if(rc)
     q.push(p->right);
   }
   return root;
}
void print(Node* root){
    queue<Node*>q;
    if(root)
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
    Node* root = level_order();
    print(root);
    return 0;
}
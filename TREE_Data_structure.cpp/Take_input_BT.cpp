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
Node* Input_BT(int val){
    //  int val;cin>>val;
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
    int val ;cin>>val;
    // Node* root = new Node(val);
 Node* root = Input_BT(val);
    level_order_print(root);
    return 0;
}

vector<int>v;
vector<int> getLevelOrder(BinaryTreeNode<int>* root) {

    if (root == NULL) return v;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* f = q.front();
        q.pop();
        v.push_back(f->val); // Add the value of the current node to the vector
        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
    return v;
}


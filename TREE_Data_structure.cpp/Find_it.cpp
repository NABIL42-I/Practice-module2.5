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
void leaf(Node* root,vector<int>&v){
    if(root == NULL) return ;
    if(root->right == NULL &&root->left == NULL){  
          v.push_back(root->val);
        }
  leaf(root->left,v);
   leaf(root->right,v);

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
    vector<int>v;
    leaf(root,v);
    map<int,int>mp;
    for(int i:v){
   mp[i]++;
    }
    int mx;
     int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > count) {
                mx = it->first;
                 count = it->second;
            }
        }
cout<<mx<<endl;
    return 0;
}


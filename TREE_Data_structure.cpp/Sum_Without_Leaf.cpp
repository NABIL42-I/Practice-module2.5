//                          PRE-ORDER(ROOT,LEFT,RIHGT)
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
int sum ;
void count_sum(Node* root){
    if(root == NULL) return ;
    if(root->left==NULL&&root->right == NULL) return ;
    if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right!=NULL))
          sum+=root->val;
    count_sum(root->left);
    count_sum(root->right);
    return ;
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
  sum=0;
  count_sum(root);
cout<<sum<<endl;
    return 0;
}


// //                                IN-ORDER(LEFT,ROOT,RIGHT)
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// int sum ;
// void count_sum(Node* root){
//     if(root == NULL) return ;
//     if(root->left==NULL&&root->right == NULL) return ;
//     if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right!=NULL))
//           sum+=root->val;
//     count_sum(root->left);
//     count_sum(root->right);
     
//     return ;
// }
// Node* Input_BT(){
//      int val;cin>>val;
//      Node* root = new Node(val);
//      queue<Node*>q;
//     q.push(root);
//     while(!q.empty()){
//         Node* p = q.front();
//         q.pop();
//         Node* lc;
//         Node* rc;
//         int l,r;cin>>l>>r;
//         if(l==-1) lc = NULL;
//         else lc = new Node(l);
//         if(r==-1) rc = NULL;
//         else rc = new Node(r);
//        p->left = lc;
//        p->right = rc;
//        if(p->left) q.push(p->left);
//        if(p->right) q.push(p->right);
//     }
//     return root;
// }
// int main(){ 
//   Node* root = Input_BT();
//   sum=0;
//   count_sum(root);
// cout<<sum<<endl;
//     return 0;
// }

// //                                POST-ORDER(LEFT,ROOT,RIGHT)
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// int sum ;
// void count_sum(Node* root){
//     if(root == NULL) return ;
//     if(root->left==NULL&&root->right == NULL) return ;
//     count_sum(root->left);
//     count_sum(root->right);
//      if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right!=NULL))
//           sum+=root->val;
//     return ;
// }
// Node* Input_BT(){
//      int val;cin>>val;
//      Node* root = new Node(val);
//      queue<Node*>q;
//     q.push(root);
//     while(!q.empty()){
//         Node* p = q.front();
//         q.pop();
//         Node* lc;
//         Node* rc;
//         int l,r;cin>>l>>r;
//         if(l==-1) lc = NULL;
//         else lc = new Node(l);
//         if(r==-1) rc = NULL;
//         else rc = new Node(r);
//        p->left = lc;
//        p->right = rc;
//        if(p->left) q.push(p->left);
//        if(p->right) q.push(p->right);
//     }
//     return root;
// }
// int main(){ 
//   Node* root = Input_BT();
//   sum=0;
//   count_sum(root);
// cout<<sum<<endl;
//     return 0;
// }
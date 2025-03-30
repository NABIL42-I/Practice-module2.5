#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
  vector<pair<string,int>>v(n);
  for(int i = 0;i<n;i++){
    cin>>v[i].first>>v[i].second;
  }
  cout<<"Your Output is here :\n";
  for(int i = 0;i<n;i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
  }
return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  vector<string> st;

  while(t--){
    int x,y,a;
    cin>>x>>y>>a;
    int ans = 5*a;
    int sum =0, i =0;
    while( sum < ans){
      if(i % 2 ==0){
        sum += x;
      }else{
        sum += y;
      }
      i++;
}
     if((i-1) % 2 == 0){
      st.push_back("NO");
     }else{
      st.push_back("YES");
     }
    
  }
  for(string s: st){
    cout<<s<<endl;
  }

    return 0;
}
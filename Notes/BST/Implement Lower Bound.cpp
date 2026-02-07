#include <bits/stdc++.h>
using namespace std;

class findValue{
  public:
  int findFloor(int arr[], int x, int n){
    int low = 0; int high = n-1;
    int ans = -1;
    
    while(low <= high){
      int mid = (low + high)/2;
      if(arr[mid] <= x){
        ans = arr[mid];
        low = mid+1;
      }else{
        high = mid - 1;
      }
    }
    return ans;
  }
  
  int findCeil(int arr[], int x, int n){
      int low = 0; int high = n-1;
    int ans = -1;

    while(low <= high){
      int mid = (low + high)/2;
      if(arr[mid] >= x){
        ans = arr[mid];
        high = mid-1;
      }else{
        low = mid+1;
      }
    }
    return ans;
  }
pair<int, int> findFloorCeil(int arr[], int n, int x){
    int m = findFloor(arr, x, n); 
    int q = findCeil(arr, x, n);   
    return make_pair(m, q);
}

};

int main() {
    int arr[] = {1,2,3, 4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    findValue value;
    pair<int, int> ans = value.findFloorCeil(arr, n, x);
    cout<<"The floor and ceil are "<<ans.first<<" "<<ans.second;

    return 0;
}
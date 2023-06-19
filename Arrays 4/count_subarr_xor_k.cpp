/*
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5

Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef unordered_map<int, int> um;
typedef pair<int,int> pi;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)

int subarraysXor(vi arr, int k){
  um mp;
  int n = arr.size(), xr = 0, count = 0 ;
  FOR(i, n){
    xr ^= arr[i];
    count += mp[xr ^ k];
    mp[xr] ++;
    if(xr == k){
      count += 1;
    }
  }
  // for(auto i: mp){
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  return count;
}

void solve()
{
  int n;
  cin>>n;
  int k;
  cin>>k;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  cout<<"\n"<<subarraysXor(arr, k);
}

int main() {
	ios::sync_with_stdio(0);
  cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
		// cout<<"\n";
	}

	return 0;
}


/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)
int longest_consecutive_seq(vi arr){
  int n = arr.size(), max_count = 0;
  set<int> h_set;
  FOR(i, n){
    h_set.insert(arr[i]);
  }
  FOR(i, n){
    int num = arr[i], count = 0;
    if(!h_set.count(num -1)){
      while(h_set.count(num + 1)){
        num ++;
        count++;
      }
      max_count = max(count+1, max_count);
    }
  }
  return max_count;
}

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  cout<<longest_consecutive_seq(arr);
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
		cout<<"\n";
	}

	return 0;
}


/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
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

vi two_sum(vi nums, int sum){
  int n = nums.size();
  vector<pair<int, int> > arr(n);
  vi ans(2);

  FOR(i, n){
    arr[i] = MP(nums[i], i);
  }
  sort(arr.begin(), arr.end());
  int i =0, j = n-1;
  while( i < j){
    if((long long)(arr[i].first) + (long long)arr[j].first> sum){
      j--;
    }
    else if((long long)(arr[i].first) + (long long)arr[j].first< sum){
      i++;
    }
    else{
      ans[0] = arr[i].second;
      ans[1] =arr[j].second;
      break;
    }
  }
  return ans;
}

void solve()
{
  int n;
  cin >>n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  int sum;
  cin>>sum;
  vi ans = two_sum(arr, sum);
  cout<<ans[0]<<" "<<ans[1];
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


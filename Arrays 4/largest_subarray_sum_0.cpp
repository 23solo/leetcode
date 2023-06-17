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

int largest_subarray_sum_0(vi arr){
  int n = arr.size();
  unordered_map<int, int> mp;
  int sum =0, max_sub_array = 0;
  FOR(i, n){
    sum += arr[i];
    if(sum == 0){
      max_sub_array = i + 1;
    }
    else{
      if(mp.find(sum) != mp.end()){
        max_sub_array = max(max_sub_array, i - mp[sum]);
      }
      else{
        mp[sum] = i;
      }
    }
  }
  return max_sub_array;
}

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  cout<<largest_subarray_sum_0(arr);

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


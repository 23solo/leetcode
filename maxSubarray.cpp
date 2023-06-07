


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++) 

ll max_subarray(vll arr, int n){
	ll sum = arr[0], max_sum = arr[0];
	FOR(i, n){
		if (i == 0){
			continue;
		}
		sum = max(arr[i], sum+arr[i]);
    max_sum = max(sum, max_sum);
	}
	return max_sum;
}

void solve()
{
  int n;
  cin>>n;
  vll arr(n);
  FOR(i, n){
	  cin>>arr[i];
  }
  cout<<max_subarray(arr, n);
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


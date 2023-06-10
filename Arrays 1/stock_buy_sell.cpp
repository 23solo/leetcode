


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

int stock_max_profit(vi arr, int n){
	int curr_val = arr[0];
	int max_profit = 0;
	for(int i = 1;i <n; i++){
		if(arr[i] <= curr_val){
			curr_val = arr[i];
		}
		else{
			max_profit = max(max_profit, arr[i] - curr_val);
		}
	}
	return max_profit;
}

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
	cin>>arr[i];
  }
  cout<<stock_max_profit(arr, n);
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


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

pi missing_repeat_no(vi arr){
	int n = arr.size();
	ll sum_arr = accumulate(arr.begin(), arr.end(), 0);
	ll sum_n = (n * (n +1)) /2;
	int diff = sum_arr - sum_n;
	ll sum_sq_arr = 0;
	FOR(i, n){
		sum_sq_arr += arr[i] * arr[i];
	}
	ll sum_sq_n = (n * (n+1) * ((2* n) + 1)) /6;
	int repeat_no = (((sum_sq_arr - sum_sq_n) / diff) + diff)/2 ;
	int missing_no = (repeat_no - diff);
	return MP(missing_no, repeat_no);
}
void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
	cin>>arr[i];
  }
  pi ans = missing_repeat_no(arr);
  cout<<"missing no is "<< ans.first<<" repeating is "<<ans.second;
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


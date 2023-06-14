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

double x_pow_n(double x, int n){
  bool is_less_than_0 = false;
  if ( n< 0){
    is_less_than_0 = true;
    n = -1 *n;
  }
  double ans= 1.0, xx = x;
  while(n){
    if(n % 2 == 0){
      n /= 2;
      xx = xx * xx;
    }
    else{

      n -= 1;
      ans *= xx;

      // cout<<"here"<<ans<<endl;
    }
  }
  if(is_less_than_0){
    cout<<ans<<endl;
    return double(1.0)/double(ans);
  }
  return ans;
}

void solve()
{
  // double x;
  // int n;
  // cin>>x>>n;
  cout<<x_pow_n(2.0000, -2);
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


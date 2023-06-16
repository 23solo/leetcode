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

int uniq_paths(int m, int n){   
  double ans = 1;
  int n1 = m+n-2;
  int r = min(m, n)-1;
  FOR(i, r){
    ans *= (n1-i);
    ans /= (i+1);
  }
  return int(ans);
}

void solve()
{
  int m, n;
  cin>>m>>n;
  cout<<uniq_paths(m, n);
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

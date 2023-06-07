


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

vll generate_pascal_row(int n){
	vll temp;
	ll numerator = 1, denominator= 1;
	temp.push_back(1);
	FOR(i, n){
		numerator *= n-i;
		denominator *= i+1;
		temp.push_back(numerator/ denominator);
	}
	return temp;
}

vector<vll> pascals_triangle( int n ){
	vector<vll> ans;
	for(int i = 0; i< n; i++){
		vll temp;
		temp = generate_pascal_row(i);
		ans.push_back(temp);
	}
	for(auto i: ans){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return ans;
}

void solve()
{
  int n ;
  cin >> n;
  pascals_triangle(n);
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


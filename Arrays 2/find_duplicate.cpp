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

int findDuplicate(vi arr){
	int slow_pointer = arr[0], fast_pointer = arr[0];
	do {
		slow_pointer = arr[slow_pointer];
		fast_pointer = arr[arr[fast_pointer]];
	} while (slow_pointer != fast_pointer);
	fast_pointer = arr[0];
	while(slow_pointer != fast_pointer){
		slow_pointer = arr[slow_pointer];
		fast_pointer = arr[fast_pointer];
	}
	return fast_pointer;
}


void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
	cin>>arr[i];
  }
  cout<<findDuplicate(arr);
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





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

void swap_with_current_state(vi &curr_index, vi &arr, int index){
	for(int i = arr[index]; i<3; i++){
		curr_index[i]++;
	}
	swap(arr[index], arr[curr_index[arr[index]]]);
	if (arr[index] == 1){
		swap(arr[index], arr[curr_index[arr[index]]]);
	}
}

void sort_0_1_2(vi arr, int n){

	vi curr_index(3);
	FOR(i, 3){
		curr_index[i] = -1;
	}
	FOR(i, n){
		swap_with_current_state(curr_index, arr, i);
	}
	for(auto i : arr){
		cout<<i<< " " ;
	}
}

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i,n){
	cin>>arr[i];
  }
  sort_0_1_2(arr, n);
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


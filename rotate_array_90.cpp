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

void reverse(vi &arr, int j){
	int i = 0;
	while(i < j){
		swap(arr[i++], arr[j--]);
	}
}

void rotate_array_90(vector<vi> &arr){
	int n = arr.size();
	//  transpose the array
	FOR(i, n){
		for(int j =0;j < i; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
	FOR(i,n){
		reverse(arr[i], n-1);
	}
  // PRINT THE ARRAY
	// for(auto i : arr){
	// 	for(auto j : i){
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
}

void solve()
{
  int n, ele;
  cin>>n;
  vector<vi> arr(n);
  FOR(i, n){
    FOR(j, n){
      cin>>ele;
      arr[i].push_back(ele);
    }
  }
  rotate_array_90(arr);
  
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


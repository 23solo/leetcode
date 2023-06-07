


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++) 

vi reverse(vi arr, int i, int j){
	while(i < j ){
		swap(arr[i++], arr[j--]);
	}
	return arr;
}

vi next_permutation(vi arr, int n){
	int index = -1;
	for(int i = n-2; i>=0; i--){
		if(arr[i] < arr[i+1]){
			index = i;
			break;
		}
	}
	if(index == -1){
		return reverse(arr, 0, n-1);
	}
	for(int i = n-1; i>index; i--){
		if(arr[i] > arr[index]){
			swap(arr[i], arr[index]);
			break;
		}
	}
	return reverse(arr, index+1, n-1);

}

void solve()
{
  vi arr;
  int n;
  cin>> n;
	FOR(i,n){
		int element;
		cin>>element;
		arr.push_back(element);
	}
	arr = next_permutation(arr, n);
	for(auto i : arr){
		cout<<i <<" ";
	}
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


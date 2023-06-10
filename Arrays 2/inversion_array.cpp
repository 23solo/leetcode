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

int merge(vi &arr, int i, int mid, int j){
	int arr_index = i, count =0;
	int left = mid - i +1;
	int right = j - mid ;
	vi left_array(left), right_array(right);
	FOR(i, left){
		left_array[i] = arr[arr_index + i];
	}
	FOR(i, right){
		right_array[i] = arr[i + mid + 1];
	}
	int left_index = 0, right_index = 0;
	while( left_index < left && right_index < right){
		if( left_array[left_index] <= right_array[right_index] ){
			arr[arr_index++] = left_array[left_index++];
		}
		else{
      count += left - left_index;
			arr[arr_index++] = right_array[right_index++];
		}
	}
  while(left_index < left){
    arr[arr_index++] = left_array[left_index++];
  }
  while(right_index < right ){
    arr[arr_index++] = right_array[right_index++];
  }
  return count;
}

int merge_sort(vi &arr, int i, int j){
	int count = 0;
	if(i >= j){
		return count;
	}
	int mid = (i+j)/2;
	count += merge_sort(arr, i, mid);
	count += merge_sort(arr, mid+1, j);
	count += merge(arr, i, mid, j);
  return count;
}

void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i,n){cin>>arr[i];}
  cout<<merge_sort(arr, 0, n-1);
	// for(auto i : arr ){
	// 	cout<<i<< " ";
	// }
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


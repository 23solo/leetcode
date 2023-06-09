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

/*
First approach iss sto take highest element in the left array and smallesst in the right array.. 
if left_array[i] > right_array[j]
then swap
	 decrement i and increment j
once the above is done sort both arraysss and that wiill be the answer
*/

void merge_array_inplace(vi &left_array, vi &right_array){
  int m = left_array.size(), n = right_array.size();
  int len = m+n;
  int mid = len/2 + len%2;
  while(mid > 0){
    int left = 0, right = mid;
    while(right < len){
      if( left < m && right >= m){
        if (left_array[left] > right_array[right - m]){
          swap(left_array[left], right_array[right - m]);
        }
      }
      else if (left >= m ){
        if (right_array[left - m] > right_array[right - m]){
          swap(right_array[left - m] , right_array[right - m]);
        }
      }
      else {
         if (left_array[left] > left_array[right]){
          swap(left_array[left], left_array[right]);
         }
      }
      ++left;
      ++right;
    }
    if ( mid == 1 ){
      return;
    }
    mid = (mid / 2 + mid %2);
  }
}

void solve()
{
  int m, n;
  cin>>m>>n;
  vi left_array(m), right_array(n);
  FOR(i, m){
	  cin>>left_array[i];
  }
  FOR(i, n){
	  cin>>right_array[i];
  }
  merge_array_inplace(left_array, right_array);
  for(auto i : left_array){
    cout<< i<<" ";
  }
  for(auto i : right_array){
    cout<< i<<" ";
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


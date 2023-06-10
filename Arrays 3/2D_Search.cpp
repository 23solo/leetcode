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

bool isElementPresent(vvi arr, int rows, int cols, int ele){
  int current_ele = arr[0][cols-1];
  int i = 0, j = cols-1, cnt = 0;
  while(i >= 0 && i < rows && j >= 0 && j< cols ){
    cnt++;
    if(arr[i][j] > ele){
      j--;
    }
    else if(arr[i][j] < ele){
      i++;
    }
    else{
      // cout<<cnt<<endl;
      return true;
    }
  }
  // cout<<cnt<<endl;
  return false;
}

void solve()
{
  int rows, cols;
  cin>>rows>>cols;
  vvi arr;
  FOR(i, rows){
    vi sub_arr;
    FOR(j, cols){
      int ele;
      cin>>ele;
      sub_arr.push_back(ele);
    }
    arr.push_back(sub_arr);
  }
  int ele_to_find;
  cin>>ele_to_find;
  cout<< isElementPresent(arr, rows, cols, ele_to_find);

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


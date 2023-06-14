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

vi majority_element(vi arr){
  int n = arr.size();
  int ele1 = 0, count_ele_1=0, ele2 = 0, count_ele_2 = 0;
  FOR(i, n){
    if (count_ele_1 == 0 && arr[i] != ele2){
      ele1 = arr[i];
      count_ele_1++;
    }
    else if(count_ele_2 == 0 && arr[i]!=ele1){
      ele2 = arr[i];
      count_ele_2++;
    }
    else if(ele1 == arr[i]){
      count_ele_1 ++;
    }
    else if(ele2 == arr[i]){
      count_ele_2++;
    }
    else{
      count_ele_1--;
      count_ele_2--;
    }
  }
  vi ans;
  count_ele_1 = 0, count_ele_2 =0;
  FOR(i, n){
    if(arr[i] == ele1){
      count_ele_1++;
    }
    else if(arr[i] == ele2){
      count_ele_2++;
    }
  }
  if(count_ele_1 > n/3){
    ans.push_back(ele1);
  }
  if(count_ele_2 > n/3){
    ans.push_back(ele2);
  }
  return ans;
}

void solve()
{
  int n;
  cin>> n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  vi ans = majority_element(arr);
  for(auto i : ans){
    cout<<i<<" ";
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


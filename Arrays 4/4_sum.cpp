/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

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

vector<vector<int> > four_sum(vi arr, int target){ // [-2 -1 -1 1 1 2 2]
  int n = arr.size();

  vector<vector<int> > ans;
  sort(arr.begin(), arr.end());
  FOR(i, n-3){
    if(i > 0 && arr[i] == arr[i-1]){
      continue;
    }
    for(int j = i+1; j <n -2; j++){
      if(j > i+1 && arr[j] == arr[j-1]){
        continue;
      }
      // cout<<arr[i]<<" "<<arr[j]<<endl;
      int k = j+1, l = n-1;
      while(k < l){
        vi temp_ans;
        if(k > j+1 && arr[k] == arr[k-1]){
          while(k < l && arr[k] == arr[k -1]){
            k++;
          }
        }
        if(l < n-1 && arr[l] == arr[l+1]){
          while(k < l && arr[l] == arr[l +1]){
            l--;
          }
        }
        if(k< l && (long long)(arr[i] + arr[j] + arr[k] + arr[l]) < target){
          k ++;
        }
        else if(k< l && (long long)(arr[i] + arr[j] + arr[k] + arr[l]) > target){
          l --;
        }
        else if(k< l){
          temp_ans.push_back(arr[i]);
          temp_ans.push_back(arr[j]);
          temp_ans.push_back(arr[k]);
          temp_ans.push_back(arr[l]);
          ans.push_back(temp_ans);
          l--;
          k++;
        }
      }
    }
  }

  return ans;
}

void solve()
{
  int n;
  cin >>n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  int sum;
  cin>>sum;
  vector<vector< int> > ans = four_sum(arr, sum);
  for(auto i : ans){
    for (auto j: i){
      cout<<j<<" ";
    }
    cout<<"\n";
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


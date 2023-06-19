#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef unordered_map<char, int> um;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)

int lengthOfLongestSubstring(string s){
  um mp;
  int n = s.size(), ans = 0, count =0, index = -1;
  bool flag = true;
  FOR(i, n){
    if(mp.find(s[i]) != mp.end()){
      flag = false;
      if( index != -1 && index < mp[s[i]]){
        index = mp[s[i]];
        ans = max(ans, i - mp[s[i]]);
        ans = max(ans, count);
        count = i - mp[s[i]];
      }
      else if(index == -1){
        ans = max(ans, i - mp[s[i]]);
        ans = max(ans, count);
        count = i - mp[s[i]] ;
        index = mp[s[i]];
      }
      else{
        count ++;
      }
    }
    else{
      count ++;
    }
    mp[s[i]] = i;
  }
  if (flag){
    return n;
  }
  return max(ans,count);

}

void solve()
{
  string s;
  cin>>s;
  cout<<lengthOfLongestSubstring(s);
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


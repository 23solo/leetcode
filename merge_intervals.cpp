#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef vector<pair<int, int> > vp;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)

vvi merge_intervals(vvi pair_intervals){
	int n = pair_intervals.size();
	sort(pair_intervals.begin(), pair_intervals.end());
	vvi ans;
	vi current_pair = pair_intervals[0];
	FOR(i, n){
		if(i == 0){
			continue;
		}
		if(pair_intervals[i][0] <= current_pair[1]){
			if(pair_intervals[i][1] > current_pair[1]){
				current_pair[1] = pair_intervals[i][1];
			}
		}
		else{
			ans.push_back(current_pair);
			current_pair = pair_intervals[i];
		}
	}
	ans.push_back(current_pair);
	return ans;
}

void solve()
{
	int n, first, second;
	cin>> n;
	vvi pair_intervals;
	FOR(i, n){
		vi temp;
		cin>>first>>second;
		temp.push_back(first);
		temp.push_back(second);
		pair_intervals.push_back(temp);
	}
	vvi ans = merge_intervals(pair_intervals);
	for(auto i : ans){
		cout<<i[0]<<" "<<i[1]<<endl;
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


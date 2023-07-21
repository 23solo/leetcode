/*
There is one meeting room in a firm. You are given two arrays, start and end each of size N.
For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]
will denote the ending time of the ith meeting. Find the maximum number of meetings that can
be accommodated if only one meeting can happen in the room at a  particular time. Print the
order in which these meetings will be performed.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef unordered_map<int, int> um;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for (int i = 0; i < N; i++)

int maxMeetings(vi start, vi end)
{
  int n = start.size();
  vector<pi> index_pairs(n);
  FOR(i, n)
  {
    index_pairs[i] = MP(end[i], i);
  }
  sort(index_pairs.begin(), index_pairs.end());
  int end_time = index_pairs[0].first, maxMeetings = 1;
  for (int i = 1; i < n; i++)
  {
    if (start[index_pairs[i].second] > end_time)
    {
      end_time = index_pairs[i].first;
      maxMeetings++;
    }
  }
  return maxMeetings;
}

void solve()
{
  int n;
  cin >> n;
  vi start(n), end(n);
  FOR(i, n)
  {
    cin >> start[i];
  }
  FOR(i, n)
  {
    cin >> end[i];
  }
  cout << maxMeetings(start, end);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

  return 0;
}

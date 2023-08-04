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

int LCS(string s1, string s2, int i, int j)
{
  // Base condn
  if (i == s1.size() || j == s2.size())
  {
    return 0;
  }

  if (s1[i] == s2[j])
  {
    return 1 + LCS(s1, s2, i + 1, j + 1);
  }
  return max(LCS(s1, s2, i, j + 1), LCS(s1, s2, i + 1, j));
}

void solve()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << LCS(s1, s2, 0, 0);
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

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef unordered_map<int, int> um;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for (int i = 0; i < N; i++)

bool isPalindrome(string s, int i, int j)
{
  while (i < j)
  {
    if (s[i] != s[j])
    {
      return false;
    }
    i++, j--;
  }
  return true;
}
void getAllPartition(string s, int index, vs &ans)
{

  for (int i = index; i < s.size(); i++)
  {
    if (isPalindrome(s, index, i))
    {
      ans.push_back(s.substr(index, i - index + 1));
      getAllPartition(s, i + 1, ans);
    }
  }
}

void solve()
{
  string s;
  cin >> s;
  vs ans;
  getAllPartition(s, 0, ans);
  for (auto i : ans)
  {
    cout << i << " ";
  }
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

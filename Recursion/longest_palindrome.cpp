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

string maxPalindrome(string s, int i, int j, vector<vector<string>> &ans)
{
  if (!ans[i][j].empty())
  {
    // cout << "here";
    return ans[i][j];
  }
  if (i < 0 || j < 0)
  {
    return "";
  }
  if (!isPalindrome(s, i, j))
  {
    string first = maxPalindrome(s, i + 1, j, ans);
    string second = "";
    if (first.size() != j - i)
    {
      second = maxPalindrome(s, i, j - 1, ans);
    }

    if (first.size() > second.size())
    {
      ans[i][j] = first;
      return first;
    }
    ans[i][j] = second;
    return second;
  }
  else
  {
    return s.substr(i, j - i + 1);
  }
}

void solve()
{
  string s;
  cin >> s;
  vector<vector<string>> ans(1001);
  for (int i = 0; i < 1001; i++)
  {
    vector<string> temp(1001);
    for (int j = 0; j < 1001; j++)
    {
      temp[j] = "\0";
    }
    ans[i] = temp;
  }
  // cout << ans[0].size() << " " << ans.size();
  cout << maxPalindrome(s, 0, s.size() - 1, ans);
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

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

void getSubsetSum(vi arr, vi temp_ans, int n, vvi &ans)
{
  // Base condition
  if (n >= arr.size())
  {
    ans.push_back(temp_ans);
    return;
  }
  if (arr[n] != arr[n - 1])
  {
    getSubsetSum(arr, temp_ans, n + 1, ans);
    temp_ans.push_back(arr[n]);
    getSubsetSum(arr, temp_ans, n + 1, ans);
  }
  else
  {
    getSubsetSum(arr, temp_ans, n + 1, ans);
    temp_ans.push_back(arr[n]);
    ans.push_back(temp_ans);
    return;
  }
}

void solve()
{
  int n;
  cin >> n;
  vvi ans;
  vi arr(n), temp;
  FOR(i, n)
  {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  getSubsetSum(arr, temp, 0, ans);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
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

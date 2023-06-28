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

int totalWaterTrap(vi arr)
{
  int n = arr.size();
  vi left(n), right(n);
  int greatest_ele = 0, ans = 0;
  FOR(i, n)
  {
    greatest_ele = max(greatest_ele, arr[i]);
    left[i] = greatest_ele;
  }
  greatest_ele = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    greatest_ele = max(greatest_ele, arr[i]);
    right[i] = greatest_ele;
  }
  FOR(i, n)
  {
    ans += min(left[i] - arr[i], right[i] - arr[i]);
  }
  return ans;
}

void solve()
{
  int n;
  cin >> n;
  vi arr(n);
  FOR(i, n)
  {
    cin >> arr[i];
  }
  cout << totalWaterTrap(arr);
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

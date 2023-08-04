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

int coinChangeWays(vi arr, int target, int i)
{
  // Base condn
  if (target == 0)
  {
    return 1;
  }
  if (i == arr.size())
  {
    return 0;
  }
  int res = 0;
  if (target >= arr[i])
  {
    res = coinChangeWays(arr, target - arr[i], i);
  }
  res += coinChangeWays(arr, target, i + 1);
  return res;
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
  int sum;
  cin >> sum;
  cout << coinChangeWays(arr, sum, 0);
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

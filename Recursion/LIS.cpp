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

int LIS(vi arr, int i)
{
  int ans = 0;
  if (i == arr.size())
  {
    return 0;
  }
  if (i > 0 && arr[i] > arr[i - 1])
  {
    ans = 1 + LIS(arr, i + 1);
  }
  return max(ans, LIS(arr, i + 1));
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
  cout << LIS(arr, 0) + 1;
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

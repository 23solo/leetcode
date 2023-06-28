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

int removeDuplicates(vi arr)
{
  int n = arr.size(), index = 1;
  FOR(i, n)
  {
    if (i == 0)
    {
      continue;
    }
    if (arr[i] != arr[i - 1])
    {
      arr[index++] = arr[i];
    }
  }
  // for (auto i : arr)
  // {
  //   cout << i << " ";
  // }
  return index;
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
  cout << removeDuplicates(arr);
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

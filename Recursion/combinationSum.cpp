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

void recurseFun(vi &candidates, vvi &ans, int target, int n, vi temp_ans)
{
  if (target == 0)
  {
    ans.push_back(temp_ans);
  }
  else if (target < 0 || n >= candidates.size())
  {
    return;
  }
  else
  {
    recurseFun(candidates, ans, target, n + 1, temp_ans);
    temp_ans.push_back(candidates[n]);
    recurseFun(candidates, ans, target - candidates[n], n, temp_ans);
  }
  return;
}

vvi combinationSum(vi &candidates, int target)
{
  vvi ans;
  vi temp;

  recurseFun(candidates, ans, target, 0, temp);
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
  int target;
  cin >> target;
  vvi ans = combinationSum(arr, target);

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

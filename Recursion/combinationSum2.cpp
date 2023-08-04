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

void recurseFun(int index, int target, vi &candidates, vvi &ans, vi temp_ans)
{
  if (target == 0)
  {
    ans.push_back(temp_ans);
    return;
  }
  for (int i = index; i < candidates.size(); i++)
  {
    if (i > index && candidates[i] == candidates[i - 1])
      continue;
    if (candidates[i] > target)
      break;
    temp_ans.push_back(candidates[i]);
    recurseFun(i + 1, target - candidates[i], candidates, ans, temp_ans);
    // temp_ans.pop_back();
  }
}

vvi combinationSum(vi &candidates, int target)
{
  vvi ans;
  vi temp;
  sort(candidates.begin(), candidates.end());
  recurseFun(0, target, candidates, ans, temp);
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

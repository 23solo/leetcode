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
// Creating a ListNode
class ListNode
{
public:
  int val;
  ListNode *next;
};

ListNode *addNode()
{
  ListNode *vNodes;
  int m;
  cout << "Enter size of linked list ";
  cin >> m;

  ListNode *list1, *temp;
  FOR(i, m)
  {
    int val;
    cin >> val;
    ListNode *newNode = new ListNode();
    newNode->val = val;
    if (i == 0)
    {
      list1 = newNode;
      temp = list1;
      continue;
    }
    temp->next = newNode;
    temp = temp->next;
  }
  return list1;
}

void deleteGivenNode(ListNode *node)
{
  if (node != NULL && node->next != NULL)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
  while (node != NULL)
  {
    cout << node->val;
    node = node->next;
  }
}

void solve()
{
  ListNode *list = addNode();
  int node;
  cout << "Enter node to remove \n";
  cin >> node;
  while (list->val != node)
  {
    list = list->next;
  }
  deleteGivenNode(list);
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

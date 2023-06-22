/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
*/
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

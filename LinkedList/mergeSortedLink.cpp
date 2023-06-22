/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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

vector<ListNode *> addNode()
{
  vector<ListNode *> vNodes;
  int m, n;
  cout << "Enter size of both linked list `m`, `n`";
  cin >> m >> n;

  ListNode *list2, *list1, *temp;
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
    // cout << newNode->val;
    temp->next = newNode;
    temp = temp->next;
  }
  FOR(i, n)
  {
    int val;
    cin >> val;
    ListNode *newNode = new ListNode();
    newNode->val = val;
    if (i == 0)
    {
      list2 = newNode;
      temp = list2;
      continue;
    }
    temp->next = newNode;
    temp = temp->next;
  }
  vNodes.push_back(list1);
  vNodes.push_back(list2);
  return vNodes;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  ListNode *head, *prev;
  if (list1 == NULL)
  {
    return list2;
  }
  if (list2 == NULL)
  {
    return list1;
  }
  if (list1->val < list2->val)
  {
    head = list1;
    prev = list1;
    list1 = list1->next;
  }
  else
  {
    head = list2;
    prev = list2;
    list2 = list2->next;
  }
  while (list1 != NULL && list2 != NULL)
  {
    if (list1->val < list2->val)
    {
      prev->next = list1;
      prev = list1;
      list1 = list1->next;
    }
    else
    {
      prev->next = list2;
      prev = list2;
      list2 = list2->next;
    }
  }
  if (list1 == NULL)
  {
    prev->next = list2;
  }
  else
  {
    prev->next = list1;
  }
  return head;
}
void solve()
{

  vector<ListNode *> vNodes = addNode();

  ListNode *head = mergeTwoLists(vNodes[0], vNodes[1]);
  while (head != NULL)
  {
    cout << head->val << " -> ";
    head = head->next;
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

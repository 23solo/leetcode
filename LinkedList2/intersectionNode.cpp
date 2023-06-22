/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
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
  cout << "Enter size of both linked list `m`, `n`\n";
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

ListNode *interSectionNode(ListNode *l1, ListNode *l2, int count)
{
  while (count)
  {
    l1 = l1->next;
    count--;
  }
  while (l1->val != l2->val)
  {
    l1 = l1->next;
    l2 = l2->next;
  }
  return l1;
}

ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
{
  ListNode *head_l1 = l1, *head_l2 = l2;
  int count = 0;
  while (l1 != NULL && l2 != NULL)
  {
    l1 = l1->next;
    l2 = l2->next;
    if (l1 == l2)
    {
      return l1;
    }
  }

  if (l1 != NULL)
  {
    while (l1 != NULL)
    {
      count++;
      l1 = l1->next;
    }
    return interSectionNode(head_l1, head_l2, count);
  }
  else
  {
    while (l2 != NULL)
    {
      count++;
      l2 = l2->next;
    }
    return interSectionNode(head_l2, head_l1, count);
  }
}
void solve()
{

  vector<ListNode *> vNodes = addNode();

  ListNode *head = getIntersectionNode(vNodes[0], vNodes[1]);
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

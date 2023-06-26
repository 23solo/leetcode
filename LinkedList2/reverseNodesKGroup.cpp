/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
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
ll getLengthOfNodes(ListNode *head)
{
  ll count = 0;
  while (head != NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
  ll len = getLengthOfNodes(head);
  ll total_groups = len / k;
  ListNode *dummy = head, *cur = head, *prev, *nex;
  FOR(i, total_groups)
  {
    int numOfOperations = k;
    prev->next = cur;
    nex = cur->next;
    while (--numOfOperations)
    {
      cur->next = nex->next;
      nex->next = prev->next;
      prev->next = nex;
      nex = cur->next;
    }
    if (i == 0)
    {
      dummy = prev->next;
    }
    prev = cur;
    cur = prev->next;
  }
  return dummy;
}

void solve()
{
  ListNode *list = addNode();
  int k;
  cin >> k;
  cout << "Her";
  ListNode *head = reverseKGroup(list, k);
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

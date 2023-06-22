/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

void addSingleList(ListNode *l1, ListNode *prev, long long carry)
{
  long long sum = 0;
  while (l1 != NULL)
  {
    ListNode *temp = new ListNode();
    sum = l1->val + carry;
    carry = sum / 10;
    temp->val = sum % 10;
    prev->next = temp;
    prev = temp;
    l1 = l1->next;
  }
  if (carry)
  {
    ListNode *temp = new ListNode();
    temp->val = carry;
    prev->next = temp;
    prev = temp;
    carry = 0;
  }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *head = l1, *prev;
  if (l1 == NULL)
  {
    return l2;
  }
  if (l2 == NULL)
  {
    return l1;
  }
  long long sum = 0, carry = 0, mod;
  while (l1 != NULL && l2 != NULL)
  {
    sum = l1->val + l2->val + carry;
    carry = sum / 10;
    l1->val = sum % 10;
    prev = l1;
    l1 = l1->next;
    l2 = l2->next;
  }
  if (l1 == NULL)
  {
    addSingleList(l2, prev, carry);
  }
  else if (l2 == NULL)
  {
    addSingleList(l1, prev, carry);
  }
  return head;
}
void solve()
{

  vector<ListNode *> vNodes = addNode();

  ListNode *head = addTwoNumbers(vNodes[0], vNodes[1]);
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

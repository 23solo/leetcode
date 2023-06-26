/*
Given the head of a singly linked list, return true if it is a
palindrome or false otherwise.
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

ListNode *reverseLinkedList(ListNode *prev, ListNode *head)
{
  if (prev == NULL)
  {
    return prev;
  }
  bool flag = true;
  while (head != NULL)
  {
    ListNode *temp = head->next;
    if (flag)
    {
      head->next = prev;
      prev->next = NULL;
      prev = head;
      head = temp;
      flag = false;
    }
    else
    {
      head->next = prev;
      prev = head;
      head = temp;
    }
  }
  return prev;
}

vector<ListNode *> getMid(ListNode *head)
{

  vector<ListNode *> vNode(2);
  vNode[0] = NULL;
  vNode[1] = NULL;
  if (head == NULL)
  {
    return vNode;
  }
  ListNode *fast = head, *slow = head, *prev = head;
  bool flag = true;
  while (fast != NULL && fast->next != NULL)
  {
    if (!flag)
    {
      prev = prev->next;
    }
    slow = slow->next;
    fast = fast->next->next;
    flag = false;
  }
  vNode[0] = prev;
  vNode[1] = slow;
  return vNode;
}

bool isPalindrome(ListNode *head)
{
  if (head == NULL || head->next == NULL)
  {
    return true;
  }
  if (head->next->next == NULL)
  {
    return (head->val == head->next->val);
  }
  vector<ListNode *> listNode = getMid(head);
  ListNode *lastNode = reverseLinkedList(listNode[0], listNode[1]);
  while (head != NULL && lastNode != NULL)
  {
    if (head->val != lastNode->val)
    {
      return false;
    }
    head = head->next;
    lastNode = lastNode->next;
  }
  return true;
}

void solve()
{
  ListNode *list = addNode();

  cout << isPalindrome(list);
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

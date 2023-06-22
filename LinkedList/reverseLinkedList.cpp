/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
  int value;
  ListNode *next;
};

ListNode *reverseLinkedList(ListNode *head)
{
  if (head->next == NULL)
  {
    return head;
  }
  ListNode *prev = head;
  head = head->next;
  prev->next = NULL;
  while (head != NULL)
  {
    ListNode *temp;
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}

void solve()
{
  ListNode *head;
  ListNode *one = NULL;
  ListNode *two = NULL;
  ListNode *three = NULL;

  // allocate 3 ListNodes in the heap
  one = new ListNode();
  two = new ListNode();
  three = new ListNode();

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect ListNodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // print the linked list value

  head = reverseLinkedList(one);
  while (head != NULL)
  {
    cout << head->value;
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

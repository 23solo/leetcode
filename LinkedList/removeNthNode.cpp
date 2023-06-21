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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
  ListNode *fast, *slow, *prev;
  int count = 0;
  fast = head;
  slow = head;
  prev = slow;
  while (fast != NULL && count != n)
  {
    count++;
    fast = fast->next;
  }
  while (fast != NULL)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next;
  }
  if (slow != NULL && prev != NULL)
  {
    prev->next = slow->next;
  }
  if (slow == prev)
  {
    return head->next;
  }
  return head;
}

void solve()
{
  ListNode *list = addNode();
  int n;
  cout << "Enter node to remove from end\n";
  cin >> n;
  ListNode *head = removeNthFromEnd(list, n);

  cout << "Updated Link is \n";
  while (head != NULL)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL";
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

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef unordered_map<int, int> um;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)
// Creating a ListNode
class ListNode {
  public:
  int value;
  ListNode* next;
};

ListNode* middleNode(ListNode* fast) {
        if(fast == NULL || fast -> next == NULL){
            return fast;
        }
        ListNode* slow = fast;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

void solve()
{
  ListNode* head;
  ListNode* one = NULL;
  ListNode* two = NULL;
  ListNode* three = NULL;


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

  ListNode* middle = middleNode(one);
  cout<<middle -> value;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
		cout<<"\n";
	}

	return 0;
}


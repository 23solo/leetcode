/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef vector<vector<int> > vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, N) for(int i =0; i<N; i++)

int merge(vi &arr, int i, int mid, int j){
  int count = 0;
  int left = mid -i +1 , right = j -mid;
  vll left_array(left), right_array(right);
  FOR(p, left){
    left_array[p] = arr[p + i];
  }
  FOR(p, right){
    right_array[p] = arr[p + mid +1];

  }
  // cout<<"\n Done"<<endl;
  int k = 0, l= 0, m = 0, n= 0;
  while(k<left && l < right){

    while(m < left){
      count += n;
      while(n < right){
        if(left_array[m] > 2 * right_array[n]){
          count ++;
          n ++;
        }
        else{
          break;
        }
      }
      m++;
    }

    if(left_array[k] < right_array[l]){
      arr[i++] = left_array[k++];
    }
    else{
      arr[i++] = right_array[l++];
    }
  }
  while(k<left){
    arr[i++] = left_array[k++];
  }

  while(l<right){
    arr[i++] = right_array[l++]; 
  }
  return count;
}


int merge_sort(vi &arr, int i, int j){
  int count = 0;
  if(i < j){
    int mid = (i+j)/2;
    count += merge_sort(arr, i, mid);
    count += merge_sort(arr, mid+1, j);
    count += merge(arr, i, mid, j);
  }
  return count;
}



int total_reverse_pairs(vi &arr){
  int n = arr.size();
  // Do merge sort and during merge add the condn for arr[i] > 2* arr[j]
  return merge_sort(arr, 0, n-1);
}


void solve()
{
  int n;
  cin>>n;
  vi arr(n);
  FOR(i, n){
    cin>>arr[i];
  }
  cout<<total_reverse_pairs(arr);
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





#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


int arr[1000][1000];
/*
	instead of using extra array let's use one index from the given array only (index 0)
	one edge case need to have an extra var maybe to store col0 or row0 value i'll go with col0
	[
		1 0 1 1     0 0 0 0
		1 0 0 1  => 0 0 0 0 
		0 1 1 1     0 0 0 0
			   ]
*/
void setMatrixZeroOptimalApproach(int m, int n){
	int col0 = 0;
	// let's traverse only first row and first column and check if 0 is present
	for(int  i = 0; i<n; i++){
		if(arr[0][i] == 0){
			arr[0][i] = -1;
			arr[0][0] = -1;
		}
	}
	for(int  i = 0; i<m; i++){
		if(arr[i][0] == 0){
			arr[i][0] = -1;
			col0 = -1;
		}
	}
	// Now loop for rest elements from 1 and consider row 0 and col 0 aas your extra arrays 
	for(int i = 1; i< m; i++){
		for (int j= 1 ; j< n; j++){
			if(arr[i][j] == 0){
				arr[0][j] = -1;
				arr[i][0] = -1;
			}
		}
	}
	cout<<"\nOp for Optimal Approach\n";
	for(int i = 0; i< m; i++){
		for (int j= 0 ; j< n; j++){
			if(j== 0){
				if(col0 == -1 || arr[i][j] == -1){
					cout<< 0<<" ";
				}
				else{
					cout<<arr[i][j]<<" ";
				}
			}
			else{
				if(arr[i][0] == -1 || arr[0][j] == -1){
					cout<<0<<" ";
				}
				else{
					cout<<arr[i][j]<<" ";
				}
			}
		}
		cout<<endl;
	}

}

void makeColumnRowZero(int row, int col, int m , int n){
	for(int i =0; i<n; i++){
		if(arr[row][i] != 0)
		{
			arr[row][i] = -1;
		}
	}
	for(int i =0; i<m; i++){
		if(arr[i][col] != 0)
		{
			arr[i][col] = -1;
		}
	}
}


// BetterApproach
// Take extra arrays with size of m and n and mark them with 0
void setMatrixZeroBetterApproach(int m, int n){

	int row[m], col[n];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	// we'll make these as one if we find a 0 in the particular row or col and use it later
	for(int i = 0; i< m; i++){
		for (int j= 0 ; j< n; j++){
			if(arr[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	cout<<"\nOp for Better approach is \n";
	for(int i = 0; i< m; i++){
		for (int j= 0 ; j< n; j++){
			if(row[i] || col[j] == 1){
				cout<<0<<" ";
			}
			else{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}

}


// Bruteforce
void setMatrixZeroBruteForce(int m, int n){
	for(int i= 0; i<m; i++){
		for (int j = 0; j< n; j++){
			if(arr[i][j] == 0){
				// fill the entire row and column with -1 except 0 as we might need it in next operations
				makeColumnRowZero(i, j, m, n);
			}
		}
	}
	cout<<"\nOp is \n";
	for(int i =0; i< m; i++){
		for (int j=0; j<n; j++){
			if (arr[i][j] == -1)
			{ cout<<0<<" ";}
			else{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

void solve()
{
	int m, n;
	cin>>m>>n;
	for(int i =0; i< m; i++){
		for (int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	// setMatrixZeroBruteForce(m, n);
	// setMatrixZeroBetterApproach(m, n); // Think for 10 mins else look for editorial
	setMatrixZeroOptimalApproach(m, n); // Think for 10 mins else look for editorial
}


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t =1 ;
	// cin >> t;
	while(t--) {
		solve();
		cout<<"\n";
	}

	return 0;
}


#include<iostream>
#include<vector>

#define vi vector<int>

using namespace std;

const int SIZE = 100; //size > n;
vi HASH_TABLE(SIZE, 0);

int main(){
	
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++){
		if(i == SIZE){
			break;
		}
		int index = a[i];
		while(HASH_TABLE[index] != 0){
			index = (index + 1) % SIZE;
		}
		HASH_TABLE[index] = a[i];
	}
	
	int cnt = 0;
	for(int i = 0; i < HASH_TABLE.size(); i++){
		if(k == HASH_TABLE[i]){
			cnt++;
		}
	}
	
	cout << cnt;

	
	return 0;
}

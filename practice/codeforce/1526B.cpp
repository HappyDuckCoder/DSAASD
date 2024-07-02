#include<iostream>
#include<vector>
#include<cstring>

#define vi vector<int>

using namespace std;


int dp[11111];

vi a = {11, 111, 1111, 11111};

void init(){
    memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= 10000; i++){
		for(int j : a){
			if(i - j >= 0 && dp[i - j]) 
                dp[i] = 1;
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

	init();

	int time; cin >> time;
	while(time--){
        int x; cin >> x;
        if(x >= 5000) cout << "YES\n";
        else if(dp[x]) cout << "YES\n";
        else cout << "NO\n";
    } 

    return 0;
}

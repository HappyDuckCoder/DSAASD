#include<iostream>
using namespace std;

string InterChangeSort(string s){
    string res = s;

    for(int i = 0; i < s.length(); i++)
        for(int j = i + 1; j < s.length(); j++)
            if(res[i] > res[j])
                swap(res[i], res[j]);

    return res;
}

int main(){

    string s; cin >> s;
    string t = InterChangeSort(s);

    int cnt = 0;

    for(int i = 0; i < s.length(); i++)
        if(s[i] != t[i])
            cnt++;

    cout << cnt << endl;
    
    return 0;
}
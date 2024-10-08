#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lowerbound(vector<int>& a, int x){
        int n = a.size();
        
        if(x < a[0]) return 0; 

        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2  + 1;
            if(a[m] > x) r = m - 1;
            else l = m;
        }

        return l;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();

        vector<int> res;

        int save = -1;

        save = lowerbound(arr, x);

        // cout << "save: " << save << endl;

        int left = save, right = save + 1;

        // res.push_back(arr[save]);
        // k--;

        while(k--){
            if(left == 0){
                res.push_back(arr[right++]);
            } 
            if(right == n){
                res.push_back(arr[left--]);
            }
            if(left > -1 && right < n){
                if(abs(arr[left] - x) < abs(arr[right] - x)){
                    res.push_back(arr[left]);
                    left--;
                } else if(abs(arr[left] - x) > abs(arr[right] - x)){
                    res.push_back(arr[right]);
                    right++;
                } else {
                    if(arr[left] < arr[right]){
                        res.push_back(arr[left]);
                        left--;
                    } else {
                        res.push_back(arr[right]);
                        right--;
                    }
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};


int main(){
    Solution s;
    vector<int> inp = {1,1,2,3,3,3,4,6,8,8};
    vector<int> res = s.findClosestElements(inp, 6, 1);
    for(auto i : res){
        cout << i << " ";
    }
    
    return 0;
}
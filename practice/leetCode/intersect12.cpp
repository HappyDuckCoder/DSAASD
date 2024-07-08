#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int sizeHash = 1001;
        vector<int> hash1(sizeHash, 0), hash2(sizeHash, 0); 

        vector<int> res;

        for(int i = 0; i < nums1.size(); i++){
            hash1[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            hash2[nums2[i]]++;
        }

        for(int i = 0; i < sizeHash; i++){
            if(hash1[i] != 0 && hash2[i] != 0){
                int tmp = min(hash1[i], hash2[i]);
                for(int k = 1; k <= tmp; k++)
                    res.push_back(i); 
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {4, 9, 5}; 
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> res = s.intersection(nums1, nums2);
    
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " "; 
    
    return 0;
}
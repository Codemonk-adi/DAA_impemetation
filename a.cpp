#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ctr=1;
        int temp;
        vector<int> mem(arr.size(),1);
        for(int i =1;i<arr.size();i++){
            int l = 0;
            int r = i-1;
            temp = 1;
            while(l<=r){
            if(arr[l]*arr[r] == arr[i]){
                if(l==r)
                temp+=mem[l]*mem[r];
                else
                temp+=2*mem[l]*mem[r];
            }
            l++;
            r--;
            }
            ctr+=temp;
            mem[i] = temp;
            ctr = ctr %(int)(1e9+7);
        }
        return ctr;

        
    }
};

int main(){
    vector<int> t={2,3,18,6};
    Solution s;
    int ans = s.numFactoredBinaryTrees(t);
    cout<<ans;
    return 0;
}
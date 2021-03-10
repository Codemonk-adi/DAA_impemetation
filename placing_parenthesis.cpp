#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

struct pairs{
    int max;
    int min;
};
int maxi(int a,int b, int c, int d, int e){
    int temp=a;
    if(b>temp)
    temp = b;
    if(c>temp)
    temp =c;
    if(d>temp)
    temp = d;
    if(e>temp)
    temp = e;

    return temp;
};
int mini(int a,int b, int c, int d, int e){
    int temp=a;
    if(b<temp)
    temp = b;
    if(c<temp)
    temp =c;
    if(d<temp)
    temp = d;
    if(e<temp)
    temp = e;

    return temp;
};

struct pairs maxmin(int i, int j, vector<int> &nums,int** max, int **min, vector<char> &op){
    struct pairs ans;
    if(i==j){
        ans.max=nums[i];
        ans.min=nums[i];
    }else{
        ans.max=INT_MIN;
        ans.min=INT_MAX;
        int s = nums.size();
        int a,b,c,d;
        for(int p=i;p<j;p++){
            switch(op[p]){
                case '+':
                a = max[i][p-i] + max[p+1][j-p-1];
                b = max[i][p-i] + min[p+1][j-p-1];
                c = min[i][p-i] + max[p+1][j-p-1];
                d = min[i][p-i] + min[p+1][j-p-1];
                break;
                case '-':
                a = max[i][p-i] - max[p+1][j-p-1];
                b = max[i][p-i] - min[p+1][j-p-1];
                c = min[i][p-i] - max[p+1][j-p-1];
                d = min[i][p-i] - min[p+1][j-p-1];
                break;
                case '*':
                a = max[i][p-i] * max[p+1][j-p-1];
                b = max[i][p-i] * min[p+1][j-p-1];
                c = min[i][p-i] * max[p+1][j-p-1];
                d = min[i][p-i] * min[p+1][j-p-1];
                break;
            }
            ans.max = maxi(a,b,c,d,ans.max);
            ans.min = mini(a,b,c,d,ans.min);
        }
    }
    return ans;
};

int soln(vector<int> nums, vector<char> op){
    int** max = new int*[nums.size()];
    for(int i=0;i<nums.size();i++){
        max[i] = new int[nums.size()-i];
        memset(max[i], 0, (nums.size()-i)*sizeof(int));
    };

    int** min = new int*[nums.size()];
    for(int i=0;i<nums.size();i++){
        min[i] = new int[nums.size()-i];
        memset(min[i], 0, (nums.size()-i)*sizeof(int));
    };

    //cause we only need n**2 /2 total space
    int a,b,c,d;
    struct pairs temp;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size()-i;j++){
            temp = maxmin(j, j+i, nums, max, min, op);
            max[j][i] = temp.max;
            min[j][i] = temp.min; 
        }
    }
    int ans = max[0][nums.size()-1];
    for(int i=0;i<nums.size();i++){
        delete max[i];
    };

    for(int i=0;i<nums.size();i++){
        delete min[i];
    };

    return ans;
};

int main(){
    vector<int> nums={5,8,7,4,8,9};
    vector<char> op={'-','+','*','-','+'};
    int max = soln(nums,op);
    cout<<max;
}
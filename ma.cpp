#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string str)
    {
        if(!str.empty()){
            auto s= str.begin();
            auto e=str.end();
            while(s<e){
                if(*s!=*e){
                    return 2;
                }
                s++;
                e--;
                if(s>e){
                    return 1;
                }
            }

        }
        return 0;
    }
};

int main(){
    Solution a;
    string str="ababa";
    cout<<a.removePalindromeSub(str);
}
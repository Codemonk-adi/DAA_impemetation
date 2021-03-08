#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
// #include<pair>

using namespace std;

int change(int value, vector<int> denom){
    vector<int> minsteps(value);
    sort(denom.begin(),denom.end());
    minsteps[0]=0;
    for(int i=denom[0];i<=value;i++){
        auto itr = denom.begin();
        int temp;
        minsteps[i]=minsteps[i-*itr]+1;
        itr++;
        while(itr!=denom.end()&&*itr<=i){
            if(minsteps[i-*itr]+1<minsteps[i]){
                temp=minsteps[i-*itr]+1;
                minsteps[i]=temp;
            }
            itr++;
        }
    }
    return minsteps[value];
}

int main(){
    vector<int> denom={1,2,5,10,20,25,100,500,2000};
    int value=4;
    int tmep;
    tmep=change(value,denom);
    cout<<tmep;
}
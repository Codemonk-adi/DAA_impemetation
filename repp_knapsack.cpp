#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<pair<int,int>> WV, int capacity){
    vector<int> value(capacity+1,0);
    sort(WV.begin(),WV.end(),[](pair<int,int> &a, pair<int,int> &b){
    return a.first<b.first;
    });
    // for(auto i:WV){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    for(int i=1;i<=capacity;i++){
        auto itr= WV.begin();
        while(itr!=WV.end()&&(*itr).first<=i){    
            if(value[i-(*itr).first]+(*itr).second>value[i]){
                int temp=value[i-(*itr).first]+(*itr).second; 
            value[i]=temp;
            }
            itr++;
        }
        // cout<<value[i]<<endl;
    }
    return value[capacity];



};

int main(){
    vector<pair<int,int>> WV;
    int knapsack_weight;
    WV.push_back(make_pair(6,30));
    WV.push_back(make_pair(4,18));
    WV.push_back(make_pair(2,7));
    WV.push_back(make_pair(3,13));
    
    knapsack_weight=11;
    int soln;
    soln = solution(WV,knapsack_weight);
    cout<<soln;

}
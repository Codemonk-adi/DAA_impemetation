#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int solution(vector<pair<int,int>> WV, int capacity){
    int **ptr = new int*[WV.size()+1];
    for(int i=0;i<=WV.size();i++){
        ptr[i] = new int[capacity+1];
        memset(ptr[i],0, (capacity+1)*sizeof(int));
    }
    
    sort(WV.begin(),WV.end(),[](pair<int,int> &a, pair<int,int> &b){
    return a.first<b.first;
    });
    //   for(auto i:WV){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    for(int i=1;i<=capacity;i++){
        for(int j=1;j<=WV.size();j++){
            int t2;
            t2 = ptr[j-1][i];
            if(WV[j-1].first<=i){
                int t1;
                t1 =  ptr[j-1][i-WV[j-1].first] + WV[j-1].second;
                ptr[j][i] = max(t1,t2 );
            }
            else{
                ptr[j][i] = t2;
            }
        }
    }
    int temp =  ptr[WV.size()][capacity];

    for(int i=0;i<=WV.size();i++){
        delete ptr[i];
    }
    return temp;
};


int main(){
    vector<pair<int,int>> WV;
    int knapsack_weight;
    WV.push_back(make_pair(6,30));
    WV.push_back(make_pair(4,18));
    WV.push_back(make_pair(2,7));
    WV.push_back(make_pair(3,13));
    
    knapsack_weight=12;
    int soln;
    soln = solution(WV,knapsack_weight);
    cout<<soln;

}
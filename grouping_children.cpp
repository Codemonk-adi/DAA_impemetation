#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<float> ages;
    int n;
    cin>>n;
    float t;
    for(int i =0; i<n;i++){
        cin>>t;
        ages.push_back(t);
    }
    sort(ages.begin(),ages.end());
    int p=0;
    float min=ages[0];
    for( auto i : ages){
        if(i-min>1){
            min=i;
            p++;
        }
    }
    cout<<p;
}
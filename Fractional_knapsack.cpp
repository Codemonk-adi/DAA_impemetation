#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class npair{
    private:

    int weight;
    int value;
    double ratio;
    public:
    npair(){
        weight=0;
        value=0;
    }
    npair(int w,int v){
        weight=w;
        value=v;
        this->set_ratio();
        
    }
    bool operator!=(npair a){
        return a.rato()!=this->rato();
    }
    void set_WV(int w,int v){
        this->weight=w;
        this->value=v;
        this->set_ratio();
    }
    void set_ratio(){
        this->ratio=0;
        if(this->weight!=0){
        this->ratio=(double)this->value/this->weight;
        }
    }
    double rato(){
        return this->ratio;
    }
    int weght(){
        return this->weight;
    }
    int vale(){
        return this->value;
    }
};
bool comparator(npair a,npair b){
    if(a.rato()>b.rato())
    return true;
    else
    {
        return false;
    }
    
}

int main(){
    vector<npair> arr;
    int n;
    cout<<"Number of elements:"<<endl;
    cin>>n;
    int w;
    int v;
    cout<<"Enter Weight Value:"<<endl;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        arr.push_back(npair(w,v));
    }
    double max_weight;
    cout<<"Enter the max weight:"<<endl;
    cin>>max_weight;

    sort(arr.begin(),arr.end(),comparator);

    double avl_weight=max_weight;
    double curr_value;
    int pointer=0;
    double fractions[20]={0.0};
    while(avl_weight>0){
        if(arr[pointer].weght()<=avl_weight){
            curr_value+=arr[pointer].vale();
            avl_weight-=arr[pointer].weght();
            fractions[pointer]=1;
            pointer++;
        }else{
            double taken=avl_weight/arr[pointer].weght();
            curr_value+=arr[pointer].vale()*taken;
            avl_weight=0;
            fractions[pointer]=taken;
        }
        
    }
    for(int i=0;fractions[i]>0;i++){
        cout<<arr[i].weght()<<" "<<arr[i].vale()<<" "<<fractions[i]<<endl;
    }

}
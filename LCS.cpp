#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;


//This is a Dynamic programming solution for the LCS problem and will use the tabulation method

//let X be the array1 with i elements and Y be the array2 with j elements
//if c[i,j] is the max length

//recurrance relation is
//C[i,j]:
//0 if i/j ==0
//c[i-1,j-1] if Xi==Yj
//max(c[i-1,j], c[i,j-1]) if Xi!= Yj

vector<char> LCS_func(vector<char> x,vector<char> y){
    int n=x.size();
    int m=y.size();
    int **arr = new int*[m+1];
    int **dir = new int*[m+1];
    vector<char> lcs;
    //dir stores the direction from which the data was updated in arr aray.
    //1 for diagonal,2 for top(arr[i][j-1]), 3 for left(arr[i-1][j])
    for(int p=0;p<=m;p++){
        arr[p]=new int[n+1];
        dir[p]=new int[n+1];
        memset(arr[p],0,m*sizeof(int));
        memset(dir[p],0,m*sizeof(int));
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(y[i-1]==x[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
                dir[i][j]=1;
            }else{
                if(arr[i-1][j]>arr[i][j-1]){
                    arr[i][j]=arr[i-1][j];
                    dir[i][j]=3;
                }else{
                    arr[i][j]=arr[i][j-1];
                    dir[i][j]=2;
                }
            }
        }
    }
    int size = arr[m][n];
    int i=m;
    char push;
    int j=n;
    while(size!=0){
        if(dir[i][j]==1){
            push=y[i-1];
            lcs.push_back(push);
            i--;
            j--;
            size--;
        }else if(dir[i][j]==2){
            j--;
        }else{
            i--;
        }

    }
    cout<<arr[m][n]<<endl;
    for(int p=arr[m][n]-1;p>=0;p--){
        cout<<lcs[p]<<" ";
    }
    for(int p=0;p<=m;p++){
        delete arr[p];
        delete dir[p];
    }
    return lcs;
};

int main(){
    vector<char> X;
    vector<char> Y;
    char temp;
    int i,j;
    cout<<"Enter the size of first array:"<<endl;
    cin>>i;
    cout<<"Enter the elements"<<endl;
    for(int p=0;p<i;p++){
        cin>>temp;
        X.push_back(temp);
    }
    cout<<"Enter the size of second array:"<<endl;
    cin>>j;
    cout<<"Enter the elements"<<endl;
    for(int p=0;p<j;p++){
        cin>>temp;
        Y.push_back(temp);
    }
    vector<char> lcs=LCS_func(X,Y);
    
}
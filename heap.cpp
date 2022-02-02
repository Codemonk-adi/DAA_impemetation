#include<iostream>
#include<cassert>
using namespace std;
class dynamic_array{
    int * arr;
    int size;
    int capacity;
    bool resize(){
        if(size<capacity/2)
        capacity/=2;
        else
        capacity*=2;

        int *temp;
        temp = new int[capacity];
        for(int i=0;i<size;i++){
            temp[i] = arr[i];
        }
        delete arr;
        arr = temp;
        return true;
    }
    public:
    dynamic_array(){
        arr = new int[1];
        size=0;
        capacity=1;
    };
    
    bool add(int n){
        if(size == capacity)
        this->resize();

        arr[size++] = n;
        
        return true;
    };

    bool remove(int index){
        for(int i=index;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
        if(size<capacity/2)
        this->resize();

        
        return true;
    };
    int &operator[](int n){
      assert(n>=0 && n<size);
      return arr[n];

    };
    int cap(){
        return capacity;
    }
    
};

class heap{
    dynamic_array tree;
    int size;
    int capacity;
    void heapify(){};
    public:
    heap(){
        size=0;
        capacity = tree.cap();
    };
    void shiftup(int index){
        while(index>0 && tree[index]>tree[(index-1)/2]){
            int temp = tree[index];
            tree[index] = tree[(index-1)/2];
            tree[(index-1)/2] = temp;
            index = (index-1)/2;
        }
    };
    void shiftdown(int index){
        int lc;
        int rc;
        lc = index*2 +1; 
            rc = lc+1;
            if(rc>=size)
            rc=-1;
        while(lc != -1 && rc != -1){ 
            
            if(rc==-1 || tree[lc]>tree[rc]){
                if(tree[index]<tree[lc]){
                    int temp = tree[index];
                    tree[index] = tree[lc];
                    tree[lc] = temp;
                    index = lc;
                }
                else{
                    lc=-1;
                }
            }else{
                if(tree[index]<tree[rc]){
                    int temp = tree[index];
                    tree[index] = tree[rc];
                    tree[rc] = temp;
                    index = rc;
                }else{
                    lc = -1;
                }
            }
            if(lc!=-1)
            lc = index*2 +1; 

            rc = lc+1;
            if(rc>=size)
            rc=-1;
                // if(rc == -1 || tree[lc]>tree[rc]){
            //     if(tree[index]<tree[lc]){
            //         int temp = tree[index];
            //         tree[index] = tree[lc];
            //         tree[lc] = temp;
            //         index = lc;
            //     }
            //     else{
            //         lc=-1;
            //     }
            // }else{
            //     if(tree[index]<tree[rc]){
            //         int temp = tree[index];
            //         tree[index] = tree[rc];
            //         tree[rc] = temp;
            //         index = rc;
            //     }else{
            //         lc = -1;
            //     }
            // }
            // lc = index*2 +1;
            // rc = lc+1;
            // if(rc>=size){
            //     rc=-1;
            // }
        }
    };
    void add(int n){
        tree.add(n);
        shiftup(size);
        size++;
        capacity = tree.cap();
        // for(int i = 0;i<size;i++){
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
    };
    int ext_max(){
        if(size==0)
        return -1;
        int max = tree[0];
        tree[0] = tree[size-1];
        size--;
        tree.remove(size);
        capacity = tree.cap();
        shiftdown(0);
        // for(int i = 0;i<size;i++){
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
        return max;
    };



};

int main(){
    heap h1;
    for(int i = 0;i<10;i++){
        h1.add(i);
    }
    for(int i =0;i<10;i++){
        cout<<h1.ext_max()<<" ";
    }

    
}
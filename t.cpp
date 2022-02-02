lass Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ctr=1;
        long int temp;
        vector<int> mem(arr.size(),1);
        for(int i =1;i<arr.size();i++){
            int l = 0;
            int r = i-1;
            temp = 1;
            long int p;
            while(l<=r){
                p=(long int)arr[l]*arr[r];
                if(p>INT_MAX)
                    r--;
                else{
            if(p == arr[i]){
                if(l==r)
                temp+=(long)mem[l]*mem[r];
                else
                temp+=2*(long)mem[l]*mem[r];
                l++;
                r--;
            }else if(p < arr[i])
            l++;
            else
            r--;
                }
            temp %= (int)(1e9+7);
            
            }
            ctr+=temp;
            mem[i] = temp;
            ctr = ctr %(int)(1e9+7);
        }
        return ctr;

        
    }
};
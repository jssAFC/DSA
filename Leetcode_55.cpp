//***************************************************************//
//
// Optimised approach
//
//***************************************************************//

class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n=arr.size(),
        maxreach=arr[0],
        steps=arr[0];
        if(n<=1) return true;
        if(arr[0]==0) return false;
        for(int i=0;i<n;i++){
            if(i==n-1) return true;
            maxreach=max(maxreach,i+arr[i]);
            steps--;
            if(steps==0){
                if(i>=maxreach) return false;
                steps=maxreach-i;
            }
        }

        return false;
    }
};

//***************************************************************//

TC - O(N)
SC - O(1)
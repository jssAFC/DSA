//***************************************************************//
//
// Optimal appraoch
//
//***************************************************************//

class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        int start=0,end=len-1;
        while(start<end){
            while(!isalnum(s[start]) && start<end) start++;
            while(!isalnum(s[end]) && start<end) end--;
            if(tolower(s[start])!=tolower(s[end])) return false;
            start++;
            end--;
        }

        return true;
    }
};

//***************************************************************//
TC - O(n);
SC- O(1);
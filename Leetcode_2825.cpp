//***************************************************************//
//
// Optimized approach 1
//
//***************************************************************//

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        //  Here we use a two pointer appraoch. If the string match the go to next, if they dont try incrementing and check again. Else conitnue

        int index=0;
        int count=0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]==str2[index] && index<str2.size()){
                count++;
                index++;
            }

            else{
                if(str1[i]=='z') str1[i]='a';
                else str1[i]++;
                if(str1[i]==str2[index] && index<str2.size()){
                    count++;
                    index++;
                }
            }
        }

        if(count==str2.size()) return true;
        else return false;
    }
};

//***************************************************************//

Time Complexity- o(n+m) where n is for traversing the length of str1 and m for str2. In worst case we traverse both

Space complexity- O(1) - on additional space is taken

//***************************************************************//
//
// Optimized approach 2
//
//***************************************************************//

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        //  In this approach we convert them into numbers and then check
        int i=0;
        for(auto &it: str1){
            if(i==str2.size()) break;
            int a= it- 'a',b=str2[i]-'a';
            if(a==b || (a+1)%26==b) i++;
        }

        return i==str2.size();
    }
};

//***************************************************************//

Time Complexity and Space complexity is same
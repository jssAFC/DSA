//***************************************************************//
//
// Brute Force solution
//
//***************************************************************//

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream result;
        // this is present in <sstring> header file
        // this function works on strings and allows us to treat strings like input or output streams. string            stream dynamically grows its interanl buffer as per the need. It also allows us to use the stream as an output

        int index=0;

        //  Iterate over the string
        for(int i=0;i<s.size();i++){

            //  We are going to add the char at s[i] always. Using the if condition we are checking if teh value of i matches that of the place where we want to insert space. In case it does we will first add a space to stream and then append the character
            if(index<spaces.size() && i==spaces[index] ){
                result << ' ';
                index++;
            }

            result << s[i];
        }

        return result.str();
    }
};

//***************************************************************//

Time complexity- O(n+m) this is because we are traversing the string of size n and the spaces vector of size m 

Space complexity - O(n+m) this is because we are storing the string and the spaces in a stream.


//***************************************************************//
//
// Optimal Approach
//
//***************************************************************//

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result="";
        int index=0;
        for(int i=0;i<s.size();i++){
            if(index<spaces.size() && i==spaces[index]){
                result+=' ';
                index++;
            }

            result+=s[i];
        }

        return result;
    }
};

//***************************************************************//

Time Complexity - O(n+m) this is because we are traversing the string of size n and the spaces vector of size m

Space complexity - O(n) this is because we are storing the string in a string variable.

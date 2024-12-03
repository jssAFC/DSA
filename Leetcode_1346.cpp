//***************************************************************//
//
// Brute Force Approach

//
//***************************************************************//

time complexity- 0(n^2)

space complexity- 0(1)

//***************************************************************//

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // This is the brute force aprocah where we use to interate
        // through evey single element making sure i!=-j
        int s=arr.size();
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(i!=j)
                if(arr[i]==2*arr[j]) return true;
            }
        }

        return false;
    }
};

//***************************************************************//
//
// Better Approach
//
//***************************************************************//

time complexity-  0(n)   // We iterate through the array once and check if they are present in the array or not.

space complexity- 0(n)  // space taken by set

//***************************************************************//

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        // here we use unordered set instead of normal set becuse these have avg
        // tc 0(1) and they are good for checking if elements presetn in the set
        // or not. Order is not important
        unordered_set<int> seen;
        for (int num : arr) {
            // check if num*2 or num/2 exists in the array
            if (seen.count(2 * num) || (seen.count(num / 2) && num % 2 == 0))
                return true;
            // this condition makes sure that a number shoudl be divisible by 2
            // only then we shall check if num/2 exits because (7/2=3.5=3) so
            // this situation doesnt occure
            seen.insert(num);
        }

    return false;
    }
    // no valid pair found
};

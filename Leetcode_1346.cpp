//***************************************************************//
//
// Brute Force Approach

//
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

time complexity- 0(n^2)
    
space complexity- 0(1)

//***************************************************************//
//
// Better Approach
//
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

//***************************************************************//

time complexity-  0(n)   // We iterate through the array once and check if they are present in the array or not.

space complexity- 0(n)  // space taken by set

//***************************************************************//
//
// Another Optimal approach
//
//***************************************************************//
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            // Step 2: Calculate the target (double of current number)
            int target = 2 * arr[i];
            // Step 3: Custom binary search for the target
            int index = customBinarySearch(arr, target);
            // If the target exists and is not the same index
            if (index >= 0 && index != i) {
                return true;
            }
        }
        // No valid pair found
        return false;
    }

private:
    int customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            // Avoid potential overflow
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};

//***************************************************************//

time complexity-  0(nlogn)   // we are iterating over n elements and for each elemetn we apply binary search which has logn time complexity

space complexity- 0(logn)  // in cpp, the sorting alogrithm is implemented using combination of quick sort, heap sort and insertion sort trherefore it takes a logn space complexity

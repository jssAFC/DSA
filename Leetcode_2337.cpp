//***************************************************************//
//
// Better approach
//
//***************************************************************//

class Solution {
public:
    bool canChange(string start, string target) {

        //  The approach in this method is that we initialise 2 queue start and target and iterate through the start and target string. If the elemetn in these string are no _ then we push the char into their respective queue alonside their index. 

        
        queue<pair<char, int>> startQueue, targetQueue;
        
        

        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        //  Now we check for the size of the 2 queue. In case they are not equal then we cannot make them equal so we return fasel. 

        if (startQueue.size() != targetQueue.size())
            return false;
        //  In case they equal, we will no pop the top elements from the both queue and check if their character value is equal or not. 
        
        
        // Now for the index, we have to make sure that if the char is 'L' then its index in start queue should be greater than that of target queue. This is becasue we can reach the target string by shifting the L char to its left. And in case if the char in start index is higher than that of target index, it is achievable to shift the char left and match the both indexes. But if its not we return false because we cannot shift the L char to right.

        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            //  the data structure used above is calle structure bindings and it is used to store pair values from a queue. The first and second value of pair are assigned to the first and second variable of the structure bindings



        //  Do it similiarly for R char and make sure its index in start queue is not larger than that of target queue because we cannot shift it left

            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;    // return true if the conditions are satisfied
    }
};

//***************************************************************//

Time complexity- O(n)   //  for traversing the both string and adding them into the queue is o(n). And then we are also comapring their values which also takes a o(n)

Space complexity- o(n)  //  for storing the values in the queue.

//***************************************************************//
//
// Optimized appraoch
//
//***************************************************************//

class Solution {
public:
    bool canChange(string start, string target) {

        //  In this the idea is to use 2 pointer appraoch to traverse both strtings at same time comparing their characters. If they dont match, we return false. In case they mathc we check for their index and if they dont match we return faslse. In case all goes well we return true

        int startLength = start.length();
        int startIndex=0,targetIndex = 0;
        while (startIndex < startLength || targetIndex < startLength) {
            while (!isalpha(start[startIndex]) && startIndex < startLength) {
                startIndex++;
            }

            while (!isalpha(target[targetIndex]) && targetIndex < startLength) {
                targetIndex++;
            }

            if (startIndex == startLength || targetIndex == startLength)
                return startIndex == startLength && targetIndex == startLength;

            if (start[startIndex] != target[targetIndex]) {
                return false;
            }

            else {
                if (start[startIndex] == 'L' && startIndex < targetIndex) 
                        return false;
                

                if (target[targetIndex] == 'R' && startIndex > targetIndex) 
                        return false;
    
            }

            startIndex++;
            targetIndex++;
        }
        return true;
    }
};

//***************************************************************//

Time complexity- o(N) // for traversing the string of length n. The inner while loop will run in constant time for each character in the string. This means that once a character is encountered it will never be visited again in the string. So it will run in constant time

Space complexity- o(1)  //  no extra space is used
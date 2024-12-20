class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0){
            int rem=x%10;
            x/=10;
            if(rev>INT_MAX/10 || (rev==INT_MAX) && rem>7) return 0;
            if(rev<INT_MIN/10 || (rev==INT_MIN) && rem<-8) return 0;
            //  Here the logic behind this code is that if rev>int_max then it will defineitely exceed int_max when next digit is added.
            // Same applies for int_min. 

            // In case they are equal, then we need to make sure its no greater than 7 or less tha 8 depeinding on case as it will again exceed limit
            rev=10*rev+rem;
        }

        return rev;
    }
};
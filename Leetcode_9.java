class Solution {
    public boolean isPalindrome(int x) {
        int rev=0;
        int original=x;
        while(x!=0){
            int rem=x%10;
            rev=rev*10+rem;
            x/=10;
        }

        if(rev<0) return false;
        if(rev>Integer.MAX_VALUE || rev<Integer.MIN_VALUE) return false;
        return rev==original;
    }
}
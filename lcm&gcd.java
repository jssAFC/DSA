class Solution {
    public static int[] lcmAndGcd(int a, int b) {
        // code here
        int n1=a;
        int n2=b;
        
        while(a>0 && b>0){
            if(a>b) a=a%b;
            else b=b%a;
        }
        
        
        int gcd;
        if(a==0) gcd=b;
        else gcd=a;
        
        int lcm=(n1*n2)/gcd;
        
        return new int[] {lcm,gcd};
        
    }
}
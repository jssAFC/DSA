class Solution {
    static int tsum(int x){
        int sum=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                sum+=i;
                if(x/i!=i && x%(x/i)==0 ){
                 sum+=x/i;   
                }
            }
        }
        return sum;
        
    }
    public static int sumOfDivisors(int n) {
        // code here
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=tsum(i);
        }
        
        return sum;
        
    }
}
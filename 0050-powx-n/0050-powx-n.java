class Solution {
    public double myPow(double X, int n) 
    {
        
     if(X==0 || X==1)
     {
         return X;
     }
     if (n>=0)
     {
         return helper(X,n);
     }
     else 
     {
         return  helper (1.0/X,-(long)n);

     }

    }

    
    

    private double helper(double X, long n)
    {
        if (n==0)
        {
            return 1;
        }
        if (n%2==0)
        {
            return helper (X*X, n/2);
        }

        else 
        {
            return X * helper(X*X , (n-1)/2);
        }
    }
}






// class Solution {
//     public double myPow(double x, int n) {
       
//         if (x == 0 || x == 1) {
//             return x;
//         }
//         if (n >= 0) {
//             return helper(x, n);
//         }
//         else {
//             return helper(1.0 / x, -(long)n);
//         }
        
//     }
    
//     private double helper(double x, long n) {
//         // Base case
//         if (n == 0) {
//             return 1;
//         }
//         // Recursive rule
//         if (n % 2 == 0) {
//             return helper(x * x, n / 2);
//         }
//         else {
//             return x * helper(x * x, (n - 1) / 2);
//         }
//     }
// }

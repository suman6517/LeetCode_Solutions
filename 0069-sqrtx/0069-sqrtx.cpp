class Solution {
public:

    long long int squartOfX(int num)
    {
        int start =0;
        int end = num;
        long long int ans = -1;
        long long int mid = start + (end - start) /2;

        while(start <= end )
        {
            long long int square = (mid * mid );

            if (square == num)
            {
                return mid ;
            }
            else if (square < num )
            {
                ans = mid ;

                start = mid +1 ;
            }
            else 
            {
                end = mid -1 ;
            }
            mid = start + (end -start ) /2;

        }
        return ans ;
    }
    int mySqrt(int x)
    {
        return squartOfX(x);
        
    }
};
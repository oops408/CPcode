class Solution {
public:
    bool isUgly(int n) {

        // if n == 0, return false

        if(n == 0)
        {
            return false;
        }

        // divide the number until it is divisible by 2
        
        while(n % 2 == 0)
        {
            n = n / 2;
        }

        // divide the number until it is divisible by 3

        while(n % 3 == 0)
        {
            n = n / 3;
        }

        // divide the number until it is divisible by 5

        while(n % 5 == 0)
        {
            n = n / 5;
        }

        // if at the end number remains 1 then it has only 3, 5, 7 as prime factors

        return n == 1;
    }
};

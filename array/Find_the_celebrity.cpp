/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
      ///  find candiate first. 
        int candidate =0; 
        for(int i=0; i< n ; i++)
        {
            if(knows(candidate, i))
            {
                candidate = i; 
            }
        }
         // verify if candiate is real or not
        for(int i =0; i< n ; i++)
        {
            if(i == candidate)
                continue;
            if(knows(i, candidate) ==false || knows(candidate, i)==true )
                return -1;
        }
        return candidate;  

    }
};

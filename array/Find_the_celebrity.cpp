class Solution {
public:
    int findCelebrity(int n) {
        
        /// use two pointer. 
        int left =0; 
        int right = n-1; 
        while(left<right)
        {
            bool bleft = knows(left, right);
            bool bright = knows(right, left); 
            if(bleft && bright)//  left know right. it means that left must not Celebrity person. 
            {
                left++;
                right--; 
            }
            else if(bleft)
            {
                left++; 
            }
            else if(bright) // right know left. it means that righ must not celeberity person. 
            {
                right--;
            }
            else  // left and right both are not celerity person. 
            {
                left++; 
                right--; 
            }
        }

        //cout << "left:" << left <<"right:" << right << "\n"; 
        if(left == right)
        {
            for(int i =0; i< n ; i++)
            {
                if(i == left)
                    continue;
                if(knows(i, left) ==false || knows(left, i)==true )
                    return -1;
            }
             return left;  
        } 
        else
            return -1; 
    }
};

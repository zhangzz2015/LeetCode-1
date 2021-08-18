class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer.
        int count =0; 
        int prevNum = nums[0];
        bool repeat = false;
        for(int i=1; i< nums.size(); i++)
        {
            if(nums[i] == prevNum )
            {
               if(repeat == false) 
               {
                   repeat = true;
                   count++;
                   nums[count] = nums[i];
               }                        
            }
            else
            {
                repeat = false;
                count++;
                nums[count] = nums[i];
            }
            prevNum = nums[i];
        }
        count ++ ; 
        return count;
        
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //  first missing positive is 1. 
        //  hash map record positive number.
        int ret  =1;
        
        unordered_set<int> see; 
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i]==ret)
            {
              ret++;   
              while(see.find(ret)!=see.end())
              {
                  ret++;
              }
            }
            if(nums[i]>0)
                see.insert(nums[i]); 
        }
        return ret; 
    }
};

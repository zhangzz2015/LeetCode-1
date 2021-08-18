class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int totalNum=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=val)
            {
                nums[totalNum] = nums[i];
                totalNum++;
            }        
        }
        return totalNum;        
    }
};

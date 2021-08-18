class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // define dp function. It has two state. 
        // dpbuy1[i]   first time to keep stock at time i.   
        // dpsell1[i] 
        // dpbuy2[i]
        // dpsell2[i]
        // dpempty[i]
        // dpbuy1[i] = max(dpemty[i-1] - prices[i],dpbuy1[i-1] )
        // dpsell1[i] = max(dpsell[i-1], dpbuy1[i-1] + prices[i]) 
        // dpbuy2[i] = max(dpsell1[i-1] - prices[i], dpbuy2[i-1])
        // dpsell2[i] = max(dpsell2[i-1], dpbuy2[i-1] + prices[i])
        vector<int> dpTable(5,0); 
        dpTable[1] = - prices[0]; 
        dpTable[3] = -prices[0];
        for(int i=1; i< prices.size(); i++)
        {
            dpTable[4] = max(dpTable[4], dpTable[3]+prices[i]);             
            dpTable[3] = max(dpTable[3], dpTable[2] - prices[i]);
            dpTable[2] = max(dpTable[2], dpTable[1] + prices[i]);            
            dpTable[1] = max(dpTable[0] - prices[i], dpTable[1]); 
        }
        
        return dpTable[4]; 
        
        
    }
};

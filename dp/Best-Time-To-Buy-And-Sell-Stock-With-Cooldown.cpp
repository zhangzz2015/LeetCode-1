class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //   
        // dpTable[i][0]   buy stock max money
        // dpTable[i][1]   today sell stock max money
        // dpTable[i][2]   yesterday sell stock and cooldown stage.
        // dpTable[i][3]   two days sell stock and pass cooldown stage. It also include don't do anything. 
        
        // dpTable[i][0] = max(max(dpTable[i-1][3] - prices[i], dpTable[i-1][0]), dpTable[i-1][2] - prices[i] ) ; 
        // dpTable[i][1] = dpTable[i-1][0] + prices[i];
        // dpTable[i][2] = dpTable[i-1][1]; 
        // dpTable[i][3] = max(dpTable[i-1][2], dpTable[i-1][3])
        if(prices.size()<=1)
            return 0;
        
        vector<int> dpTable(4,0); 
        dpTable[0] = - prices[0];
        
        int maxProfit = 0; 
        for(int i=1; i < prices.size(); i++)
        {
            int sellPrice = dpTable[0]; 
            
            dpTable[0] = max(max((dpTable[3] - prices[i]), dpTable[0]), dpTable[2] - prices[i]);
            dpTable[3] = max(dpTable[2], dpTable[3]);    
            dpTable[2] = dpTable[1];             
            dpTable[1] = sellPrice + prices[i]; 
            if(i == (prices.size()-1 ) )
            {
                maxProfit = max(max(dpTable[1], dpTable[2]) , dpTable[3]) ; 
            }
        }
        
        return maxProfit; 
        
    }
};

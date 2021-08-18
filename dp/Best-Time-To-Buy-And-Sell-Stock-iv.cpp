class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        // dp[i][0]   don't do anything; 
        // dp[i][2*j-1]   here j from 1 to k.  buy and keep max value  
        // dp[i][2*j]     here j from 1 to k.  sell and keep max value.
        //  dp[i][0] = dp[i-1][0]; 
        // dp[i][2*j-1] = max(dp[i-1][2*j-1], dp[i-1][2*j-1-1] - prices[i] ); 
        // dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j-1] + prices[i]); 
        if(prices.size()<=1)
            return 0; 
        
        vector<int> dpTable(2*k+1,0); 
        for(int i=1; i<=k; i++)
            dpTable[2*i-1] = - prices[0]; 
        int maxProfit = 0; 
        for(int i=1; i< prices.size(); i++)
        {
            for(int j =k; j >0; j--)
            {
                {
                    dpTable[2*j] = max(dpTable[2*j] , dpTable[2*j-1] + prices[i]);                    
                    dpTable[2*j-1] = max(dpTable[2*j-1], dpTable[2*j-1-1] - prices[i]);                     
                }
                
                if(i==(prices.size()-1))
                {
                    maxProfit = max(maxProfit, dpTable[2*j]);
                }
               // cout << "i:" << i << "j:" << j << "dpTable:" << dpTable[i][j*2]<<"\n"; 
            }
        }
            
        return maxProfit; 
        
    }
};

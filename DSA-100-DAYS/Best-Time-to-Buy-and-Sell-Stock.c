#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int profit =0;
    int mini=prices[0];

    for(int i=1;i<pricesSize;i++)
    {
        int diff = prices[i]-mini;
        profit=fmax(diff, profit);
        mini=fmin(prices[i],mini);
    }
    return profit;
}

int main(){
    
    return 0;
}
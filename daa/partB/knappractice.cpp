#include<utilties.h>
int knapsack(int i, vi& weight,vi& profit,const int& w,vvi& dp)
{
    if(i==0 or w==0)
    return 0;

    if(dp[i][w]!=-1)
    return dp[i][w];

    if(dp[i-1][w-1]+weight[i] > w)
    dp[i][w] = knapsack(i-1,weight,profit,w,dp);
    else
    dp[i][w] = max(knapsack(i-1,weight,profit,w-weight[i-1],dp) + profit[i-1], knapsack(i-1,weight,profit,w,dp));

    return dp[i][w];


}
void result() {
    int n;
    cout << "Enter the size of array"; nl
    cin >> n;
    vi profit(n);
    vi weight(n);
    cout << "Enter the Profit for each index"; nl
    inp(profit, n)
    cout << "Enter the weight for each index"; nl
    inp(weight, n)
    int w;
    cout << "Enter the weight limit "; cin >> w;
    vvi dp(n+1,vi(w+1,-1));
    auto max_profit = knapsack(n,weight,profit,w,dp);
    cout << "Max profit = \t" << max_profit; nl
}


int main() {

    int tc;
    cin>>tc;
    TC(tc)
    {
        result();
    }
    return 0;
}

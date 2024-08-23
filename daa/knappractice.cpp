#include<utilties.h>
int knapsack(int i, vi& weight, vi& profit, const int& w, vector<vector<int>>& dp) {
    if (i == 0 || w == 0) {
        return 0;
    }

    if (dp[i][w] != -1) {
        return dp[i][w];
    }

    if (weight[i - 1] > w) {
        dp[i][w] = knapsack(i - 1, weight, profit, w, dp);
    } else {
        dp[i][w] = max(knapsack(i - 1, weight, profit, w, dp),
                       profit[i - 1] + knapsack(i - 1, weight, profit, w - weight[i - 1], dp));
    }

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
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    int max_profit = knapsack(n, weight, profit, w, dp); nl
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

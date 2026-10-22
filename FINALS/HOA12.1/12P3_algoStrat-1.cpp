#include <iostream>
#include <algorithm>
#include <vector>

int getMinSteps ( int n ){
    if (n <= 1) return 0;
    std::vector<int> dp(n + 1, 0);

    dp[1] = 0; // trivial case
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}

int main(){
    int n = 10;
    std::cout << "Minimum steps to reduce " << n << " to 1: "
              << getMinSteps(n) << std::endl;
    return 0;
}



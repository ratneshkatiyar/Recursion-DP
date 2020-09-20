#include <iostream>
// recursion
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
// recursion

int knapsack_recur(vector<int> wt, vector<int> pr, int W)
{
    if (W == 0)
    {
        return 0;
    }
    if (wt.size() == 0 || wt.size() == 0)
    {
        return 0;
    }
    int tmp_wt = wt[wt.size() - 1];
    int tmp_pr = pr[pr.size() - 1];

    wt.pop_back();
    pr.pop_back();

    if (tmp_wt <= W)
    {
        // you have 2 options either take it or leave it
        // first take it
        int op1 = tmp_pr + knapsack_recur(wt, pr, W - tmp_wt);

        // leave it
        int op2 = knapsack_recur(wt, pr, W);

        return std::max(op1, op2);
    }
    if (tmp_wt > W)
    {
        return knapsack_recur(wt, pr, W);
    }
}

// memoziation
// take an array
int dp_arr[100][100];

int knapsack_memoziation(vector<int> wt, vector<int> pr, int W)
{
    if (W == 0)
    {
        return 0;
    }
    if (wt.size() == 0 || wt.size() == 0)
    {
        return 0;
    }

    int tmp_wt = wt[wt.size() - 1];
    int tmp_pr = pr[pr.size() - 1];

    // basicall create a matrix of dp[N][W]
    if (dp_arr[wt.size()][W] != -1)
    {
        return dp_arr[wt.size()][W];
    }

    wt.pop_back();
    pr.pop_back();

    if (tmp_wt <= W)
    {
        // you have 2 options either take it or leave it
        // first take it
        int op1 = tmp_pr + knapsack_memoziation(wt, pr, W - tmp_wt);

        // leave it
        int op2 = knapsack_memoziation(wt, pr, W);

        return dp_arr[wt.size()][W] = std::max(op1, op2);
    }
    if (tmp_wt > W)
    {
        return dp_arr[wt.size()][W] = knapsack_memoziation(wt, pr, W);
    }
}

// topdown approach derived from above approach
// 1) Initialization // based on your recursive base consdition
//2) omit recursive call and use table and make it iterative
//3)  1st row and 1 st column will come under initialization
// better in case in the problem of stack overflow
// demionsiona will always be dp[N+1][W+1], because you need answer for dp[N][W]

// recursive case base condition = top down approach initialization

// top down approach
int dp_top_down[100][100];
int knapsack_top_down(vector<int> wt, vector<int> pr, int W, int N)
{
    // recursive case base condition = top down approach initialization
    for (int i = 0; i <N+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp_top_down[i][j] = 0;
            }
        }
    }


    // if(wt[n-1]<=W)
    // {
    //     // 2 conditions
    //     dp[n][w] = std::max(val[n-1]+ dp[n-1][W-wt[n-1]], dp[n-1][W]);

    // }
    // if(wt[n-1]>W)
    // {
    //     dp [n][w] = dp[n-1][W];
    // }
    
    
    // main condition change n,W into i and j. So changing above code
    
    

    for (int i = 1; i < N+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
           // n into i and W into j // IN BOLD 
            if(wt[i-1]<=j)
            {
                dp_top_down[i][j] = std::max(pr[i - 1] + dp_top_down[i - 1][j - wt[i - 1]], dp_top_down[i-1][j]);
            }
            if(wt[i-1]>j)
            {
                dp_top_down[i][j] = dp_top_down[i - 1][j];
            }
            
        }
    }

    return dp_top_down[N][W];
}

void knapsack_call_from_main()
{
    vector<int> val{-1, 100, 20, 60, 40};
    vector<int> wt{-1, 3, 2, 4, 1};
    cout << knapsack_recur(wt, val, 5) << endl;

    // memoziation code
    memset(dp_arr, -1, sizeof(dp_arr));
    cout << knapsack_memoziation(wt, val, 5) << endl;

    cout << knapsack_top_down(wt, val, 5,5) << endl;
}
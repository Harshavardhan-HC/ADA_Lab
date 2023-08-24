#include <stdio.h>

int main(void)
{
    printf("Enter the number of items: ");
    int n;
    scanf("%d", &n);

    printf("Enter the price of each item: ");
    int price[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }

    printf("Enter the weight of each item: ");
    int weight[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter the max weight: ");
    int W;
    scanf("%d", &W);

    printf("\nThe dp table is:\n");
    int dp[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                dp[i][j] = (price[i - 1] + dp[i - 1][j - weight[i - 1]]) > dp[i - 1][j] ? (price[i - 1] + dp[i - 1][j - weight[i - 1]]) : dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            printf("%d  ", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nThe maximum value we can get is: %d", dp[n][W]);

    return 0;
}

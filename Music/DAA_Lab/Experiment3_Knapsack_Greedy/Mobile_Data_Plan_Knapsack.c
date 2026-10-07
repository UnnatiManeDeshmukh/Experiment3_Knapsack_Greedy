#include <stdio.h>

struct Plan
{
    int planId;
    float cost;
    float benefit;
    float ratio;
};

int main()
{
    struct Plan plans[50], temp;
    int n;
    float budget, totalBenefit = 0.0;

    printf("MOBILE DATA PLAN SELECTION USING GREEDY METHOD\n");
    printf("------------------------------------------------\n");

    printf("Enter number of plans: ");
    scanf("%d", &n);

    printf("Enter available budget (Rs): ");
    scanf("%f", &budget);

    printf("\nEnter Plan ID, Cost (Rs) and Data Benefit (GB):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %f %f",
              &plans[i].planId,
              &plans[i].cost,
              &plans[i].benefit);

        plans[i].ratio = plans[i].benefit / plans[i].cost;
    }

    /* Sort plans by benefit/cost ratio */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (plans[i].ratio < plans[j].ratio)
            {
                temp = plans[i];
                plans[i] = plans[j];
                plans[j] = temp;
            }
        }
    }

    printf("\nSelected Plans:\n");

    for (int i = 0; i < n; i++)
    {
        if (budget >= plans[i].cost)
        {
            budget -= plans[i].cost;
            totalBenefit += plans[i].benefit;

            printf("Plan %d -> Rs. %.2f -> %.2f GB\n",
                   plans[i].planId,
                   plans[i].cost,
                   plans[i].benefit);
        }
        else if (budget > 0)
        {
            float fraction = budget / plans[i].cost;
            totalBenefit += plans[i].benefit * fraction;

            printf("Plan %d -> Rs. %.2f (%.2f%%) -> %.2f GB\n",
                   plans[i].planId,
                   budget,
                   fraction * 100,
                   plans[i].benefit * fraction);

            budget = 0;
        }
    }

    printf("\nMaximum Data Benefit = %.2f GB\n", totalBenefit);

    return 0;
}
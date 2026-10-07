#include <stdio.h>

struct Order
{
    int orderId;
    float weight;
    float value;
    float ratio;
};

int main()
{
    struct Order orders[50], temp;
    int n, capacity;
    float totalValue = 0.0;

    printf("FOOD DELIVERY ORDER SELECTION USING GREEDY METHOD\n");
    printf("--------------------------------------------------\n");

    printf("Enter number of orders: ");
    scanf("%d", &n);

    printf("Enter delivery capacity (kg): ");
    scanf("%d", &capacity);

    printf("\nEnter Order ID, Weight (kg) and Order Value (Rs):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %f %f",
              &orders[i].orderId,
              &orders[i].weight,
              &orders[i].value);

        orders[i].ratio = orders[i].value / orders[i].weight;
    }

    /* Sort orders by value/weight ratio */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (orders[i].ratio < orders[j].ratio)
            {
                temp = orders[i];
                orders[i] = orders[j];
                orders[j] = temp;
            }
        }
    }

    printf("\nSelected Orders:\n");

    for (int i = 0; i < n; i++)
    {
        if (capacity >= orders[i].weight)
        {
            capacity -= orders[i].weight;
            totalValue += orders[i].value;

            printf("Order %d -> %.2f kg -> Rs. %.2f\n",
                   orders[i].orderId,
                   orders[i].weight,
                   orders[i].value);
        }
        else if (capacity > 0)
        {
            float fraction = capacity / orders[i].weight;
            totalValue += orders[i].value * fraction;

            printf("Order %d -> %.2f kg (%.2f%%) -> Rs. %.2f\n",
                   orders[i].orderId,
                   capacity,
                   fraction * 100,
                   orders[i].value * fraction);

            capacity = 0;
        }
    }

    printf("\nMaximum Order Value = Rs. %.2f\n", totalValue);

    return 0;
}
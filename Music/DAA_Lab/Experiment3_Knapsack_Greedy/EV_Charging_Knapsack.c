#include <stdio.h>

struct Vehicle
{
    int vehicleId;
    float chargingTime;
    float batteryBenefit;
    float ratio;
};

int main()
{
    struct Vehicle vehicles[50], temp;
    int n;
    float availableTime, totalBenefit = 0.0;

    printf("EV CHARGING PRIORITY USING GREEDY METHOD\n");
    printf("-----------------------------------------\n");

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    printf("Enter available charging time (hours): ");
    scanf("%f", &availableTime);

    printf("\nEnter Vehicle ID, Charging Time (hours) and Battery Benefit (%%):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %f %f",
              &vehicles[i].vehicleId,
              &vehicles[i].chargingTime,
              &vehicles[i].batteryBenefit);

        vehicles[i].ratio =
            vehicles[i].batteryBenefit / vehicles[i].chargingTime;
    }

    /* Sort vehicles by battery benefit/time ratio */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vehicles[i].ratio < vehicles[j].ratio)
            {
                temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
        }
    }

    printf("\nSelected Vehicles:\n");

    for (int i = 0; i < n; i++)
    {
        if (availableTime >= vehicles[i].chargingTime)
        {
            availableTime -= vehicles[i].chargingTime;
            totalBenefit += vehicles[i].batteryBenefit;

            printf("Vehicle %d -> %.2f hours -> %.2f%% benefit\n",
                   vehicles[i].vehicleId,
                   vehicles[i].chargingTime,
                   vehicles[i].batteryBenefit);
        }
        else if (availableTime > 0)
        {
            float fraction = availableTime / vehicles[i].chargingTime;

            totalBenefit += vehicles[i].batteryBenefit * fraction;

            printf("Vehicle %d -> %.2f hours (%.2f%%) -> %.2f%% benefit\n",
                   vehicles[i].vehicleId,
                   availableTime,
                   fraction * 100,
                   vehicles[i].batteryBenefit * fraction);

            availableTime = 0;
        }
    }

    printf("\nMaximum Battery Benefit = %.2f%%\n", totalBenefit);

    return 0;
}
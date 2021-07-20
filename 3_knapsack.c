# include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], total_p = 0,u;
   int i, j;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      // If adding Item won't overflow, add it completely
      else {
         x[i] = 1.0;
         total_p = total_p + profit[i];
         u = u - weight[i];
      }
   }
   // If we can't add current Item, add fractional part of it
   if (i < n)                        //when weight[i]>capacity 
      x[i] = u / weight[i];

   total_p = total_p + (x[i] * profit[i]);

   printf("\nThe resultant ratio taken are:- ");
   for (i = 0; i < n; i++)
      printf("%f ", x[i]);

   printf("\nMaximum profit is:- %f", total_p);

}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);

   printf("\nEnter the weights and profits of each object:- ");
   for (i = 0; i < num; i++) {
      printf("\nweight & profit of object:%d",i+1);
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
  
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            //sorting ratio in decreasing order
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            // sorting Item on basis of ratio
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
    printf("Ratio in decreasing order:");
   for (i = 0; i < num; i++) {
        printf("%f ",ratio[i]);
   }
   printf("\n");
   printf("Profit in decreasing order:");
   for (i = 0; i < num; i++) {
        printf("%f ",profit[i]);
   }
   printf("\n");
   printf("Weight in decreasing order:");
   for (i = 0; i < num; i++) {
        printf("%f ",weight[i]);
   }
   printf("\n");

   knapsack(num, weight, profit, capacity);
   return(0);
}


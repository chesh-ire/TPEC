1.POISONOUS PLANT
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a stack element
typedef struct {
int pesticide;
int days;
} Plant;
// Function to find the number of days until no plants die
int poisonousPlants(int n, int* p) {
Plant* stack = (Plant*)malloc(n * sizeof(Plant));
int top = -1, max_days = 0;
for (int i = 0; i < n; i++) {
int days = 0;
while (top >= 0 && stack[top].pesticide >= p[i])
{
days = days > stack[top].days ? days : stack[top].days;
top--;
}
if (top >= 0) {
days++;
} else {
days = 0;
}
max_days = days > max_days ? days : max_days;
stack[++top] = (Plant){p[i], days};
}
free(stack);
return max_days;
}
int main() {
int n;
scanf("%d", &n);
int* p = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
scanf("%d", &p[i]);
}
int result = poisonousPlants(n, p);
printf("%d\n", result);
free(p);
return 0;
}
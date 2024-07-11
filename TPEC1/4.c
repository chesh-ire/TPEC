#include <stdio.h>
int main() {
int n;
scanf("%d", &n);
int petrol[n], distance[n];
for (int i = 0; i < n; i++) {
scanf("%d %d", &petrol[i], &distance[i]);
}
int start = 0;
int deficit = 0;
int capacity = 0;
for (int i = 0; i < n; i++) {
capacity += petrol[i] - distance[i];
if (capacity < 0) {
start = i + 1;
deficit += capacity;
capacity = 0;
}
}
if (capacity + deficit >= 0) {
printf("%d\n", start);
} else {
printf("-1\n");
}
return 0;
}
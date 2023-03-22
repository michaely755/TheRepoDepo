#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n){
    int temp;
    for(int i = 0; i < n-1; i++){
        int num_swaps = 0;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                num_swaps++;
            }
        }
        printf("pass %d: %d\n", i+1, num_swaps);
    }
}

int main()
{
    int arr[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    printf("before swap\n");
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, 9);

    printf("after swap\n");
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}

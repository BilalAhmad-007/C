#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main() {
    int arr[] = {42, 17, 23, 89, 13, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the number you want to search: ");
    scanf("%d",&key);

    sort(arr, n);

  
    int result = binarySearch(arr, n, key);


    if (result != -1)
        printf("Element %d found at index %d (in sorted array)\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}

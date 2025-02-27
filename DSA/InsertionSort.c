#include <stdio.h>
void getArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void printA(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int insertionSort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int arr[5];
    int size = 5;
    printf("Enter the elements of the array:\n");
    getArr(arr, size);
    printf("\nArray before sorted:\n");
    printA(arr, size);
    insertionSort(arr, size);
    printf("\nArray after sorted:\n");
    printA(arr, size);

    // only for understanding the sizeof concept:
    int s = sizeof(arr);
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("\ntotal size of array in bytes: %d\nthe size in blocks of array: %d", s, sz);
    return 0;
}
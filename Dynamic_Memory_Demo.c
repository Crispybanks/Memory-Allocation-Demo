#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Byte size: %d\n", n * sizeof(int));
        
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i)
            ptr[i] = i + 1;

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
            if (i != n - 1) {
                printf("%d, ", ptr[i]);
            } else {
                printf("%d", ptr[i]);
            }

        // Get the new size for the array
        n = 10;
        printf("\n\nNew size of array: %d\n", n);

        // Dynamically re-allocate memory using realloc()
        int* temp = (int*)realloc(ptr, n * sizeof(int));
      
        if (temp== NULL) {
            printf("Reallocation Failed\n");
            free(ptr);
            exit(0);
        }
        ptr = temp;

        printf("Byte size of new array: %d\n", n * sizeof(int));

        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");

        // Get the new elements of the array
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the new array are: ");
        for (i = 0; i < n; ++i)
            if (i != n - 1) {
                printf("%d, ", ptr[i]);
            } else {
                printf("%d", ptr[i]);
            }

        free(ptr);
    }

    return 0;
}

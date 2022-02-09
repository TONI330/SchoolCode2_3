//OPDRACHT 3.2
#include <stdio.h>
// TODO add other libraries as necessary
typedef struct rectangle
{
    int length;
    int width;
} rectangle;

// C program for implementation of Bubble sort
// Source: https://www.geeksforgeeks.org/bubble-sort/
void swap(rectangle *xp, rectangle *yp)
{
    rectangle temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(rectangle arr[], int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < size-i-1; j++) 
           if (surface(arr[j]) > surface(arr[j+1])) //ERROR mag deze values niet lezen
              swap(&arr[j], &arr[j+1]);
}
int surface(rectangle rect)
{
    return rect.length * rect.width;
}
void main(void)
{
    // let the user enter the number of rectangles
    int numberOfRects;
    printf("Enter the number of rectangles you want: ");
    scanf("%i", &numberOfRects);
    // allocate memory to store an array of rectangles using malloc( )
    // Note: don't use calloc( ) (just yet)
    rectangle *arr_ptr;
    int arr_size = sizeof(rectangle) * numberOfRects;
    arr_ptr = (rectangle *) malloc(arr_size);
    // let the user enter length and width of each rectangle and store those in the array
    for(int i = 0; i < numberOfRects; i++){
        //get the length for our rectangles
        printf("Give the length for rectangle %d :", i + 1);
        int length;
        scanf("%i", &length);
        arr_ptr[i].length = length;
        //get the width for our rectangles
        printf("Give the width for rectangle %d :", i + 1);
        int width;
        scanf("%i", &width);
        arr_ptr[i].width = width;
    }
    // print the array of rectangles
    for(int i = 0; i < numberOfRects; i++) {
        printf("Rectangle %i is %i by %i", i, arr_ptr[i].length, arr_ptr[i].width);
    }
    // TODO sort the array by surface area, e.g. using bubble sort
    // or insertion sort
    bubbleSort(arr_ptr, arr_size);
    printf("Sorted it, look!");
    // TODO print the sorted array
    for(int i = 0; i < numberOfRects; i++) {
        printf("Rectangle %i is %i by %i", i, arr_ptr[i].length, arr_ptr[i].width);
    }
    //free memory to prevent leaks
    free(arr_ptr);
}



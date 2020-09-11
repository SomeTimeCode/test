#include <stdio.h>
#include "merge_sort.h"


// merge the four sub-array
// [low, mid1), [mid1, mid2), [mid2, mid3), [mid3, high)
void merge_4_way(int* array, int low, int mid1, int mid2, int mid3, int high) {
    // IMPLEMENT YOUR CODE HERE
    int a, b, c, d, k;

    int n1 = mid1 - low; 
    int n2 = mid2 - mid1;
    int n3 = mid3 - mid2;
    int n4 = high - mid3;

    int array_1[n1], array_2[n2], array_3[n3], array_4[n4];
    for (size_t i = 0; i < n1; i++){
        array_1[i] = array[low + i];
    }
    for (size_t i = 0; i < n2; i++){
        array_2[i] = array[mid1+ i];
    }
    for (size_t i = 0; i < n3; i++){
        array_3[i] = array[mid2+ i];
    }
    for (size_t i = 0; i < n4; i++){
        array_4[i] = array[mid3 + i];
    }
    
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    k = low;
    //four array comparsion
    while (a < n1 && b < n2 && c < n3 && d < n4){
        if (array_1[a] <= array_2[b] && array_1[a] <= array_3[c] && array_1[a] <= array_4[d]){
            array[k] = array_1[a];
            a++;
        }else if (array_2[b] <= array_1[a] && array_2[b] <= array_3[c] && array_2[b] <= array_4[d]){
            array[k] = array_2[b];
            b++;
        }else if (array_3[c] <= array_1[a] && array_3[c] <= array_2[b] && array_3[c] <= array_4[d]){
            
            array[k] = array_3[c];
            c++;
        }else{
            array[k] = array_4[d];
            d++;
        }
        k++;
    }
    
    //three left arrays do comparsion 4C3 
    while (a < n1 && b < n2 && c < n3){
        if (array_1[a] <= array_2[b] && array_1[a] <= array_3[c]){
            array[k] = array_1[a];
            a++;
        }else if (array_2[b] <= array_1[a] && array_2[b] <= array_3[c]){
            array[k] = array_2[b];
            b++;
        }else{
            array[k] = array_3[c];
            c++;
        }
        k++;
    }

    while (a < n1 && b < n2 && d < n4){
        if (array_1[a] <= array_2[b] && array_1[a] <= array_4[d]){
            array[k] = array_1[a];
            a++;
        }else if (array_2[b] <= array_1[a] && array_2[b] <= array_4[d]){  
            array[k] = array_2[b];
            b++;
        }else{
            array[k] = array_4[d];
            d++;
        }
        k++;
    }

    while (a < n1 && c < n3 && d < n4){
        if (array_1[a] <= array_3[c] && array_1[a] <= array_4[d]){
            array[k] = array_1[a];
            a++;
        }else if (array_3[c] <= array_1[a] && array_3[c] <= array_4[d]){
            array[k] = array_3[c];
            c++;
        }else{
            array[k] = array_4[d];
            d++;
        }
        k++;
    }

    while (b < n2 && c < n3 && d < n4){
        if (array_2[b] <= array_3[c] && array_2[b] <= array_4[d]){
            array[k] = array_2[b];
            b++;
        }else if (array_3[c] <= array_2[b] && array_3[c] <= array_4[d]){
            array[k] = array_3[c];
            c++;
        }else{
            array[k] = array_4[d];
            d++;
        }
        k++;
    }

    //do 2 arrays comparsion 4C2
    while (a < n1 && b < n2) { 
        if (array_1[a] <= array_2[b]) { 
            array[k] = array_1[a]; 
            a++; 
        } 
        else { 
            array[k] = array_2[b]; 
            b++; 
        } 
        k++; 
    } 

    while (a < n1 && c < n3) { 
        if (array_1[a] <= array_3[c]) { 
            array[k] = array_1[a]; 
            a++; 
        } 
        else { 
            array[k] = array_3[c]; 
            c++; 
        } 
        k++; 
    }

    while (a < n1 && d< n4) { 
        if (array_1[a] <= array_4[d]) { 
            array[k] = array_1[a]; 
            a++; 
        } 
        else { 
            array[k] = array_4[d]; 
            d++; 
        } 
        k++; 
    }

    while (b < n2 && c < n3) { 
        if (array_2[b] <= array_3[c]) { 
            array[k] = array_2[b]; 
            b++; 
        } 
        else { 
            array[k] = array_3[c]; 
            c++; 
        } 
        k++; 
    }

    while (b < n2 && d < n4) { 
        if (array_2[b] <= array_4[d]) { 
            array[k] = array_2[b]; 
            b++; 
        } 
        else { 
            array[k] = array_4[d]; 
            d++; 
        } 
        k++; 
    }

    while (c < n3 && d < n4) { 
        if (array_3[c] <= array_4[d]) { 
            array[k] = array_3[c]; 
            c++; 
        } 
        else { 
            array[k] = array_4[d]; 
            d++; 
        } 
        k++; 
    }

    //append the ramining array
    while(a<n1){
      array[k]=array_1[a];
      k++;
      a++;
    }
    while(b<n2){
      array[k]=array_2[b];
      k++;
      b++;
    }
    while(c<n3){
      array[k]=array_3[c];
      k++;
      c++;
    }
    while(d<n4){
      array[k]=array_4[d];
      k++;
      d++;
    }

}



// divide the array [low, high) into 4 parts (roughly same size).
// For each part, if # of items > 3, recursively call mergesort_4_way_rec; 
// Otherwise sort them as you like
// Finally use merge_4_way merge them

void mergesort_4_way_rec(int* array, int low, int high) {
    // IMPLEMENT YOUR CODE HERE
    int min2 = (low + high)/2; 
    int min1 = (low + min2)/2;
    int min3 = (min2 + high)/2;

    //do comparsion 
    if(high - low >= 2){
      mergesort_4_way_rec(array, low, min1);
      mergesort_4_way_rec(array, min1, min2);
      mergesort_4_way_rec(array, min2, min3);
      mergesort_4_way_rec(array, min3, high);

      merge_4_way(array, low, min1, min2, min3, high);
    }else{
        return;
    }
    
}
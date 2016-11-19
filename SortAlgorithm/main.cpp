//
//  main.cpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include <iostream>
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"

enum SORT_ALGORITHM {
    
};

int compare (const void* a, const void* b) {
    int valueOfA = *((int*)a);
    int valueOfB = *((int*)b);
    return -(valueOfA - valueOfB);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int array[] = {4, 10, 3 , 5 , 1,3, 10};
    
    
    //QuickSort quickSort;
    //quickSort.sort(array, (int)sizeof(array)/ sizeof(int), sizeof(int), compare);
    
    HeapSort heapSort;
    heapSort.sort(array, (int)sizeof(array)/ sizeof(int), sizeof(int), compare);
    
    std::cout << "Array after sort: " << std::endl;
    for (int i = 0 ; i < (int)sizeof(array)/ sizeof(int) ; i ++) {
        std::cout << array[i] << " ";
    }
    
    return 0;
}

//
//  HeapSort.hpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/10/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include "Sort.hpp"
class HeapSort : Sort {
public:
    HeapSort();
    void sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*));
private:
    void buildHeap(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*));
    void heapify(void* base, int rootIndex, int nElement, int nSize, int (*cmp)(const void*, const void*));
};
#endif /* HeapSort_hpp */

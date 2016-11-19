//
//  QuickSort.hpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include "Sort.hpp"

class QuickSort : public Sort{
public:
    QuickSort();
    void sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*));
    int partition(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*));
    void quickSort(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*));
};
#endif /* QuickSort_hpp */

//
//  MergeSort.hpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include "Sort.hpp"


class MergeSort: public Sort {
    //void*
public:
    explicit MergeSort();
    void sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*));
private:
    void mergeSort(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*));
    
    void merge(void* base, int head, int pivot, int tail, int nSize, int (*cmp)(const void*, const void*));
};
#endif /* MergeSort_hpp */

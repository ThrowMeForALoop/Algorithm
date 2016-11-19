//
//  Sort.hpp
//  SortAlgorithm
//  Base class for any sort algorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
class Sort {
public:
    virtual void sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*)) = 0;
protected:
    void swap (void* a, void* b, int nSize);
};
#endif /* Sort_hpp */

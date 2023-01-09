//
//  Header.h
//  10_06
//
//  Created by Subin Lee on 2022/10/06.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> //open file
#include <math.h>
#include <time.h>
#include <sys/time.h>
using namespace::std;

const int r[] = {1, 2, 4,8,16};
const string sort_type[] = {"insertion_sort", "merge_sort", "quick_sort", "counting_sort","radix_sort"};

double wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)) return 0; //error
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
#endif /* Header_h */

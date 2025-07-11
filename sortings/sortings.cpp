#include "sortings.hpp"



/// SortArr:
void SortArr::sort_bubble()
{
    ;
}

void SortArr::sort_optimize_bubble()
{
    ;
}

void SortArr::sort_insert()
{
    ;
}

void SortArr::sort_selection()
{
    ;
}

void SortArr::sort_merge()
{
    ;
}

void SortArr::sort_quick()
{
    ;
}


void SortArr::print() const
{
    for(uint64_t i = 0; i < SIZE; ++i) {
        printf("%ld", arr[i]);

        if(((i + 1) % SIZE) != 0) {
            printf(" ");
        }
    }
}

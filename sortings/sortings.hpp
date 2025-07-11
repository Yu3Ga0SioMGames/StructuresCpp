#ifndef SORTINGS_HPP_INCLUDED

#define SORTINGS_HPP_INCLUDED


/// C libs(Modern):
#include <ctime>
#include <cstdio>
#include <cstdint>
#include <cstdlib>

/// C++ libs:
#include <limits>
#include <iostream>


class SortArr
{
    private:
        enum {SIZE = 10};

        int64_t arr[SIZE];


        inline const int64_t random(const int64_t MIN, const uint64_t MAX)
        {
            return (MIN + (rand() % ((MAX - MIN) + 1)));
        }



    public:
        SortArr()
        {
            for(uint64_t i = 0; i < SIZE; ++i) {
                arr[i] = random(1, SIZE);
            }
        }


        void sort_bubble();
        void sort_optimize_bubble();
        void sort_insert();
        void sort_selection();
        void sort_merge();
        void sort_quick();

        void print() const;
};


#endif // SORTINGS_HPP_INCLUDED

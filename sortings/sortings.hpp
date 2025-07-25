#ifndef SORTINGS_HPP_INCLUDED

#define SORTINGS_HPP_INCLUDED


/// C libs(Modern):
#include <ctime>
#include <cstdio>
#include <cstdint>
#include <cstdlib>

/// C++ libs:
#include <random> // for the std::random_device & std::mt19937
#include <limits>
#include <iostream>
#include <algorithm>


#define NOT_SORT        'n'

#define BUBBLE          'b'
#define OPTIMIZE_BUBBLE 'o'
#define INSERT          'i'
#define SELECTION       's'
#define MERGE           'm'
#define QUICK           'q'


class SortArr
{
	private:
		enum {SIZE = 100000};

		uint64_t arr[SIZE];

		inline void random(uint64_t arg_arr[], uint64_t sIze,
		                   uint64_t mIn, uint64_t mAx)
		{
			uint64_t range = mAx - mIn + 1;

			for(uint64_t i = 0; i < sIze; ++i) {
				arg_arr[i] = mIn + i;
			}

			std::random_device rd;
			std::mt19937 gen(rd());

			for(uint64_t i = sIze - 1; i > 0; --i) {
				std::uniform_int_distribution<uint64_t> dist(0, i);
				uint64_t j = dist(gen);
				std::swap(arg_arr[i], arg_arr[j]);
			}
		}


	public:
		SortArr()
		{
			random(arr, SIZE, SIZE - SIZE + 1, SIZE);
		}



		void sort_bubble();
		void sort_optimize_bubble();
		void sort_insert();
		void sort_selection();

		void sort_merge(uint64_t [], uint64_t = SIZE);
		void merge_sort(uint64_t [], uint64_t [], uint64_t [],
		                uint64_t, uint64_t);

		void sort_quick();


		void print() const;
		void print(char = NOT_SORT);
};


#endif // SORTINGS_HPP_INCLUDED

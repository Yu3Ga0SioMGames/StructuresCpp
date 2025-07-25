#include "sortings.hpp"




/// SortArr:
void SortArr::sort_bubble()
{
	if(SIZE <= 1) {
		return;
	}

	uint64_t tmp;
	for(uint64_t i = 0; i < SIZE; ++i) {
		for(uint64_t j = 0; j < SIZE - 1 - i; ++j) {
			if(arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


void SortArr::sort_optimize_bubble()
{
	if(SIZE <= 1) {
		return;
	}

	uint8_t swapped;
	uint64_t tmp;
	for(uint64_t i = 0; i < SIZE; ++i) {
		swapped = 0;
		for(uint64_t j = 0; j < SIZE - 1 - i; ++j) {
			if(arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				swapped = 1;
			}
		}

		if(swapped == 0) {
			break;
		}
	}
}


void SortArr::sort_insert()
{
	if(SIZE <= 1) {
		return;
	}

	uint64_t key;
	uint64_t j;
	for(uint64_t i = 1; i < SIZE; ++i) {
		key = arr[i];
		for(j = i; j > 0 && arr[j - 1] > key; --j) {
			arr[j] = arr[j - 1];
		}

		arr[j] = key;
	}
}


void SortArr::sort_selection()
{
	if(SIZE <= 1) {
		return;
	}

	uint64_t tmp;
	uint64_t mIn;
	for(uint64_t i = 0; i < SIZE - 1; ++i) {
		mIn = i;
		for(uint64_t j = i + 1; j < SIZE; ++j) {
			if(arr[mIn] > arr[j]) {
				mIn = j;
			}
		}

		if(mIn != i) {
			tmp = arr[mIn];
			arr[mIn] = arr[i];
			arr[i] = tmp;
		}
	}
}


void SortArr::merge_sort(uint64_t arg_arr[], uint64_t left[], uint64_t right[],
                         uint64_t size_left, uint64_t size_right)
{
	uint64_t i = 0, l = 0, r = 0;



	while(l < size_left && r < size_right) {
		if(left[l] < right[r]) {
			arg_arr[i] = left[l];
			++l;
		} else {
			arg_arr[i] = right[r];
			++r;
		}

		++i;
	}


	while(l < size_left) {
		arg_arr[i] = left[l];
		++i;
		++l;
	}

	while(r < size_right) {
		arg_arr[i] = right[r];
		++i;
		++r;
	}
}

void SortArr::sort_merge(uint64_t arg_arr[], uint64_t sIze)
{
	if(sIze <= 1) {
		return;
	}

	uint64_t middle = sIze / 2;
	uint64_t left[middle], right[sIze - middle];

	for(uint64_t i = 0; i < sIze; ++i) {
		if(i < middle) {
			left[i] = arg_arr[i];
		}
	}

	for(uint64_t i = middle; i < sIze; ++i) {
		right[i - middle] = arg_arr[i];
	}

	sort_merge(left, middle);
	sort_merge(right, sIze - middle);
	merge_sort(arg_arr, left, right, middle, sIze - middle);
}


void SortArr::sort_quick()
{
	if(SIZE <= 1) {
		return;
	}

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


void SortArr::print(char SORT)
{
	switch(SORT) {
		case BUBBLE:
			sort_bubble();
			break;

		case OPTIMIZE_BUBBLE:
			sort_optimize_bubble();
			break;

		case INSERT:
			sort_insert();
			break;

		case SELECTION:
			sort_selection();
			break;

		case MERGE:
			sort_merge(arr);
			break;

		case QUICK:
			sort_quick();
			break;


		default:
			break;
	}

	for(uint64_t i = 0; i < SIZE; ++i) {
		printf("%ld", arr[i]);

		if(((i + 1) % SIZE) != 0) {
			printf(" ");
		}
	}
}

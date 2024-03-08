#include <stdio.h>
#include <stdlib.h>

int* generate_ref_arr(size_t sz, size_t page_max);
int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz);

// Driver code
//  Usage: ./program {ref_arr_size} {page_max} {frame_size}
int main(int argc, char** argv) {
    if (argc < 4) return -1;
    
    int ref_arr_sz = atoi(argv[1]);
    int page_max = atoi(argv[2]);
    int frame_sz = atoi(argv[3]);

    int* ref = generate_ref_arr(ref_arr_sz, page_max);
    int page_faults = lru(ref, ref_arr_sz, frame_sz, page_max);
    printf("%d\n", page_faults);
    free(ref);

    return 0;
}

int* generate_ref_arr(size_t sz, size_t page_max) {
    int* ref_arr = (int*) malloc(sizeof(int) * sz);
    
    // TODO :: Generate Random Refernece String
	
	for(int i = 0; i < sz; i++) {
		ref_arr[i] = rand() % page_max;
	}

    return ref_arr;
}

int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz, size_t page_max) {
    int i, j;
    int page_faults = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = -1;

    // TODO
	
	int pos = =1;				// frame에서 마지막까지 저장된 위치
	int min_pos = -1;			// frame에서 reference bit가 가장 작은 위치
	int is_found = -1;			// frame 내에서 발견됨을 알려주는 인자
	int ref_bit[page_max];
	for(i = 0; i < page_max; i++) ref_bit[i] = 0;
	
	for(i = 0; i < ref_arr_sz; i++) {
		
	}

    return page_faults;
}


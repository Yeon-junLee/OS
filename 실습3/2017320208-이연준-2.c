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
    int page_faults = lru(ref, ref_arr_sz, frame_sz);
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

int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz) {
    int i, j;
    int page_faults = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = -1;

    // TODO
	int clockpin = 0;
	int ref_bit[frame_sz];
	int is_found = -1;
	int found_index = -1;
	for(i = 0; i < frame_sz; i++)
		ref_bit[i] = 0;
	
	for(i = 0; i < ref_arr_sz; i++) {
		for(j = 0; j < frame_sz; j++) {			// finding in frame
			if(frames[j] == ref_arr[i]) {
				is_found = 1;
				found_index = j;
			}
		}
		
		if(is_found == 1) {						// found in frame
			ref_bit[j] = 1;
			clockpin = j;
		}
		else {										// not found in frame
			while(ref_bit[clockpin % frame_sz] != 0) {				// find frame whose ref_bit == 0
				ref_bit[clockpin % frame_sz] = 0;
				clockpin++;
			}
			
			frames[clockpin % frame_sz] = ref_arr[i];
			ref_bit[clockpin % frame_sz] = 1;
			clockpin++;
		}
		page_faults++;
		is_found = -1;
		found_index = -1;
	}	

    return page_faults;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("%d ", ref_arr[i]);
	}
	
	printf("\n");
	
    return ref_arr;
}

int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz) {
    int i, j;
    int page_faults = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = -1;

    // TODO
	int num_full = 0;
	int found_index = -1;							// page found frame
	int top, temp;
	for(i = 0; i < ref_arr_sz; i++) {
		printf("%d | ", ref_arr[i]);
		if(num_full != frame_sz) {				// frame is not full
			for(j = 0; j < num_full - 1; j++) {		// find in frame
				if(ref_arr[i] == frames[j])	found_index = j;
			}
			if(found_index != -1) {				// duplicate frame is found
				printf("found_index value = %d\n",found_index);
				top = frames[found_index];
				memmove(frames + 1, frames, sizeof(int) * (found_index - 1));		// move frames
				frames[0] = top;
				
				for (int r = 0; r < frame_sz; r++) {
					if(frames[i] != -1)	printf("%d ",frames[i]);
					else	printf(". ");
				}
				
			}
			
			else {								// duplicate frame is not found
				memmove(frames + 1, frames, sizeof(int) * num_full);
				frames[0] = ref_arr[i];
				num_full++;
				page_faults++;
				
				for (int r = 0; r < frame_sz; r++) {
					if(frames[i] != -1)	printf("%d ",frames[i]);
					else	printf(". ");
				}
				printf("(falut)");
				
			}
		}
		
		else {									// frame is full
		printf("%d | ", ref_arr[i]);
			for(j = 0; j < num_full - 1; j++) {		// find in frame
				if(ref_arr[i] == frames[j])	found_index = j;
			}
			if(found_index != -1) {				// duplicate frame is found
				printf("found_index value = %d\n",found_index);
				top = frames[found_index];
				memmove(frames + 1, frames, sizeof(int) * (found_index - 1));		// move frames
				frames[0] = top;
				
				for (int r = 0; r < frame_sz; r++) {
					if(frames[i] != -1)	printf("%d ",frames[i]);
					else	printf(". ");
				}
				
			}
			
			else {								// duplicate frame is not found
				memmove(frames + 1, frames, sizeof(int) * num_full);
				frames[0] = ref_arr[i];
				page_faults++;
				
				for (int r = 0; r < frame_sz; r++) {
					if(frames[i] != -1)	printf("%d ",frames[i]);
					else	printf(". ");
				}
				printf("(falut)");
				
			}
		}
		
		found_index = -1;
		printf("\n");
	}

    return page_faults;
}


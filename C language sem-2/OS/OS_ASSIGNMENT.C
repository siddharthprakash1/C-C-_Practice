//Siddharth Prakash
//PES2UG21CS523
#include <stdio.h>
#include <stdlib.h>
int simulate_segmentation(int segment_number, int offset, int base_address, int segment_limit) {
    int physical_address;
    if (offset >= segment_limit) {
        printf("Error: offset is outside the segment limit.\n");
        return -1;
    }
    physical_address = base_address + offset + (segment_number * segment_limit);
    return physical_address;
}
int main() {
    int segment_number, offset, base_address, segment_limit, physical_address;
    printf("Enter segment number: ");
    scanf("%d", &segment_number);
    printf("Enter offset: ");
    scanf("%d", &offset);
    printf("Enter base address: ");
    scanf("%d", &base_address);
    printf("Enter segment limit: ");
    scanf("%d", &segment_limit);
    physical_address = simulate_segmentation(segment_number, offset, base_address, segment_limit);
    if (physical_address != -1) {
        printf("Physical address: %d\n", physical_address);
    }
    return 0;
}
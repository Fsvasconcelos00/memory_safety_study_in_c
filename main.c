#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void random_pointerUsage(uint32_t* my_randomPointer)
{
    printf("Pointer value: %d\n", (*my_randomPointer));
    (*my_randomPointer) = 1;
}

int main(void)
{
    uint32_t random_value = 5;
    uint32_t* random_pointer = NULL;

    // (*random_pointer) = 5; // This would result in a segmentation fault
    random_pointer = &random_value; // This will fix the segmentation fault

    printf("Pointer address: %p\n", random_pointer);
    random_pointerUsage(random_pointer);
    random_pointerUsage(random_pointer);

    return(0);
}
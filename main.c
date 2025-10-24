#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void dangling_pointerBomb(uint32_t** my_randomPointer)
{
    uint32_t temp_value = 10;

    // temp_value is a local variable and won't exist when the function goes out of scope
    // This will change the random_pointer address on the main function
    (*my_randomPointer) = &temp_value;
}

int main(void)
{
    uint32_t random_value = 5;
    uint32_t* random_pointer = NULL;

    
    // Dereferencing uninitialized or NULL pointers
    // (*random_pointer) = 5; // This would result in a segmentation fault

    random_pointer = &random_value; // Initializing the pointer will fix the segmentation fault

    printf("Pointer address: %p\n", random_pointer);
    dangling_pointerBomb(&random_pointer);
    printf("Pointer address: %p\n", random_pointer);

    return(0);
}
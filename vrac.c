// Counter-Based Loop
int i = 0;
while (i < 5) { // The condition is a comparison
    printf("i is %d\n", i);
    i++; // The variable is changed inside the loop
}

// Flag-Based Loop
#include <stdbool.h> // For using bool, true, and false

bool running = true;
while (running) { // The condition checks the boolean variable
    printf("Running...\n");
    // Some logic might change the flag
    if (/* some condition is met */) {
        running = false;
    }
}

// Pointer-Based Loop
// Assuming 'node' is a pointer to a struct in a linked list
while (node) { // Equivalent to: while (node != NULL)
    printf("Node value: %d\n", node->value);
    node = node->next;
}

// Infinite Loop
while (1) { // 1 is always true
    printf("Looping forever...\n");
    if (/* some exit condition */) {
        break; // Exit the loop
    }
}

// Type Casting and Floating-Point Division
#include <stdio.h>

int main(void) {
    int i = 3;
    int j = 2;

    printf("%f\n", (float)i / j);

    return 0;
}

/* read char
usage --> ./copycat < hello.txt
*/
#include <stdio.h>

int main(void) {
    int c; // Use 'int' to correctly handle the EOF value.

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}

// allocate memory
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = NULL;

    // 1. Allocate memory
    p = (int*)malloc(sizeof(int));

    // 2. Check if allocation was successful
    if (p == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // 3. Use the allocated memory
    *p = 42;
    printf("Successfully allocated memory.\n");
    printf("Value stored at the address %p is: %d\n", (void*)p, *p);

    // 4. Free the memory when done
    free(p);
    p = NULL; // Good practice to nullify pointer after freeing

    return 0; // Exit successfully
}

/*
sizeof(int): This operator calculates the amount of memory (in bytes) that one integer requires. This makes the code portable, as the size of an int can vary between systems (e.g., 4 bytes on most modern systems).

malloc(...): The malloc function (which stands for "memory allocation") is called with the number of bytes calculated by sizeof(int). It finds a free block of that size in the computer's memory (specifically, on the heap) and reserves it. It returns a void* (a generic pointer) to the beginning of this newly allocated block. If it fails to find enough memory, it returns NULL.

(int*): This is a type cast. Since malloc returns a generic void* pointer, this cast explicitly converts it to the type int* (a pointer to an integer) to match the type of our pointer p. While this cast is required in C++, it is optional in C, but many programmers include it for clarity.

p = ...: The memory address returned by malloc is assigned to the pointer p. Now, p holds the address of the block of memory that was just allocated. You can now use *p to access and modify the integer value stored at that location.

Complete Program: The logic is wrapped in a standard int main(void) function, making it a fully functional program.

Error Checking: It includes a critical if (p == NULL) block. malloc returns NULL if it cannot allocate the requested memory, and a robust program must always check for this failure.

Using the Memory: The program now actually uses the allocated memory by assigning a value (*p = 42) and printing it, demonstrating that the allocation worked.

Freeing Memory: It calls free(p) to release the memory back to the operating system. For every malloc, there should be a corresponding free to prevent memory leaks.

Pointer Nullification: After freeing, p is set to NULL. This prevents accidental use of a "dangling pointer" (a pointer that no longer points to valid memory).
*/

// pointer declaration and usage
#include <stdio.h>

// 1. DECLARATION: This function says it needs an ADDRESS of an integer.
// The local pointer variable is named 'p'.
void add_five(int *p) {
    // 2. USAGE: Inside the function, 'p' holds the address of 'my_number'.
    // '*p' means "go to that address and get the value".
    // So this line becomes: value_at_p = value_at_p + 5;
    *p = *p + 5; 
}

int main(void) {
    int my_number = 10;

    printf("Before: %d\n", my_number); // Prints 10

    // We pass the ADDRESS of my_number using the '&' operator.
    add_five(&my_number);

    printf("After: %d\n", my_number); // Prints 15
    return 0;
}

*/
Declaration (int *p): The * defines p as a pointer.

Usage (*p): The * is an action that fetches the value from the pointer's address.
*/

// print integer
#include <stdio.h>

int main() {
    int my_number = 42;
    printf("%d\n", my_number);
    return 0;
}

// ft_puchar for int 42
#include <unistd.h>

// A function to write a single character to the standard output.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	number;
	char	tens_digit;
	char	units_digit;

	// 1. Store the integer 42 in a variable.
	number = 42;

	// 2. Isolate the tens digit and convert it to its character equivalent.
	//    42 / 10 = 4
	//    '0' + 4 = '4'
	tens_digit = '0' + (number / 10);

	// 3. Isolate the units digit and convert it to its character equivalent.
	//    42 % 10 = 2
	//    '0' + 2 = '2'
	units_digit = '0' + (number % 10);

	// 4. Print the characters one by one.
	ft_putchar(tens_digit);
	ft_putchar(units_digit);
	ft_putchar('\n'); // Add a newline for cleaner terminal output

	return (0);
}

// storing strings, when C has no built-in string type
// The Character Array char[]
#include <stdio.h>
#include <string.h>

int main() {
    // Declares an array of 20 chars and copies "Hello" into it.
    // The memory layout is: H e l l o \0 ... (14 empty slots)
    char greeting[20] = "Hello";

    printf("Initial string: %s\n", greeting);

    // This is LEGAL because 'greeting' is a mutable array we own.
    strcpy(greeting, "World"); 
    
    printf("Modified string: %s\n", greeting); // Prints "World"

    return 0;
}

// The Character Pointer char *
#include <stdio.h>

int main() {
    // 'greeting_ptr' points to the address of the read-only literal "Hello".
    char *greeting_ptr = "Hello";

    printf("String: %s\n", greeting_ptr);
    
    // You can make the pointer point to a different string.
    greeting_ptr = "World";
    printf("Pointer now points to: %s\n", greeting_ptr);

    // This is ILLEGAL and will likely crash your program.
    // greeting_ptr[0] = 'J'; // CRASH! Trying to modify read-only memory.

    return 0;
}

// print string
#include <stdio.h>

// 'const' is a promise that this function will not change the string.
void print_string(const char *str) {
    printf("%s\n", str);
}

int main() {
    char my_name[] = "Gemini";
    char *my_location = "France";

    print_string(my_name);     // Works
    print_string(my_location); // Works
    
    return 0;
}

// strcpy
#include <stdio.h>
#include <string.h>

int main() {
    // Declares an array of 20 chars and copies "Hello" into it.
    // The memory layout is: H e l l o \0 ... (14 empty slots)
    char greeting[20] = "Hello";

    printf("Initial string: %s\n", greeting);

    // This is LEGAL because 'greeting' is a mutable array we own.
    strcpy(greeting, "World"); 
    
    printf("Modified string: %s\n", greeting); // Prints "World"

    return 0;
}

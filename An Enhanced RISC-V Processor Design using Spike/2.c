#include <stdio.h>
int main ()
{
    int a[10] = {0}, b[10]= {0}, c[10] = {0}; 
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt", "r");
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);
    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];
    /* Original C code segment
    for (int i = 0; i < arr_size; i++){
    *p_c++ = *p_a++ / *p_b++;
    }
    */
    for (int i = 0; i < arr_size; i++)
    asm volatile(
   	"lw x5, 0(%[p_a])\n\t"
        "lw x6, 0(%[p_b])\n\t"
        "div x7, x5, x6\n\t"
        "sw x7, 0(%[p_c])\n\t"
        "addi %[p_a], %[p_a], 4\n\t"
        "addi %[p_b], %[p_b], 4\n\t"
        "addi %[p_c], %[p_c], 4\n\t"	
	    :[p_a] "+r"(p_a), [p_b] "+r"(p_b), [p_c] "+r"(p_c)	
    );
    p_c = &c[0];
    for (int i = 0; i < arr_size; i++)
    printf("%d ", *p_c++);
    printf("\n");
    return 0;
}

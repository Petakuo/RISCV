#include<stdio.h>
int main()
{ 
    int i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/4.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];
    
    asm volatile(
	"add x18, x0, x0\n\t"   //i = 0
	"addi x21, x0, 2\n\t"   //2
	"addi x22, x0, 3\n\t"   //3
	"L1:	\n\t"
		"add x19, x0, x0\n\t"   //j = 0
	"L2:	\n\t"
		"add x20, x0, x0\n\t"   //f = 0
	"L3:	\n\t"
		"addi x5, x0, 4\n\t"
  		"addi x6, x0, 8\n\t"
  		"addi x7, x0, 12\n\t"
  		"mul x28, x7, x18\n\t"   //3i
  		"mul x29, x5, x20\n\t"   //f
  		"add x29, x28, x29\n\t"   //3i+f
  		"mul x30, x6, x20\n\t"   //2f
  		"mul x31, x5, x19\n\t"   //j
  		"add x31, x30, x31\n\t"   //2f+j
  		"mul x28, x6, x18\n\t"   //2i
	  	"mul x30, x5, x19\n\t"   //j
  		"add x30, x28, x30\n\t"   //2i+j
  
  		"add x31, x31, %[p_x]\n\t"
  		"add x29, x29, %[p_h]\n\t"
  		"add x30, x30, %[p_y]\n\t"
  
  		"lw x5, 0(x31)\n\t"
  		"lw x6, 0(x29)\n\t"
  		"lw x7, 0(x30)\n\t"
  		"mul x6, x5, x6\n\t"
  		"add x7, x7, x6\n\t"
  		"sw x7, 0(x30)\n\t"
  		
  		"addi x20, x20, 1\n\t"   //f+=1
  		"bne x20, x22, L3\n\t"
  		"addi x19, x19, 1\n\t"   //j+=1
  		"bne x19, x21, L2\n\t"
  		"addi x18, x18, 1\n\t"   //i+=1
  		"bne x18, x22, L1\n\t"

  	: [p_x] "+r"(p_x), [p_h] "+r"(p_h), [p_y] "+r"(p_y)
     );

    p_y = &y[0];
    for(i = 0; i < 6; i++)
    printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}

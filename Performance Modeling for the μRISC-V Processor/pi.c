"li x5, 0\n\t"	//i = 0
"li x7, -1\n\t"	//-1

"addi %[lw_cnt], %[lw_cnt], 2\n\t"

"Loop: \n\t"
	"li x6, 0\n\t"	//term = 0
	"andi x28, x5, 1\n\t"	//i%2
	"beq x28, x0, E1\n\t"	//if i is even, go to E1
	"add x6, x0, x7\n\t"	//term = -1
	"addi %[add_cnt], %[add_cnt], 1\n\t"
	"addi %[others_cnt], %[others_cnt], 1\n\t"
	"bne x6, x0, E2\n\t"	//go to E2
	"addi %[others_cnt], %[others_cnt], 1\n\t"
"E1: \n\t"
	"addi x6, x0, 1\n\t"	//term = 1
	"addi %[add_cnt], %[add_cnt], 1\n\t"
"E2: \n\t"
	"add x29, x5, x5\n\t"    //2i
	"addi x29, x29, 1\n\t"    //2i+1
	
	"fcvt.d.w f1, x6\n\t"
	"fcvt.d.w f2, x29\n\t"
	
	"fdiv.d f1, f1, f2\n\t"	//term = (-1)^i / (2*i+1)
	"fadd.d %[pi], %[pi], f1\n\t"	//pi += term
	"addi x5, x5, 1\n\t"	//i+=1
	
	"addi %[add_cnt], %[add_cnt], 4\n\t"
	"addi %[sub_cnt], %[sub_cnt], 0\n\t"
	"addi %[mul_cnt], %[mul_cnt], 0\n\t"
	"addi %[div_cnt], %[div_cnt], 1\n\t"
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"
	"addi %[sw_cnt], %[sw_cnt], 0\n\t"
	"addi %[others_cnt], %[others_cnt], 5\n\t"
		
	"bne x5, %[N], Loop\n\t"

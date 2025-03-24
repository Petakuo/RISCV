"add x5, x0, x0\n\t"	//i = 0
"addi %[add_cnt], %[add_cnt], 1\n\t"
"Loop: \n\t"
	"lh t1, 0(%[h])\n\t"
	"lh t2, 0(%[x])\n\t"
	"mul x6, t1, t2\n\t"
	"add x6, x6, %[id]\n\t"
	"sh x6, 0(%[y])\n\t"

	"addi %[h], %[h], 2\n\t"
	"addi %[x], %[x], 2\n\t"
	"addi %[y], %[y], 2\n\t"
	"addi x5, x5, 1\n\t"	//i+=1   

	"addi %[add_cnt], %[add_cnt], 5\n\t"
	"addi %[sub_cnt], %[sub_cnt], 0\n\t"
	"addi %[mul_cnt], %[mul_cnt], 1\n\t"
	"addi %[div_cnt], %[div_cnt], 0\n\t"
	"addi %[lw_cnt], %[lw_cnt], 2\n\t"
	"addi %[sw_cnt], %[sw_cnt], 1\n\t"
	"addi %[others_cnt], %[others_cnt], 1\n\t"

	"bne x5, %[arr_size], Loop\n\t"

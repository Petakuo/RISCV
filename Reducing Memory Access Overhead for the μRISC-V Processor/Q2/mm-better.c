void matrix_multiplication(int *a, int *b, int *output, int i,
			   int k, int j) {
    for (int x = 0; x < i; x++) {
        for (int z = 0; z < k; z++) {
            int sum = a[x * k + z];
            for (int y = 0; y < j; y++) {
                output[x * j + y] += sum * b[z * j + y];
            }
        }
    }
    return;
}

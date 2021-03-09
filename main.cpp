#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main() {
	int base, degree;
	POLYNOMIAL pol1;
	POLYNOMIAL pol2;
	POLYNOMIAL pol_sum;
	POLYNOMIAL pol_sum_f;
	POLYNOMIAL pol_diff;
	POLYNOMIAL pol_diff_f;
	POLYNOMIAL pol_mult;
	POLYNOMIAL pol_mult_f;

	char input_pol1[] = "pol1";
	char input_pol2[] = "pol2";
	char title_sum[] = "pol1 + pol2";
	char title_dif[] = "pol1 - pol2";
	char title_mult[] = "pol1 * pol2";

	printf("Input simple base: ");
	scanf("%i", &base);

	int p = prime(base);
	if (p == 0) { 
		printf("It is not prime\n");
		return 1;
	}

	printf("Input degree: ");
	scanf("%i", &degree);


	input(input_pol1, &pol1, base, degree);
	cut(&pol1, base, degree);
	print_struct(input_pol1, &pol1);
	
	input(input_pol2, &pol2, base, degree);
	cut(&pol2, base, degree);
	print_struct(input_pol2, &pol2);

	sum(&pol1, &pol2, &pol_sum);
	cut(&pol_sum, base, degree);
	print_struct(title_sum, &pol_sum);
	
	difference(&pol1, &pol2, &pol_diff);
	cut(&pol_diff, base, degree);
	print_struct(title_dif, &pol_diff);

	mult(&pol1, &pol2, &pol_mult);
	cut(&pol_mult, base, degree);
	print_struct(title_mult, &pol_mult);
	
	return 0;
}
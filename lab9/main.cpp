#include "struct_math.h"

int main() {
	POLYNOMIAL pol1;
	POLYNOMIAL pol2;
	POLYNOMIAL pol_sum;
	POLYNOMIAL pol_diff;
	POLYNOMIAL pol_mult;

	char input_pol1[] = "pol1";
	char input_pol2[] = "pol2";
	char title_sum[] = "pol1 + pol2";
	char title_dif[] = "pol1 - pol2";
	char title_mult[] = "pol1 * pol2";

	input(input_pol1, &pol1);
	print_struct(input_pol1, &pol1);
	
	input(input_pol2, &pol2);
	print_struct(input_pol2, &pol2);

	sum(&pol1, &pol2, &pol_sum);
	print_struct(title_sum, &pol_sum);
	
	difference(&pol1, &pol2, &pol_diff);
	print_struct(title_dif, &pol_diff);

	mult(&pol1, &pol2, &pol_mult);
	print_struct(title_mult, &pol_mult);

	return 0;
}
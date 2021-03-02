#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "struct_math.h"

void sum(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_sum) {
	int i;
	pol_sum->size = (pol1->size > pol2->size) ? pol1->size : pol2->size;

	for (i = 0; i < (int)pol_sum->size; i++) {
		pol_sum->coeff[i] = pol1->coeff[i] + pol2->coeff[i];
	}
}

void difference(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_diff) {
	int i;
	pol_diff->size = (pol1->size > pol2->size) ? pol1->size : pol2->size;

	for (i = 0; i < (int)pol_diff->size; i++) {
		pol_diff->coeff[i] = pol1->coeff[i] - pol2->coeff[i];
	}
}

void mult(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_mult) {
	int pow1, pow2, pow;

	pol_mult->size = pol1->size + pol2->size - 1;

	for (pow1 = 0; pow1 < (int)pol1->size; pow1++) {
		for (pow2 = 0; pow2 < (int)pol2->size; pow2++) {
			pow = pow1 + pow2;
			pol_mult->coeff[pow] += pol1->coeff[pow1] * pol2->coeff[pow2];
		}
	}
}

void print_struct(char title[], POLYNOMIAL* pol) {
	int pow;
	char sign;
	float abs_value;

	printf("%s: ", title);

	for (pow = (int)pol->size - 1; pow >= 0; pow--) {
		if (pol->coeff[pow] >= 0) {
			sign = '+';
			abs_value = pol->coeff[pow];
		}
		else {
			sign = '-';
			abs_value = -pol->coeff[pow];
		}

		if (pow < (int)pol->size - 1 || sign == '-') {
			printf("%c ", sign);
		}
		if (pow == 0) { 
			printf("%.3f\n", abs_value);
		}
		else if (pow == 1) {
			printf("%.3fx ", abs_value);
		}
		else {
			printf("%.3fx^%i ", abs_value, pow);
		}
	}
}

void input(char title[], POLYNOMIAL* pol) {
	int pow = 0, sf_res1, sf_res2;
	float coeff;

	printf("%s\n", title);
	printf("Input pow (int): ");
	sf_res1 = scanf("%i", &pow);

	if (pow < 0 || sf_res1 == 0) {
		printf("Invalid value\n");
		exit(1);
	}
	pol->size = pow + 1;

	for (; pow >= 0; pow--) {
		printf("x^%i (float): ", pow);
		sf_res2 = scanf("%f", &coeff);
		if (sf_res2 == 0) {
			printf("Invalid value\n");
			exit(1);
		}
		pol->coeff[pow] = coeff;
	}
}

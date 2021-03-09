#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

void sum(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_sum) {
	int i, coeff;
	pol_sum->size = (pol1->size > pol2->size) ? pol1->size : pol2->size;

	for (i = 0; i < (int)pol_sum->size; i++) {
		coeff = pol1->coeff[i] + pol2->coeff[i];
		pol_sum->coeff[i] = coeff;
	}
}

void difference(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_diff) {
	int i, coeff;
	pol_diff->size = (pol1->size > pol2->size) ? pol1->size : pol2->size;

	for (i = 0; i < (int)pol_diff->size; i++) {
		coeff = pol1->coeff[i] - pol2->coeff[i];
		pol_diff->coeff[i] = coeff;
	}
}

void mult(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_mult) {
	int pow1, pow2, pow;

	pol_mult->size = pol1->size + pol2->size - 1;

	for (pow1 = 0; pow1 < (int)pol1->size; pow1++) {
		for (pow2 = 0; pow2 < (int)pol2->size; pow2++) {
			pow = pow1 + pow2;
			pol_mult->coeff[pow] += (pol1->coeff[pow1] * pol2->coeff[pow2]);
		}
	}
}

void cut(POLYNOMIAL* pol, int base, int degree) {
	if ((int)pol->size >= degree) {
		pol->size = degree;
		for (int i = 0; i <= (int)pol->size; i++) {

			if (pol->coeff[i] < 0) {
				for (; pol->coeff[i] < 0;) {
					pol->coeff[i] += base;
				}
			}

			pol->coeff[i] = pol->coeff[i] % base;
		}
	}
}

void print_struct(char title[], POLYNOMIAL* pol) {
	int pow = (int)pol->size - 1, abs_value;
	char sign;

	printf("%s: ", title);
	for (; pow >= 0; pow--) {
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
			printf("%i\n", abs_value);
		}
		else if (pow == 1) {
			printf("%ix ", abs_value);
		}
		else {
			printf("%ix^%i ", abs_value, pow);
		}
		
	} 
}

void input(char title[], POLYNOMIAL* pol, int f, int degree) {
	int pow = 0, sf_res1, sf_res2;
	int coeff;

	printf("%s\n", title);
	printf("Input pow (int): ");
	sf_res1 = scanf("%i", &pow);

	if (pow < 0 || sf_res1 == 0) {
		printf("Invalid value\n");
		exit(1);
	}
	pow = pow < degree - 1 ? pow : degree - 1;
	pol->size = pow + 1; 

	for (; pow >= 0; pow--) {
		printf("x^%i (int): ", pow);
		sf_res2 = scanf("%i", &coeff);
		if (sf_res2 == 0) {
			printf("Invalid value\n");
			exit(1);
		}
		pol->coeff[pow] = coeff;
	}
}

int prime(int n) {
	int count = 0, i = 1;
	if (n == 1) {
		count = 2;
	}
	else {
		for (i = 1; i <= n; i++) {
			if (n % i == 0) {
				count++;
				if (count > 2) return 0;
			}
		}
	}
	if (count == 2) {
		return 1;
	}
	return 0;
}

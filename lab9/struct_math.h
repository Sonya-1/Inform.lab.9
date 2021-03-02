#ifndef A_H
#define A_H

struct POLYNOMIAL {
	float coeff[100] = { 0 };
	size_t size = 0;
};

void sum(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_sum);
void difference(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_diff);
void mult(POLYNOMIAL* pol1, POLYNOMIAL* pol2, POLYNOMIAL* pol_mult);
void print_struct(char title[], POLYNOMIAL* pol);
void input(char title[], POLYNOMIAL* pol);

#endif

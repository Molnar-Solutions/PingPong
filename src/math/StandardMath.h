#ifndef ENGINE_STANDARD_MATH_MD_H
#define ENGINE_STANDARD_MATH_MD_H

#include <iostream>
#define e 2.718281828182818281828182818281828
#define PI 3.141592653589793238462643383279502884197
#define EXP_A 184
#define EXP_C 16249 

class StandardMath {
public:
	static float convertDegreeToRadian(float degree)
	{
		/* Radians = Degrees × (π / 180) */
		return degree * (PI / 180);
	}

	static float convertRadianToDegree(float radian)
	{
		/* Radian * (180/π) = Degree */
		return radian * (180 / PI);
	}

	static float abs(float value)
	{
		return value >= 0 ? value : (value * (-1));
	}

	static int fact(int x)
	{
		if (x == 1)
		{
			return 1;
		}

		return x * fact(x - 1);
	}

	static float pow(float base, float ex)
	{
		if (base == 0) return 0;
		if (ex == 0) return 1;

		if (ex < 0) return 1 / pow(base, -ex);
		if (ex > 0 && ex < 1) return nth_root(base, 1 / ex);
		if ((int)ex % 2 == 0) {
			/* For optimization */
			float half_pow = pow(base, ex / 2);
			return half_pow * half_pow;
		}

		/* integer exponent */
		return base * pow(base, ex - 1);
	}

	static float nth_root(float A, int n)
	{
		const int K = 6;
		float x[K] = { 1 };
		for (int k = 0; k < K - 1; k++)
		{
			x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / pow(x[k], n - 1));
		}
		return x[K - 1];
	}

	static float sin(float x)
	{
		float summa = 0.0f;

		for (int i = 0; i < 15; i++)
		{
			summa += pow(-1, i) * ((pow(x, 2 * i + 1)) / fact(2 * i + 1));
		}

		return summa;
	}

	static float cos(float x)
	{
		float summa = 0.0f;

		for (int i = 0; i < 15; i++)
		{
			summa += pow(-1, i) * ((pow(x, 2 * i) / fact(2 * i + 1)));
		}

		return summa;
	}

	static short min(short a, short b)
	{
		return a > b ? b : a;
	}

	static int min(int a, int b)
	{
		return a > b ? b : a;
	}

	static short max(short a, short b)
	{
		return a > b ? a : b;
	}

	static int max(int a, int b)
	{
		return a > b ? a : b;
	}

	static float sinh(float x)
	{
		float summa = 0.0f;

		for (int i = 0; i < 15; i++)
		{
			summa += (pow(x, 2*i+1) / fact(2*i+1));
		}
	}

	static float cosh(float x)
	{
		float summa = 0.0f;

		for (int i = 0; i < 15; i++)
		{
			summa += (pow(x, 2*i)) / fact(2 * i);
		}
	}
};

#endif // MATH_H

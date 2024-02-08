#include "pch.h"
#include "hamhanded.h"
#include <cctype>
#include <cstdint>
#include <stdlib.h>
#include <corecrt_math.h>

//enum class MathOperations : uint8_t
//{
//	None = 0,
//	Add,
//	Sub,
//	Mul,
//	Div,
//	Sin,
//};
//
//long double hhCalcAddFloat(const char* str)
//{
//	long double nubmers[128];
//	MathOperations operations[128];
//	bool signs[128];
//	int idx = 0;
//}
// 
//auto f = 1 & 2 && 4 + 5 == 7;
//auto b = 0b10001;

long double hhCalcFloat(const char* str)
{
	char c;
	double div = 10.0;

	long double numbers[128] = { 0 };
	char signs[128] = { 0 };

	bool floatPiece = false;

	// getting numbers and math signs
	int i = 0;
	while (0 != (c = *str++))
	{
		if (!isdigit(c))
		{
			if (c == '+' || c == '-' || c == '*' || c == '/') {
				signs[++i] = c;

				floatPiece = false;
				div = 10.0;

				continue;
			}
			else if (c == '.') {
				floatPiece = true;
				continue;
			}
		}

		if(!floatPiece)
			numbers[i] = numbers[i] * 10 + (c - '0');
		else {
			numbers[i] = numbers[i] + (c - '0') / div;
			div *= 10;
		}
	}

	// do math operations with priority [*, /]
	i = 0;
	while (signs[++i] != 0)
	{
		if (signs[i] == '*') {
			numbers[i] *= numbers[i - 1];
			numbers[i - 1] = -1;
		}
		else if (signs[i] == '/') {
			numbers[i] = numbers[i - 1] / numbers[i];
			numbers[i - 1] = -1;
		}
	}

	// do other math operations
	i = 0;
	int iNumbers = -1;
	while (signs[++i] != 0)
	{
		switch (signs[i]) {
		case '*':
			continue;

		case '/':
			continue;
		}

		if (numbers[i] == -1) {
			if (iNumbers == -1) {
				iNumbers = i + 1;
			}

			while (numbers[iNumbers] == -1)
				iNumbers++;
		}

		switch (signs[i]) {
		case '+':
			if (iNumbers != -1) {
				numbers[iNumbers] += numbers[i - 1];
				iNumbers = -1;
			}
			else {
				numbers[i] += numbers[i - 1];
			}

			numbers[i - 1] = -1;
			continue;

		case '-':
			if (iNumbers != -1) {
				numbers[iNumbers] = numbers[i - 1] - numbers[iNumbers];
				iNumbers = -1;
			}
			else {
				numbers[i] = numbers[i - 1] - numbers[i];
			}

			numbers[i - 1] = -1;
			continue;
		}
	}


	return numbers[i - 1];
}

int hhCalc(const char* str)
{
	char c;

	int numbers[128] = { 0 };
	char signs[128] = { 0 };

	// getting numbers and math signs
	int i = 0;
	while (0 != (c = *str++))
	{
		if (!isdigit(c))
		{
			if (c == '+' || c == '-' || c == '*' || c == '/') {
				signs[++i] = c;
				continue;
			}
		}

		numbers[i] = numbers[i] * 10 + (c - '0');
	}

	// do math operations with priority [*, /]
	i = 0;
	while (signs[++i] != 0)
	{
		if (signs[i] == '*') {
			numbers[i] *= numbers[i - 1];
			numbers[i - 1] = -1;
		}
		else if (signs[i] == '/') {
			numbers[i] = numbers[i - 1] / numbers[i];
			numbers[i - 1] = -1;
		}
	}

	// do other math operations
	i = 0;
	int iNumbers = -1;
	while (signs[++i] != 0)
	{
		switch (signs[i]) {
		case '*':
			continue;

		case '/':
			continue;
		}

		if (numbers[i] == -1) {
			if (iNumbers == -1) {
				iNumbers = i + 1;
			}

			while (numbers[iNumbers] == -1)
				iNumbers++;
		}

		switch (signs[i]) {
		case '+':
			if (iNumbers != -1) {
				numbers[iNumbers] += numbers[i - 1];
				iNumbers = -1;
			}
			else {
				numbers[i] += numbers[i - 1];
			}

			numbers[i - 1] = -1;
			continue;

		case '-':
			if (iNumbers != -1) {
				numbers[iNumbers] = numbers[i - 1] - numbers[iNumbers];
				iNumbers = -1;
			}
			else {
				numbers[i] = numbers[i - 1] - numbers[i];
			}

			numbers[i - 1] = -1;
			continue;
		}
	}


	return numbers[i - 1];
}

int hhCalcOld(const char* str)
{
	char c;

	int a = 0;
	int b = NULL;
	char op = NULL;

	bool changeNumber = false;
	bool isSignOp = false;

	// hexadecimal to decimal and get sign operation
	while (0 != (c = *str++))
	{
		if (!isdigit(c))
		{
			if (isSignOp) {
				return -1;
			}

			if (c == '+' || c == '-' || c == '*' || c == '/') {
				if (b != NULL)
				{
					switch (op) {
					case '+':
						a += b;
						break;
					case '-':
						a -= b;
						break;
					case '*':
						a *= b;
						break;
					case '/':
						a /= b;
						break;
					}
					b = NULL;
				}
				op = c;

				changeNumber = true;
				isSignOp = true;
				continue;
			}
			else {
				isSignOp = true;
				continue;
			}
		}

		if (!changeNumber) {
			a = a * 10 + (c - '0');
			isSignOp = false;
		}
		else {
			b = b * 10 + (c - '0');
			isSignOp = false;
		}
	}

	switch (op) {
	case '+':
		a += b;
		break;
	case '-':
		a -= b;
		break;
	case '*':
		a *= b;
		break;
	case '/':
		a /= b;
		break;
	}

	return a;
}

int hhAdd(int a, int b)
{
	return a + b;
}

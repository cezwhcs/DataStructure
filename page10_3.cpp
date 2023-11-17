#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void PrintDigit(size_t n)
{
	cout << n;
	return;
}

void
PrintOut(unsigned int N) /* Print nonnegative N */
{
	if (N >= 10)
		PrintOut(N / 10);
	PrintDigit(N % 10);
}

double RoundUp(double N, int DecPlaces)
{
	int i;
	double AmountToAdd = 0.5;
	for (i = 0; i < DecPlaces; i++)
		AmountToAdd /= 10;
	return N + AmountToAdd;
}
void PrintFractionPart(double FractionPart, int DecPlaces)
{
	int i, Adigit;
	for (i = 0; i < DecPlaces; i++)
	{
		FractionPart *= 10;
		Adigit = IntPart(FractionPart);
		PrintDigit(Adigit);
		FractionPart = DecPart(FractionPart);
	}
}
void PrintReal(double N, int DecPlaces)
{
	int IntegerPart;
	double FractionPart;
	if (N < 0)
	{
		putchar(' - ');
		N = -N;
	}
	N = RoundUp(N, DecPlaces);
	IntegerPart = IntPart(N); FractionPart = DecPart(N);
	PrintOut(IntegerPart); /* Using routine in text */
	if (DecPlaces > 0)
		putchar('. ');
	PrintFractionPart(FractionPart, DecPlaces);
}
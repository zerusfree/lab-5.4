// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int N)
{
	double s = 0;
	for (int k = N; k <= 19; k++)
		s += sqrt(pow(sin(1. * k), 2) + pow(cos(1. * N / k), 2));
	return s;
}
double S1(const int k ,const int N)
{
	if (k > 19)
		return 0;
	else
		return  sqrt(pow(sin(1. * k), 2) + pow(cos(1. * N / k), 2)) + S1(k+1, N);
}
double S2(const int k, const int N)
{
	if (k < N)
		return 0;
	else
		return  sqrt(pow(sin(1. * k), 2) + pow(cos(1. * N / k), 2)) + S2(k-1, N);
}
double S3(const int k, const int N, double t)
{
	t = t + sqrt(pow(sin(1. * k), 2) + pow(cos(1. * N / k), 2)) ;
	if (k >= 19)
		return t;
	else
		return S3(k+1, N, t);
}
double S4(const int k, const int N, double t)
{
	t = t + sqrt(pow(sin(1. * k), 2) + pow(cos(1. * N / k), 2)) ;
	if (k <= N)
		return t;
	else
		return S4(k-1, N, t);
}
int main()
{
	int N;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(N) << endl;
	cout << "(rec up ++) S1 = " << S1(N,N) << endl;
	cout << "(rec up --) S2 = " << S2(19, N) << endl;
	cout << "(rec down ++) S3 = " << S3(N, N, 0) << endl;
	cout << "(rec down --) S4 = " << S4(19, N, 0) << endl;
	return 0;
}

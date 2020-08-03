/*
Fixed point iteration_not_optimisd.cpp
@author - Yawar Badri (c) copyright 2019
@version - 0.6/2019
@Title - FIXED POINT ITERATION SOLVER


*/
#include "pch.h"
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
int main()
{
	

	cout << "\tSolution by fixed point iteration\n\n";
	
	while (1)
	{
		clock_t tic;

		//Set tolerance value here-------------------
		const double tol_e = 0.00001;
		//this operation limits the precision of the 'tol_e'
		//to avoid random approximation errors
		double tol = floor(tol_e * 1e8) / 1e8; 
		//-------------------------------------------

		double x1, x2;
		x1 = x2 = 0;
		int iter = 0;
		int choice = 0;

		cout << "\n\tEvaluate which function\n 0 -> x = sin(x)\n"
			"1 -> x = log10(x)\n"
			"2 -> x = sinh(x)\n"
			"3 -> x = cosh(x)\n";
		cin >> choice;
		//basic error handling
		if (!(choice >= 0 && choice <= 4))
		{
			cout << "\nchoice out of range - terminating program\n";
			exit(0);
		}

		cout << "tolerance = " << tol << "\nenter the initial guess -> ";
		cin >> x2;

		// main program
		tic = clock();					//obtain the execution time
		while (!(abs(x2 - x1) < tol))
		{
			//new value = old value
			x1 = x2;
			//write the function here in terms of x implicitly
			//functions are selected based on 'choice'
			//! Remember that the below are **equations** of form **x = f(x)**
                        //
                        switch (choice)
			{
			case 0:
				x2 = sin(x1);		//	0
				break;
			case 1:
				x2 = log10(x1);		//	1
				break;
			case 2:
				x2 = sinh(x1);		//	2
				break;
			case 3:
				x2 = cosh(x1);		//	3
				break;
			case 4:
				//x2 = ((x1*x1) + 10) / 11;
				x2 = 2 * sin(x1);

				break;
			default:
				break;
			}

			//		x2 = 0.5*(log10(x1) + 7);
			// basic error handling
			if (x1 == INFINITY || isnan(x1))
			{
				cout << "\n\n! - The selected function choice (" << choice << ") seems to diverge "
					"or has no solution or a single trivial solution."
					"\n try a different guess value\n";
				break;
			}
			cout << "\ncurrent value of x1 = " << x1 << "\n";
			iter++;
		}
		tic = clock() - tic;			//obtain net run time for main loop
		cout << "the number of iterations is " << iter << "\n";
		cout << "\n excution time - " << (float(tic) / CLOCKS_PER_SEC) << "seconds \n";

	}
}

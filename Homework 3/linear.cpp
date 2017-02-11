//
//  linear.cpp
//  Homework 3-xcode
//
//  Created by Steven Shi on 2/10/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//
#include<iostream>
bool somePredicate(double x)
{
	return x < 0;
}
// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const double a[], int n)
{
	if (n == 0)
		return true;
	if (n == 1)
		return somePredicate(a[n-1]);
	if (somePredicate(a[n-1]) && allTrue(a,n-1))
		return true;
	else
		return false; 
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const double a[], int n)
{
	int count = 0;
	if (n == 0)
		return 0;
	if (somePredicate(a[n-1]))
		count = 1;
	return count + countFalse(a, n-1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const double a[], int n)
{
	if (n <= 0)
		return -1;
	if (firstFalse(a, n - 1) != -1)
		return firstFalse(a, n - 1);
	else if (somePredicate(a[n - 1]))
		return n - 1;
	else
		return -1; 


	
}

// Return the subscript of the smallest double in the array (i.e.,
// the one whose value is <= the value of all elements).  If more
// than one element has the same smallest value, return the smallest
// subscript of such an element.  If the array has no elements to
// examine, return -1.
int indexOfMin(const double a[], int n)
{
	if (n <= 0)
		return -1;
	if (n == 1)
		return 0;
	if (n == 2)
	{
		if (a[n - 2] > a[n - 1])
			return n - 1;
		else
			return n - 2;
	}
	else if (a[indexOfMin(a, n - 1)] < a[n - 1])
	{
		return indexOfMin(a, n - 1);
	}
	else
		return n - 1;
	
	
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2)
{
    
}


int main()
{
	double a[] = { -2, -33, -4, -5, -66 };
	double b[] = { 2, 33, 4, 5, 66 };
	double c[] = { 2, 33, 4, 5, -66 };
	double d[] = { 2, 33, 4, -5, 66 };
	double e[] = { 2, 33, -4, 5, 66 };
	double f[] = { 2, -33, 4, 5, 66 };
	double g[] = { -2, 33, 4, 5, 66 };
	double h[] = { -2, -33, 4, 5, 66 };
	double i[] = { 2, -33, -4, 5, 66 };
	double j[] = { 2, 33, -4, -5, 66 };
	double k[] = { 2, 33, 4, -5, -66 };
	double l[] = { 2, 33, -4, -5, -66 };
	double m[] = { -2, -33, -4, 5, 66 };
	double n[] = { 2, -33, -4, -5, 66 };
	
	double* ptr = e;
		if (allTrue(ptr, 5))
			std::cout << "true " << std::endl;
		else
			std::cout << "false " << std::endl;
	std::cout << countFalse(ptr, 5) << std::endl;
	std::cout << firstFalse(ptr, 5) << std::endl;
	std::cout << indexOfMin(ptr, 5) << std::endl;

}
	
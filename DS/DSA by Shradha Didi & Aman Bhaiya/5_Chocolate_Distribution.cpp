//https://www.geeksforgeeks.org/chocolate-distribution-problem/
The Chocolate Distribution Problem is a problem where you are given an array of integers
representing the number of chocolates in each packet. You also have a given number of students.
Your task is to distribute the packets of chocolates among the students in such a way
that each student receives exactly one packet, and the difference between the number of chocolates in the packet with the maximum number of chocolates and the packet with the minimum number of chocolates is minimized.

To solve this problem, you need to come up with a distribution strategy that minimizes the difference between the maximum and minimum number of chocolates given to the students. The goal is to achieve a balanced distribution of chocolates among the students.

For example, consider the following scenario:

Array of chocolate packets: [7, 3, 2, 4, 9, 12]
Number of students: 3
To distribute the chocolates, you need to find a way to allocate the packets in a manner that minimizes the difference between the maximum and minimum number of chocolates given to the students.

One possible solution for the given example could be:

Student 1: 2 chocolates
Student 2: 3 chocolates
Student 3: 4 chocolates
In this solution, the packet with the maximum number of chocolates has 4 chocolates, and the packet with the minimum number of chocolates has 2 chocolates. The difference between them is 2, which is the minimum possible difference.

The main challenge in this problem is to come up with an efficient algorithm to distribute the chocolates in a way that minimizes the difference. This can be achieved through various approaches, including sorting the array and then distributing the chocolates or using other data structures and algorithms.

I hope this clarifies the problem statement for you. If you have any further questions, please let me know.

Naive Approach for Chocolate Distribution Problem
The idea is to generate all subsets of size m of arr[0..n-1]. For every subset, find the difference between the maximum and minimum elements in it. Finally, return the minimum difference.

Efficient Approach for Chocolate Distribution Problem
The idea is based on the observation that to minimize the difference, we must choose consecutive elements from a sorted packet. We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between the last and first elements.
// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
	// if there are no chocolates or number
	// of students is 0
	if (m == 0 || n == 0)
		return 0;

	// Sort the given packets
	sort(arr, arr + n);

	// Number of students cannot be more than
	// number of packets
	if (n < m)
		return -1;

	// Largest number of chocolates
	int min_diff = INT_MAX;

	// Find the subarray of size m such that
	// difference between last (maximum in case
	// of sorted) and first (minimum in case of
	// sorted) elements of subarray is minimum.

	for (int i = 0; i + m - 1 < n; i++) {
		int diff = arr[i + m - 1] - arr[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

int main()
{
	int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30,
				40, 28, 42, 30, 44, 48, 43, 50 };
	int m = 7; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum difference is "
		<< findMinDiff(arr, n, m);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

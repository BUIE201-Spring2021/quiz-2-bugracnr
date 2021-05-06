#include<iostream>
#include<vector>
#include<map>
#include<numeric>
using namespace std;

// Write a function that checks if two integers in a given array add up to 
// a given target
// If check = {1, -2, 4, 7, -3, 5} and target = 3, the function should return true since -2 + 5 = 3. 
// If check = {1, -2, 4, 7, -3, 5} and target = 13, the function should return false since no pair of elements add to 13. 

// a)	Implement the function so that you iterate through each pair of integers without using any additional data structures

bool CheckSum(vector<int>& check, int target)
{
	// CODE REQUIRED
	int size = check.size();
	for( int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
			if(check[i]+check[j]==target)
			{
				cout << check[i] << " + " << check[j] << " = " << target << endl;
				return true;
			}

	return false;
}

// b)	Implement the function so that you make a single pass through the vector (i.e. each element is considered only once). You may create additional data structures such as map. 

bool CheckSumQuick(vector<int>& check, int target)
{
	// CODE REQUIRED
	map<int,int> checkmap;

	for(auto it:check)
	{
		if(checkmap.count(it)>0)
		{
			cout << it << " + " << checkmap[it] << " = " << target << endl;
			return true;
		}
		else
			checkmap[target-it] = it;
	}

	return false;

}


int main()
{
	vector<int> check = {1, -2, 4, 7, -3, 5};
	int target = 3;

	cout << "CheckSum: " << CheckSum(check,target) << endl; 

	target = 13;

	cout << "CheckSum: " << CheckSum(check,target) << endl; 

	target = 3;
	cout << "CheckSumQuick: " << CheckSumQuick(check,target) << endl; 

	target = 13;
	cout << "CheckSumQuick: " << CheckSumQuick(check,target) << endl; 


	vector<int> large(100000);
  iota(large.begin(),large.end(),0);

  clock_t b,e;
  bool res=false;
 
  b=clock();
  res = CheckSum(large, 99999999);
  e=clock();
  cout << "CheckSum: " << res << " Time: " << double(e-b)/CLOCKS_PER_SEC << endl;

	b=clock();
  res = CheckSumQuick(large, 99999999);
  e=clock();
  cout << "CheckSumQuick: " << res << " Time: " << double(e-b)/CLOCKS_PER_SEC << endl;


	return 0;
}
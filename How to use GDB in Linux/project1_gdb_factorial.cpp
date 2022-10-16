# include <iostream>
using namespace std;

int factorial(int);

int main()
{
	int num, fact;
	cout << "Enter the number: ";
	cin >> num;

	fact = factorial(num);

	cout << "The factorial of " << num << " is " << fact << "\n";
  
 	return 0;
}

int factorial(int n) {
int i, j;
	
	for (i=1; i<n; i++)
		j=j*i;    

	return j;
}
	



# include <iostream>
using namespace std;
int main()
{
	int i, num, j;
	cout << "Enter the number: ";
	cin >> num;

	for (i=1; i<num; i++)
		j=j*i;    

	cout << "The factorial of " << num << " is " << j << "\n";
  
 	return 0;
}

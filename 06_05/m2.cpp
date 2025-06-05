#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	int i = 0;
	while (i < 10)
	{
		cout << "HELLO WOLRD " << i << endl;
		i++;
	}

	for (i = 3; i % 13 != 0; i++)
	{
		cout << "STILL NOT %13: i = " << i << endl;
	}


	return 0;
}

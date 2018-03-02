#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PriorityQueue<int> q;

	//Testar isEmpty och undantag
	if (q.isEmpty())
		cout << "Queue is Empty!" << endl;
	try
	{
		cout << q.front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	getchar();
	return 0;
}
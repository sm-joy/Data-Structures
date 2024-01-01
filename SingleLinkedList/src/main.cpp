#include "SLL.h"

int main()
{
	SLL<int> list;
	list.push_back(1);
	list.push_front(2);
	list.push_back(4);
	list.print();
	return 0;
}
#include "Id.h"

std::string otherFunc(std::string& nowId)
{
	Id id(nowId);
	id.sameCheck();
	id.SetPairs();
	id.PairToInt();
	id.Add();
	id.IntToPair();

	return id.GetNextId();
}

int main()
{
	std::string nowId;
	std::cout << "Enter id: ";
	std::cin >> nowId;

	nowId = otherFunc(nowId);
	std::cout << "Now id is: " << nowId << std::endl;
}
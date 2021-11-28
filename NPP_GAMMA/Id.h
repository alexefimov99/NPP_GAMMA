#pragma once

#include <iostream>
#include <vector>
#include <string>

class Id
{
private:
	std::string sId;
	int pairSize;
	std::string *pairs;
	std::vector<std::pair<int, int> >numOfSymb;
	bool same;
	std::string taboo = "DFGJMQV0";

public:
	Id(std::string&);
	~Id();

	void sameCheck();
	void SetPairs();
	void PairToInt();
	void Add();
	void IntToPair();

	std::string GetNextId();

};


#include "Id.h"

Id::Id(std::string& sId) : sId(sId)
{ }

Id::~Id()
{
	numOfSymb.clear();
	delete[] pairs;
}

void Id::sameCheck()
{
	same = true;
	int pos = 3;

	if (sId.size() > 2)
	{
		for (int i = 0; i < sId.size() / pos + 1; i++)
		{
			if (sId[i * pos] < 'Z' || sId[i * pos + 1] < '9')
			{
				same = false;
				break;
			}
		}
	}
	else if (sId.size() == 2 && (sId[0] < 'Z' || sId[1] < '9'))
		same = false;

	for (int i = 0; i < taboo.size(); i++)
	{
		if (sId.find(taboo[i]) != std::string::npos)
		{
			std::cout << "ID has undefined symbol." << std::endl;
			system("pause");
			exit(0);
		}
	}
}

void Id::SetPairs()
{
	pairSize = sId.size() / 3 + 1;
	pairs = new std::string[pairSize]{};

	for (int i = 0, j = 0; i < sId.size(); i++)
	{
		if (i % 3 == 2)
		{
			j++;
			continue;
		}

		pairs[j] += sId.at(i);
	}
}

void Id::PairToInt()
{
	for (int i = 0; i < pairSize; i++)
		numOfSymb.push_back(std::make_pair(static_cast<int>(pairs[i][0] - 'A'), static_cast<int>(pairs[i][1] - '0')));
}

void Id::Add()
{
	for (int i = pairSize - 1; i >= 0; i--)
	{
		if (numOfSymb[i].second < 9)
		{
			numOfSymb[i].second++;

			if (numOfSymb[i].first >= 'Z')
				numOfSymb[i].first = 0;

			break;
		}
		else if (numOfSymb[i].second == 9)
		{
			numOfSymb[i].second = 1;

			if (numOfSymb[i].first < 'Z' - 'A')
			{
				while (taboo.find(numOfSymb[i].first + 'A' + 1) != std::string::npos)
					numOfSymb[i].first++;
				numOfSymb[i].first++;
				break;
			}
			else
				numOfSymb[i].first = 0;
		}
	}
}

void Id::IntToPair()
{
	sId = "";
	for (int i = 0; i < pairSize; i++)
	{
		sId += char(numOfSymb[i].first + 'A');
		sId += char(numOfSymb[i].second + '0');
		if (i != pairSize - 1)
			sId += '-';
	}
}

std::string Id::GetNextId()
{
	if (same == true)
	{
		sId += "-A1";
		if (sId.size() > 29)
		{
			std::cout << "Invalid value! The size of value is exceeded." << std::endl;
			system("pause");
			exit(0);
		}
	}

	return sId;
}
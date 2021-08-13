#include "LabelMaker.h"
#include <iostream>

using namespace std;

namespace sdds
{
	LabelMaker::LabelMaker(int noOfLabels)
	{
		this->labelList = nullptr;
		this->nLabels = noOfLabels;
		this->labelList = new Label[noOfLabels];
	}
	
	void LabelMaker::readLabels()
	{
		int i = 0;
		cout << "Enter " << this->nLabels << " labels:" << endl;
		while (i < this->nLabels) // check if it works
		{
			cout << "Enter label number " << (i + 1) << endl;
			labelList[i].readLabel();
			i++;
		}

	}
	
	void LabelMaker::printLabels()
	{
		int i = 0;
		while (i < this->nLabels)
		{
			labelList[i].printLabel()<< endl;
			i++;
		}
		
	}

	LabelMaker::~LabelMaker()
	{
		if (this->labelList != nullptr)
		{
			delete[] this->labelList;
			this->labelList = nullptr;
		}
	}
}

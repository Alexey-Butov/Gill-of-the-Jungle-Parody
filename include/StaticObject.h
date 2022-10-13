#pragma once

#include "Object.h"
#include <vector>

class StaticObject : public Object
{

public:

	//----Constructor for StaticObject base------
	StaticObject(); // constructor
	~StaticObject()= default; // destructor
	virtual void changPic() = 0;
};
#pragma once

#include "StaticObject.h"


class Gate : public StaticObject
{

public:

	//----Constructor for Gate base------
	Gate();
	void changPic() override {};
	~Gate() = default;

private:

};
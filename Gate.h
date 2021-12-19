#pragma once

#include "StaticObject.h"


class Gate : public StaticObject
{

public:

	//----Constructor for Gate base------
	Gate();
	void changPic() override {}; // changes gate picture when enough keys were eaten
	~Gate() = default;

private:

};
#pragma once
class masina
{
protected:
	char* color;
	char* name;
public:
	virtual char* GetColor()=0;
	virtual char* GetName()=0;
};


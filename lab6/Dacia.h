#pragma once
#include "masina.h"
class Dacia :
    public masina
{
    Dacia(char* culoare);
    ~Dacia();
    char* GetColor();
    char* GetName();
};


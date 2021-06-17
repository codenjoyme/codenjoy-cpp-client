#ifndef CHARELEMENT_H
#define CHARELEMENT_H

#include "utils.h"

class CharElement {
public:
	virtual Char ch() = 0;
	virtual String name() = 0;
};

#endif
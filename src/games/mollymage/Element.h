#ifndef ELEMENT_H
#define ELEMENT_H

#include "engine/utils.h"
#include "engine/CharElement.h"


class Element : public CharElement {
public:
    Element(Char el);
    Element(String name);

    bool operator==(const Element& el) const;

    Char ch();
    String name();

    Char getChar() const;
    String valueOf(Char ch) const;

private:
    static ElementMap initialiseElements();
    static const ElementMap Elements;

    ElementItem elem;
};

#endif

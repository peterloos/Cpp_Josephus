#include <iostream>
using namespace std;
#include "Soldier.h"

Soldier::Soldier(int number) : m_number(number), m_next ((Soldier*) 0)
{
}

ostream& operator<< (ostream& os, const Soldier& s)
{
    os << s.m_number;
    return os;
}

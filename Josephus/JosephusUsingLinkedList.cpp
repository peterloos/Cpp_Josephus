#include <iostream>
using namespace std;
#include "Soldier.h"
#include "Josephus.h"

namespace SolutionUsingLinkedList
{
    // c'tor(s), d'tor
    Josephus::Josephus()
        : m_count(41), m_alive(41), m_lastEliminated(0)
    {
        m_passby = Josephus::DefaultPassBy;
        CreateLinkedList();
    }

    Josephus::Josephus(int count)
        : m_count(count), m_alive(count), m_lastEliminated(0)
    {
        m_passby = Josephus::DefaultPassBy;
        CreateLinkedList();
    }

    Josephus::~Josephus()
    {
        Soldier* soldier = m_root;
    
        // delete each single element
        do 
        {
            // store current node pointer
            Soldier* current = soldier;
    
            // advance to next node
            soldier = soldier -> m_next;
    
            // delete 'current' node pointer
            delete current;
        }
        while (soldier != m_root);
    }

    // public interface
    bool Josephus::EliminateNextSoldier()
    {
        // more than one soldier?
        if (m_alive == 1)
            return false;
        
        // locate next soldier
        for (int i = 0; i < m_passby - 1; i ++)
            m_current = m_current -> m_next;

        // remove soldier from list
        Soldier* node = m_current -> m_next;
        m_current -> m_next = node -> m_next;

        // take care, if root object is removed
        if (m_root == node)
            m_root = m_root -> m_next;

        m_lastEliminated = node -> m_number;
        delete node;
        m_alive --;

        return true;
    }

    void Josephus::EliminateAll()
    {
        while (EliminateNextSoldier())
            ;
    }

    // private helper methods
    void Josephus::CreateLinkedList()
    {
        // create first soldier
        m_root = new Soldier(1);
        m_current = m_root;

        for (int i = 1; i < m_count; i ++)
        {
            Soldier* s = new Soldier(i + 1);

            // link previous Soldier with current one
            m_current -> m_next = s;
            m_current = s;
        }

        // link last soldier with first one
        m_current -> m_next = m_root;
    }

    // output
    ostream& operator<< (ostream& os, const Josephus& j)
    {
        os << '[';
        Soldier* tmp = j.m_root;
        do
        {
            os << *tmp;
            if (tmp -> m_next != j.m_root)
                os << ',';
            tmp = tmp -> m_next;
        }
        while (tmp != j.m_root);
        os << ']';
        return os;
    }
}

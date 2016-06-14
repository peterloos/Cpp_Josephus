#include <iostream>
using namespace std;
#include "Soldier.h"
#include "Josephus.h"

namespace SolutionUsingArray
{
    // c'tor(s), d'tor
    Josephus::Josephus() : m_count(41), m_alive(41), m_lastEliminated(0)
    {
        Init();
    }

    Josephus::Josephus(int count) : m_count(count), m_alive(count), m_lastEliminated(0)
    {
        Init();
    }

    void Josephus::Init()
    {
        m_soldiers = new bool[m_count];
        for (int i = 0; i < m_count; i ++)
            m_soldiers[i] = true;

        m_passby = Josephus::DefaultPassBy;
        m_lastAlive = 0;
        m_current = 0;
    }

    Josephus::~Josephus()
    {
        delete[] m_soldiers;
    }

    // public interface
    bool Josephus::EliminateNextSoldier()
    {
        // more than one soldier?
        if (m_alive == 1)
            return false;

        for (int i = 0; i < m_passby - 1; i ++)
        {
            MoveToNextAliveSoldier();
            NextIndex();  // skip found alive soldier
        }

        MoveToNextAliveSoldier();

        // kill 'n'.th soldier
        m_soldiers[m_current] = false;
        m_alive --;
        m_lastEliminated = m_current + 1;

        return true;
    }

    void Josephus::EliminateAll()
    {
        while (EliminateNextSoldier())
            ;
    }

    int Josephus::LastAlive ()
    {
        if (m_lastAlive == 0)
        {
            MoveToNextAliveSoldier();
            m_lastAlive = m_current + 1;
        }

        return m_lastAlive;
    }

    // private helper methods
    void Josephus::MoveToNextAliveSoldier()
    {
        while (m_soldiers[m_current] == false)
            NextIndex(); // move index to next entry
    }

    void Josephus::NextIndex()
    {
        // move index to next entry
        m_current ++;
        if (m_current >= m_count)
            m_current = 0;
    }

    // output
    ostream& operator<< (ostream& os, Josephus& j)
    {
        os << '[';
        int save = j.m_current;  // save current state of position index
        j.m_current = 0;

        int count = 0;
        do
        {
            j.MoveToNextAliveSoldier();
            os << (j.m_current + 1);

            count ++;
            if (count < j.Alive())
                os << ',';
            j.NextIndex();
        }
        while (count < j.Alive());

        os << ']';
        j.m_current = save;  // restore current state of position index
        return os;
    }
}

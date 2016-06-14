#include <iostream>
using namespace std;

#include "Soldier.h"
#include "Josephus.h"

// using namespace SolutionUsingLinkedList;
using namespace SolutionUsingArray;

void Test01();
void Test02();
void Test03();
void Test04();
void Test05();
void Test06();

void main()
{
    Test01();
    Test02();
    Test03();
    Test04();
    Test05();
    Test06();

	getchar();
}

void Test01()
{
    Josephus j (41);
    j.SetPassBy (3);
    cout << j << endl;

    j.EliminateNextSoldier();
    cout << j << endl;

    j.EliminateNextSoldier();
    cout << j << endl;
}

void Test02()
{
    Josephus j(17);
    j.SetPassBy(3);

    cout << "Number of soldiers: " << j.Count() << endl;
    cout << "Eliminating: Each " << j.PassBy() << ". soldier";
    cout << endl << endl;

    while (j.Alive() > 1)
    {
        j.EliminateNextSoldier();
        cout << "Removed ";
        cout.width(2);
        cout << j.LastEliminated() << "  " << j  << endl;
    }

    cout << endl;
    cout << "Last soldier: " << j.LastAlive() << endl;
    cout << "Last eliminated: " << j.LastEliminated() << endl;
}

void Test03()
{
    Josephus j(41);
    j.SetPassBy(3);

    cout << "Number of soldiers: " << j.Count() << endl;
    cout << "Eliminating: Each " << j.PassBy() << ". soldier" << endl << endl;

    while (j.Alive() > 1)
    {
        j.EliminateNextSoldier();
        cout << "Removed ";
        cout.width(2);
        cout << j.LastEliminated() << endl;
    }

    cout << endl;
    cout << "Last soldier: " << j.LastAlive() << endl;
}

void Test04()
{
    Josephus j(41);
    j.SetPassBy(10);

    cout << "Number of soldiers: " << j.Count() << endl;
    cout << "Eliminating: Each " << j.PassBy() << ". soldier" << endl << endl;

    while (j.Alive() > 1)
    {
        j.EliminateNextSoldier();
        cout << "Removed "  << j.LastEliminated() << endl;
    }

    cout << endl;
    cout << "Last soldier: " << j.LastAlive() << endl;
    cout << "Last eliminated: " << j.LastEliminated() << endl;
}

void Test05()
{
    Josephus j(41);
    j.SetPassBy(3);

    cout << "Number of soldiers: " << j.Count() << endl;
    cout << "Eliminating: Each " << j.PassBy() << ". soldier" << endl;

    cout << "Soldiers: " << j << endl;
    while (j.Alive() > 1)
    {
        j.EliminateNextSoldier();
        cout << "Soldiers: " << j << endl;
    }

    cout << endl;
    cout << "Last soldier: " << j.LastAlive() << endl;
    cout << "Last eliminated: " << j.LastEliminated() << endl;
    cout << endl << endl << endl;
}

void Test06()
{
    Josephus j(41);
    j.SetPassBy(10);

    cout << "Number of soldiers: " << j.Count() << endl;
    cout << "Eliminating: Each " << j.PassBy() << ". soldier" << endl;
    j.EliminateAll();
    cout << "Last soldier: " << j.LastAlive() << endl;
    cout << "Last eliminated: " << j.LastEliminated() << endl;
}


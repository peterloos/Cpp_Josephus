class Soldier
{
friend ostream& operator<< (ostream&, const Soldier&);

public:
    // c'tor
    Soldier (int number);

    // member data
    int      m_number;
    Soldier* m_next;
};
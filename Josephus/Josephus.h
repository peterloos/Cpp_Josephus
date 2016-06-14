namespace SolutionUsingArray
{
    class Josephus
    {
    public:
        static const int DefaultPassBy = 10;  // default "decimatio"

    private:
        bool* m_soldiers;       // array of boolean states: alive or not
        int m_current;          // current index into array
    
        int m_count;            // total number of soldiers
        int m_alive;            // number of alive soldiers
        int m_lastEliminated;   // last eliminated soldier
        int m_lastAlive;        // number of surviving soldier
        int m_passby;           // "decimatio"

    public:
        // c'tor(s), d'tor
        Josephus ();
        Josephus (int);
        ~Josephus ();
    
        // getter/setter
        int Count () const { return m_count; }
        int Alive () const { return m_alive; }
        int LastEliminated () { return m_lastEliminated; }
        int LastAlive ();
        int PassBy () { return m_passby; }
        void SetPassBy (int passby) { m_passby = passby; }

        // public interface
        bool EliminateNextSoldier();
        void EliminateAll();

    private:
        // private helper methods
        void MoveToNextAliveSoldier();
        void NextIndex();
        void Init();

        // output
        friend ostream& operator<< (ostream&, Josephus&);
    };
}

namespace SolutionUsingLinkedList
{
    class Josephus
    {
    private:
        static const int DefaultPassBy = 10;  // default "decimatio"

    private:
        // root of soldiers
        Soldier*  m_root;      // root of linked list of soldiers
        Soldier*  m_current;   // current soldier

        int m_count;           // total number of soldiers
        int m_alive;           // number of alive soldiers
        int m_lastEliminated;  // last eliminated soldier
        int m_passby;          // "decimatio"

    public:
        // c'tor(s), d'tor
        Josephus ();
        Josephus (int);
        ~Josephus ();

        // getter/setter
        int Count () const { return m_count; }
        int Alive () const { return m_alive; }
        int LastEliminated () { return m_lastEliminated; }
        int LastAlive () { return m_current -> m_number; }
        int PassBy () { return m_passby; }
        void SetPassBy (int passby) { m_passby = passby; }

        // public interface
        bool EliminateNextSoldier();
        void EliminateAll();

    private:
        // private helper methods
        void CreateLinkedList();

        // operators
        friend ostream& operator<< (ostream&, const Josephus&);
    };
}






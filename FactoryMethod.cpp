#include <iostream>
#include <vector>
using namespace std;

namespace FactoryMethod 
{


    class Unit
    {
    public:
        Unit() {}
        virtual ~Unit() {}

    public:
        virtual void Move() = 0;
    };

    class WarriorUnit : public Unit
    {
    public:
        WarriorUnit() { printf("Create : Unit_Warrior\t"); }
        ~WarriorUnit() {}

    public:
        void Move() override
        {
            printf("WarriorMove\n");
        }
    };
    class MagicianUnit : public Unit
    {
    public:
        MagicianUnit() { printf("Create : Unit_Magician\t"); }
        ~MagicianUnit() {}

    public:
        void Move() override
        {
            printf("MagicianMove\n");
        }
    };
    class ArcherUnit : public Unit
    {
    public:
        ArcherUnit() { printf("Create : Unit_Archer\t"); }
        ~ArcherUnit() {}

    public:
        void Move() override
        {
            printf("ArcherMove\n");
        }
    };

  /*  enum class UNITTYPE
    {
        WARRIOR,
        MAGICIAN,
        ARCHER
    };*/

    class UnitGenerator
    {
    public:
        UnitGenerator() {}
        virtual ~UnitGenerator() {}

    public:
        vector<Unit*> units;

    public:
        virtual vector<Unit*> CreateUnits() = 0;
    };
    class A_UnitGenerator : public UnitGenerator
    {
    public:
        A_UnitGenerator() {}
        ~A_UnitGenerator() {}

    public:
        vector<Unit*> CreateUnits() override
        {
            for (int i = 0; i < 3; i++)
            {
                Unit* warrior = new WarriorUnit();
                units.push_back(warrior);

                Unit* magician = new MagicianUnit();
                units.push_back(magician);
            }

            return units;
        }
    };


    class B_UnitGenerator : public UnitGenerator
    {
    public:
        B_UnitGenerator() {}
        ~B_UnitGenerator() {}

    public:
        vector<Unit*> CreateUnits() override
        {
            for (int i = 0; i < 3; i++)
            {
                Unit* warrior = new WarriorUnit();
                units.push_back(warrior);

                Unit* magician = new MagicianUnit();
                units.push_back(magician);
            }
            for (int i = 0; i < 5; i++)
            {
                Unit* archer = new ArcherUnit();
                units.push_back(archer);
            }

            return units;
        }
    };
    class UnitFactory
    {
    public:
        UnitFactory()
        {
            generators[0] = new A_UnitGenerator();
            generators[1] = new B_UnitGenerator();

        }
        ~UnitFactory() {}

    public:
        UnitGenerator* generators[2];

    public:
        void CreateUnit(int num)
        {
            if (num < 2)
            {
                generators[num]->CreateUnits();
                printf("\n Complete CreateUnits\n");
            }
        }
        void Move()
        {
            _Move(0);
            _Move(1);
        }
    private:
        void _Move(int num)
        {
            for (int i = 0; i < generators[num]->units.size(); i++)
            {
                generators[num]->units[i]->Move();
            }
        }

    };
}

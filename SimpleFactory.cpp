#include <iostream>

using namespace std;

namespace SimpleFactory
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
        WarriorUnit() {}
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
        MagicianUnit() {}
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
        ArcherUnit() {}
        ~ArcherUnit() {}

    public:
        void Move() override
        {
            printf("ArcherMove\n");
        }
    };

    enum class UNITTYPE
    {
        WARRIOR,
        MAGICIAN,
        ARCHER,
        MAX
    };

    class UnitFactory
    {
    public:
        UnitFactory() {}
        ~UnitFactory() {}
    public:
        Unit* CreateUnit(UNITTYPE type)
        {
            Unit* unit = nullptr;
            switch (type)
            {
            case UNITTYPE::WARRIOR:
                unit = new WarriorUnit();
                printf("Create : Unit_Warrior\t");
                break;

            case UNITTYPE::MAGICIAN:
                unit = new MagicianUnit();
                printf("Create : Unit_Magician\t");
                break;

            case UNITTYPE::ARCHER:
                unit = new ArcherUnit();
                printf("Create : Unit_Archer\t");
                break;
            default:
                printf("Can't Create Unit\t");
                break;
            }
            return unit;
        }
    };
}

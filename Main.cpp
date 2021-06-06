#pragma once
#include "SimpleFactory.cpp"
#include "FactoryMethod.cpp"

void SimpleFactoryExample()
{
    
    SimpleFactory::UnitFactory* factory = new SimpleFactory::UnitFactory();

    SimpleFactory::Unit* unit[static_cast<int>(SimpleFactory::UNITTYPE::MAX)];
    for (int i = 0; i < static_cast<int>(SimpleFactory::UNITTYPE::MAX); i++)
    {
        unit[i] = factory->CreateUnit(static_cast<SimpleFactory::UNITTYPE>(i));
        unit[i]->Move();
    }
}


void FactoryMethodExample()
{  
    FactoryMethod::UnitFactory* factory = new FactoryMethod::UnitFactory();
    factory->CreateUnit(0);
    factory->CreateUnit(1);
    factory->Move();
}
int main()
{
    //SimpleFactoryExample();
    FactoryMethodExample();
    

    return 0;
}
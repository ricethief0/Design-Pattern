#pragma once
#include "SimpleFactory.cpp"
#include "FactoryMethod.cpp"
#include "Builder.cpp"


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

void BuilerExample()
{
    BuilderPattern::Factory* factory = new BuilderPattern::Factory();
    BuilderPattern::CarBuilder* carBuilder = new BuilderPattern::CarBuilder();
    BuilderPattern::MoterCycle* moterCycle = new BuilderPattern::MoterCycle();

    factory->MakeVehicle(carBuilder);
    factory->MakeVehicle(moterCycle);
}
int main()
{
    //SimpleFactoryExample();
    //FactoryMethodExample();
    BuilerExample();
    

    return 0;
}
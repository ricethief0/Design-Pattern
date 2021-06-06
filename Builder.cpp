#include <iostream>
#include <vector>

using namespace std;

namespace BuilderPattern
{
	class VehicleBuilder
	{
	public:
		VehicleBuilder(){}
		virtual ~VehicleBuilder(){}
		
		virtual void BuilderFrame() = 0;
		virtual void BuilderEngine() = 0;
		virtual void BuilderWheels() = 0;
		virtual void Check() = 0;
	};
	enum VEHICLETYPE 
	{
		CAR,
		MOTERCYCLE
	};
	class Vehicle
	{
	public:
		Vehicle(VEHICLETYPE type):type(type){}
		~Vehicle(){}
	
	public:
		vector<string> parts;
	private:
		VEHICLETYPE type;

	public:
		void AddPart(string partName)
		{
			parts.push_back(partName);
		}

		VEHICLETYPE GetType() { return type; }

		void CurruntVehicleCheck()
		{
			cout << type << endl;
			for (string partName : parts)
			{
				if(partName != parts[parts.size()-1])
					cout << partName << ',';
				else
					cout << partName << endl;
			}
		}
	};
	class CarBuilder : public VehicleBuilder
	{
	public:
		CarBuilder()
		{
			vehicle = new Vehicle(VEHICLETYPE::CAR);
		}
		~CarBuilder(){}

	public:
		Vehicle* vehicle;
	
	public:
		void BuilderFrame()
		{
			vehicle->AddPart("Å×½½¶ó");
		}
		void BuilderEngine()
		{
			vehicle->AddPart("Àü±â¸ðÅÍ");
		}
		void BuilderWheels()
		{
			vehicle->AddPart("¿Þ¾Õ¹ÙÄû");
			vehicle->AddPart("¿ÞµÚ¹ÙÄû");
			vehicle->AddPart("¿À¾Õ¹ÙÄû");
			vehicle->AddPart("¿ÀµÚ¹ÙÄû");
		}
		void Check()
		{
			vehicle->CurruntVehicleCheck();
		}
	};
	class MoterCycle : public VehicleBuilder
	{
	public:
		MoterCycle()
		{
			vehicle = new Vehicle(VEHICLETYPE::MOTERCYCLE);
		}
		~MoterCycle() {}

	public:
		Vehicle* vehicle;

	public:
		
		void BuilderFrame()
		{
			vehicle->AddPart("È¥´Ù");
		}
		void BuilderEngine()
		{
			vehicle->AddPart("¿ÀÅä¹ÙÀÌ¿£Áø");
		}
		void BuilderWheels()
		{
			vehicle->AddPart("¾Õ¹ÙÄû");
			vehicle->AddPart("µÚ¹ÙÄû");
		}
		void Check()
		{
			vehicle->CurruntVehicleCheck();
		}
	};

	class Factory
	{
	public:
		Factory() {}
		~Factory() {}

		void MakeVehicle(VehicleBuilder* vehicle)
		{
			vehicle->BuilderFrame();
			vehicle->BuilderEngine();
			vehicle->BuilderWheels();
			vehicle->Check();
		}
	};
	
}
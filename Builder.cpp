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
			vehicle->AddPart("�׽���");
		}
		void BuilderEngine()
		{
			vehicle->AddPart("�������");
		}
		void BuilderWheels()
		{
			vehicle->AddPart("�޾չ���");
			vehicle->AddPart("�޵ڹ���");
			vehicle->AddPart("���չ���");
			vehicle->AddPart("���ڹ���");
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
			vehicle->AddPart("ȥ��");
		}
		void BuilderEngine()
		{
			vehicle->AddPart("������̿���");
		}
		void BuilderWheels()
		{
			vehicle->AddPart("�չ���");
			vehicle->AddPart("�ڹ���");
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
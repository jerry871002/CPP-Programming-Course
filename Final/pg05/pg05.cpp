#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee{
public:
	string name;
	string IDnumber;
	Employee(){}
	Employee(string n, string id) : name(n), IDnumber(id){}
	virtual double earnings() = 0;
	virtual void display() = 0;

};

class SalariedEmployee: public Employee{
public:
	double weeklySalary;
	// (1) define the constructor
	SalariedEmployee(){}
	SalariedEmployee(string n, string i, double w) : Employee(n, i), weeklySalary(w) {}

	// (2) define the earnings function
	double earnings() { return weeklySalary; }
	void display(){
		cout << "Salaried Employee: " << name << endl;
		cout << "ID number: " << IDnumber << endl;
		cout << "Earned: " << earnings() << endl;
	}

};

class HourlyEmployee: public Employee{
public:
	double wage;
	double hours;
	// (1) define the constructor
	HourlyEmployee(){}
	HourlyEmployee(string n, string i, double w, double h) : Employee(n, i), wage(w), hours(h) {}

	// (2) define the earnings function
	double earnings() {
		if(hours <= 40)
			return hours * wage;
		else
			return 40 * wage + (hours - 40) * wage * 1.5;
	}
	void display(){
		cout << "Salaried Employee: " << name << endl;
		cout << "ID number: " << IDnumber << endl;
		cout << "Earned: " << earnings() << endl;
	}

};

class CommissionEmployee: public Employee{
public:
	double grossSales;
	double CommissionRate;
	// (1) define the constructor
	CommissionEmployee(){}
	CommissionEmployee(string n, string i, double g, double c)
		: Employee(n, i), grossSales(g), CommissionRate(c) {}

	// (2) define the earnings function
	double earnings() { return grossSales * CommissionRate; }
	void display(){
		cout << "Salaried Employee: " << name << endl;
		cout << "ID number: " << IDnumber << endl;
		cout << "Earned: " << earnings() << endl;
	}
};

class BasePlusCommissionEmployee: public CommissionEmployee{
public:
	double baseSalary;
	// (1) define the constructor
	BasePlusCommissionEmployee(){}
	BasePlusCommissionEmployee(string n, string i, double g, double c, double b)
		: CommissionEmployee(n, i, g, c), baseSalary(b) {}

	// (2) define the earnings function
	double earnings() { return (grossSales * CommissionRate) + baseSalary; }
	void display(){
		cout << "Salaried Employee: " << name << endl;
		cout << "ID number: " << IDnumber << endl;
		cout << "Earned: " << earnings() << endl;
	}

};



int main(int argc,char *argv[]){
	ifstream fin;
	fin.open(argv[1]);
	int n;
	fin >> n;
	Employee *employees[n];
	SalariedEmployee se[n];
	HourlyEmployee he[n];
	CommissionEmployee ce[n];
	BasePlusCommissionEmployee bpce[n];


	// Construct your input stream to the pointer array
	for(int i = 0; i < n; i++) {
		char type;
		string name, id;
		double a, b, c;
		fin >> type >> name >> id;

		switch (type) {
			case 'S': {
				fin >> a;
				se[i] = SalariedEmployee(name, id, a);
				employees[i] = &se[i];
				break;
			}
			case 'H': {
				fin >> a >> b;
				 he[i] = HourlyEmployee(name, id, a, b);
				 employees[i] = &he[i];
				break;
			}
			case 'C': {
				fin >> a >> b;
				 ce[i] = CommissionEmployee(name, id, a, b);
				 employees[i] = &ce[i];
				break;
			}
			case 'B': {
				fin >> a >> b >> c;
				bpce[i] = BasePlusCommissionEmployee(name, id, a, b, c);
				employees[i] = &bpce[i];
				break;
			}
		}
	}


	for(int i=0;i<n; i++){
		employees[i]->display();
		cout << "---------------------------------" << endl;
	}
	return 0;
}

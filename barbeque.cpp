/*
Name: Radityo Noeraldi Arief, Kevin Djoni,Jordanatha, Daniel Juanda, Mirna Sumopawiro
*/
#include<iostream>
#include<string>
using namespace std;

class Barbeque{
	private:
		string my_Brand;
		string my_Model;
		//booleans
		bool Coal = false; 
		bool Light = false;
		bool Cook = false;
		int counter = 0;    //to stop repitition
		
	public:
		Barbeque(string brand, string model){
			my_Brand = brand;
			my_Model = model;
		}
		void loadCoals(){
			if(counter == 0)
			{
			cout<<"Loading "<<my_Brand<<" "<<my_Model<<" with coals!"<<endl;
			Coal = true;
			counter++;
		    }
		    else if(counter>0)
		    cout<<"Coals already in Barbeque!"<<endl;
		}
		void light(){
			if(counter > 1)
		    cout<<"Already Light up!"<<endl;
			else if(hasCoals() && counter == 1)//implementation of hasCoals
			{
			cout<<"Lighting the grill!"<<endl;
			Light = true;
			counter++;
		    }
		    else if(counter == 0)
		    cout<<"You can't light this "<<my_Brand<<" "<<my_Model<<" until you load it with coals!"<<endl;
		}
		void cook(){
		    if(counter > 2 && isCooking())//implementation of isCooking()
		    cout<<"Already Cooking!"<<endl;
			else if(isLit() && counter == 2)//implementation of isLit()
			{
			cout<<"Cooking food!"<<endl;
			Cook = true;
			counter++;
		    }
		    else if(counter <= 1)
		    cout<<"You can't cook on this "<<my_Brand<<" "<<my_Model<<" until it has been lit!"<<endl;
		}
		void reset(){
			Cook = false;
			Coal = false;
			Light = false;
			counter = 0;
		}
		
		bool hasCoals() const{
			return Coal;
		}
		bool isLit() const{
			return Light;
		}
		bool isCooking() const{
			return Cook;
		}
};

int main(){
	
	string brand, model;
	int choice;
	
	//get model and brand
	cout<<"BARBEQUE SIMULATOR"<<"\n\n";
	cout<<"Input Barbeque Brand: ";
	getline(cin, brand);
	cout<<"Input Barbeque Model: ";
	getline(cin, model);
	
	Barbeque bbq(brand, model);
	
	//Menu Interface
	do{
	cout<<"\nInput Choice:\n";
	cout<<"1. Load Coal"<<endl;
	cout<<"2. Light Coal"<<endl;
	cout<<"3. Cook Food"<<endl;
	cout<<"4. Reset"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Input: ";
	cin>>choice;
	
	//implementation
	
	switch(choice){
		case 1:
			bbq.loadCoals();
			break;
		case 2:
			   bbq.light();
			break;
		case 3:
			   bbq.cook();
			break;
		case 4:
			bbq.reset();
			break;
		case 5:
		    exit(0);	   	   	
	}
	
    }while(choice != 5);
}

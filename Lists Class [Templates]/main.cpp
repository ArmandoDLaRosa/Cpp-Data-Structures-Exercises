#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

#include "lista.h"

int main() {

	Lista <int> test;
	
	int opcionMenu;
	cout << endl << "Before trying to use any option: \nInsert data into the list selecting \nOPTION '1'" << endl ;

	// This Menu is for integers, although the class 'Lista' can be used with other data types. 
	while (opcionMenu != 0)
    {
		cout << endl;
        cout << "OPTIONS MENU " << endl;
        cout << endl;

		cout << "0) EXIT" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Erase" << endl;
        cout << "3) Get List Data" << endl;
		cout << "4) Get List Size" << endl;
		cout << "5) Print"<< endl;
        
		cout << "   Select an option: ";
        cin  >> opcionMenu;
        cout << endl;
		
        switch (opcionMenu) 
		{
            case 1:
				int insert, quantity, count; 

				cout << "How many integers are you going to enter?" << endl;			
				cin >> quantity;
				cout << "Go ahead:" << endl;

				count = 0;
				while(count < quantity)
				{  
					cin >> insert;
					if (cin.fail())
    				{
						cout << "INVALID DATA" << endl;
						cout << "Continue where you left: "<< endl;
						cin.clear();

						cin.ignore(std::numeric_limits<int>::max(), '\n');
					} else
					{
					test.insert(insert);
					count++; 
					}
				}
				break;
                
            case 2:  
				int output;

				cout << "How many integers are you going to erase?" << endl;			
				cin >> quantity;

				count = 0;

				cout << "DELETED: ";
				while(count < quantity)
				{  
					output = test.erase();
					if ( output == 1)
					{
						//
						break;
					} else
					{

						cout << output << " ";
						count++;	
					}
				}
				cout << endl;
				break;

            case 3: 
				int location;
				cout << "Tell us the position of the element in the list you want to see" << endl;			
				cin >> location;			
				cout << test.getData(location);
				break;

            case 4:  
				cout << "The List size is:" << endl;			
				cout << test.getSize()<< endl;		
				break;
            
			case 5:  
				cout << "The List elements are:" << endl;	
				test.print();	
				break; 
        }
    } 

    return 0;
}
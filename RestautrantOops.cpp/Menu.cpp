#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Menu
{
    public:
    // list of food items here
    string fastfood[5];
    string Cake[5];
    string drink[5];
    string snacks[5];
    static bool message;

    // for amounts of items
    int foodAmounts[5];
    int cakeAmounts[5];
    int drinkAmounts[5];
    int snackAmounts[5];

   // consntructor
   Menu()
   {
       if(!message)
       {
          cout<<"Welcome to the Restro Menu"<<endl;
          message = true;
       }
   }

   string getFastFood(int index)
   {
       return fastfood[index];
   }

   string getCake(int index)
   {
       return Cake[index];
   }

   string getDrink(int index)
   {
       return drink[index];
   }

   string getSnacks(int index)
   {
       return snacks[index];
   }


   void setItems(string *ff , string *CC , string *dd , string *ss , int size )
   {
       for(int i = 0; i<size; i++)
       {
            fastfood[i] = ff[i];
           Cake[i] = CC[i];
           drink[i] = dd[i];
           snacks[i] = ss[i];
       }
    }

    void setAmount(int *Amount_Food , int *Amount_Cake , int *Amount_Drink , int *Amount_Snacks , int size)
    {
        for(int i = 0; i<size; i++)
        {
           foodAmounts[i] = Amount_Food[i];
           cakeAmounts[i] = Amount_Cake[i];
           drinkAmounts[i] = Amount_Drink[i];
           snackAmounts[i] = Amount_Snacks[i];
        }
        
    }

    // Set function for amounts of items
    string AmountFood(int index){
       return to_string(foodAmounts[index]);
    }
   

   string AmountCake(int index)
   {
       return to_string(cakeAmounts[index]);
   }

   string AmountDrink(int index)
   {
       return to_string(drinkAmounts[index]);
   }

   string AmountSnacks(int index)
   {
       return to_string(snackAmounts[index]);
   }

};

bool Menu::message = false;

class Order : public Menu{
    
public:

    vector <string> OrderItems;
    
   Order()
   {
       cout<<"What is your Order ?";
   }

   void takeOrder()
   {
       string item;
       int count = 0;
       int maxItemsOrder = 5;
    

       while(count < maxItemsOrder)
       {
           cout<<"\n Enter the item name : "<<" ";
           getline(cin ,  item);


            bool  found = false;

            for(int i = 0; i<5 ; i++)
        {
            if(item == fastfood[i] || item == Cake[i] || item == drink[i] || item == snacks[i])
            {

                found =  true;
                break;
            }
        }

            if(found){
                 OrderItems.push_back(item);
                 cout << item << " has been added to your order." << endl;
                 count++;
            } 
            else {
               cout << "Sorry, " << item << " is not available in the menu." << endl;
            }

            if (count < maxItemsOrder) {
                cout << "Would you like to order another item? (yes/no): ";
                string response;
                getline(cin, response);
                if (response != "yes") {
                    break;
                }
            }
        }
    }

    void showOrder()
    {
        cout<<"\nYour Order "<<endl;
        for(const string& item : OrderItems)
        {
            cout<<" - "<<item<<endl;
        }
    }
};


int main()
{

    Menu *M1 = new Menu();
    int size = 5;
    // Make an arrays For Items of different Fields
    string ff[5] = {"Pizza" , "Burger" , "Momos" , "FriedRice" , "Roll"};
    string CC[5] = {"ChocolateCake" , "CreamCake" , "VanillaCake" , "StrawberryCake" , "MangoCake"};
    string dd[5] = {"Mozito" , "SoftDrinks" , "Shake" , "ColdCoffee" , "Tea"};
    string ss[5] = {"Biscuit" , "CreamRoll" , "Namkeen" , "Bun" , "Toast"};
    M1->setItems(ff, CC,dd ,ss , size);
    
    //  Make an arrays for Amount 
    int Amount_Food[] = {200 , 150 , 70 , 90 , 50};
    int Amount_Cake[] = {500 , 450 , 750 , 690 , 850};
    int Amount_Drink[] = {80 , 30 , 60 , 40 , 10};
    int Amount_Snacks[] = {20 , 10 , 30 , 10 , 20};
    M1->setAmount(Amount_Food , Amount_Cake ,Amount_Drink , Amount_Snacks , size);

    
    
    
    cout<<"\nFastFood Item : "<<"Amount"<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<M1->getFastFood(i)<<" :  ";
        cout<<M1->AmountFood(i)<<endl;
    }

    cout<<"\nCakes Item : "<<"Amount"<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<M1->getCake(i)<<" : ";
        cout<<M1->AmountCake(i)<<endl;
    }

    cout<<"\nDrinks Item : "<<"Amount"<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<M1->getDrink(i)<<" :  ";
        cout<<M1->AmountDrink(i)<<endl;
    }

    cout<<"\nSnacks Item : "<<"Amount"<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<M1->getSnacks(i)<<" :  ";
        cout<<M1->AmountSnacks(i)<<endl;
        
    }


    Order *myOrder = new Order();
    myOrder->takeOrder();
    myOrder->showOrder();

    delete M1;
    delete myOrder;

    return 0;
}



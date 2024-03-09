#include <bits/stdc++.h>
using namespace std;

/* Name: Youssif Hisham Mahmoud
 * ID: 20200675
 * Section: S3
*/

//Starting the Item class
class Item{
private:
    int price, quantity, ID;
    string name;
    static int IDNUM;
public:

    //default Constcutor
    Item(){
        ID = 0;
        quantity = 0;
        price = 0;
        name = "NULL";
    }

    //Parametrized Constcutor - which create an object with the following parameters of the private access
    Item(int pri, int quan, int id, string s){
        price = pri;
        quantity = quan;
        ID = IDNUM;
        name = s;
        IDNUM++;
    }

    //Copy Constructor - Taking object as parameter
    Item(const Item &obj)
    {
        price = obj.price;
        quantity = obj.quantity;
        ID = obj.ID;
        name = obj.name;
        IDNUM = obj.IDNUM++;     //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    }

    //Setters & Getters for Class ITEM
    void setPRICE(int pri) {price = pri;};
    int getPRICE() { return price;};

    void setQUANTITY(int quan){quantity = quan;};
    int getQUANTITY() {return quantity;};

    void setID(int id){ID = id;};
    int getID() {return ID;};

    void setNAME(int s){name = s;};
    string getNAME() {return name;};

    static int getSERIALID(){
        return (IDNUM);
    }


    //overload function that act as an info input function for the class
    friend istream& operator>>(istream& is, Item &right){
        is>>right.name>>right.quantity>>right.price;
        return is;
    }


    //in the opposite this overload function print the info put by user
    friend ostream& operator<<(ostream& os, Item &right){
        os<<"Name: "<<right.name<<'\n'<<"ID: "<<right.ID<<'\n'<<"Quantity: "<<right.quantity<<'\n'<<"Price: "<<right.price<<'\n';
        return os;
    }


    //overload operator that will compare the names of the items entered and it is boolean that returns 1/0, yes/no
    bool operator==(const Item &obj){
        return ((name==obj.name));
    }

    //overload operator that add the items to the cart for example
    void operator+=(Item &add){
        quantity += add.quantity;
    }
    //overload operator that delete the item from the cart
    void operator-=(Item &sub) {
        quantity -= sub.quantity;
    }

    //a friend class for seller to have access to the private variables
    friend class seller;

};

//The static variable that is the serial ID number of the items
int Item::IDNUM=1;

//The seller class
class seller {
private:
    Item *items;
    int maxitems;
    string email, name;

public:
    //Parametirized constructor that take the client info
    seller(int maxit, string n, string em) {
        items = new Item[maxit];
        name = n;
        email = em;
        maxitems = maxit;
    }

    //overload operator that print out the info taken from the client
    friend ostream &operator<<(ostream &os, seller &right) {
        os << "The Seller Info is: " << endl;
        os << "Name: " << right.name << endl;
        os << "Email: " << right.email << endl;
        return os;
    }

    //The public member function that add items to the cart
    bool add(Item &obj) {
        for (int i = 0; i < maxitems; i++) {
            if (this->items[i] == obj) { //Here it checks first if the item entered exists
                this->items[i] += obj; //if yes it will add to the cart for example
                return true;
            } else if (this->items[i].getNAME() == "NULL") {
                this->items[i] = obj;
                this->items[i].ID = this->items[i].getSERIALID();
                this->items[i].IDNUM++;
                return true;
            }
        }
        return false;
    }

    //function that sell items from the store
    bool sell(string it, int num){
        for(int i=0; i<maxitems; i++){
            if(this->items[i].name==it){
                if(this->items[i].quantity>=num){
                    this->items[i].quantity-=num;
                }
                else{
                    cout << "There is nly "<<this->items[i].quantity <<"left for this item";
                }
                return true;
            }
        }
        return false;
    }

    //function that check the existence of the item by the name
    bool find(int num){
        for(int i=0; i<maxitems;i++){
            if(this->items[i].ID==num){
                return true;
            }
        }
        return false;
    }

    //Public member function to search the items entered by it's serial ID
    Item searchbyserial(int find){
        for(int i=0; i<maxitems; i++){
            if(this->items[i].ID == find){
                return this->items[i];
            }
        }
    }

    //Public member function to Print out the items entered
    void display(){
        for(int i=0; i<maxitems; i++){
            cout << items[i];
        }
    }

    //Destructor of the seller class
    ~seller(){ delete[] items;};

};


int main() {
    //Take the clien info
    cout << "Enter Your Name: ";
    string name; cin >> name;

    cout <<"Enter Your Email: ";
    string email; cin >> email;

    cout <<"Enter number of items to sell: ";
    int maxitems; cin >> maxitems;

    seller seller1(maxitems, name, email);

    int choose=0; //this is the navigator of the user enterence in the menu

    //The Loop that will keep popping to the user till you choose 6 and will trigger
    //Every function that do the step chosen
    while(choose!=6) {
        cout << "Menu: " << endl;
        cout << "1. Print my Info" << endl;
        cout << "2. Add An Item" << endl;
        cout << "3. Sell An Item" << endl;
        cout << "4. Print Items" << endl;
        cout << "5. Find an Item by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "Please Choose what you want to do: ";
        cin >> choose;

        if(choose==1){
            cout << seller1;
        }
        else if(choose==2){
            cout<<"Enter The Item Info in this order, Name, Quantity, Price: ";
            Item item1;
            cin >> item1;
            if(seller1.add(item1)){
                cout << "Item is added to cart successfully";
            }
        }
        else if(choose == 3){
            cout << "Please enter Item's Name and quantity: ";
            string itemname;
            int quant;
            cin >> itemname >> quant;
            if(!(seller1.sell(itemname, quant))){
                cout << "It's Not Found here!"<<endl;
            }
        }
        else if(choose==4){
            seller1.display();
        }
        else if(choose==5){
            cout <<"Please enter the Item ID: ";
            int num; cin >> num;
            if(seller1.find(num)){
                Item item2;
                item2 = seller1.searchbyserial(num);
                cout << item2;
            }
            else{
                cout<<"Item is not found!";
            }
        }
    }

    return 0;
}

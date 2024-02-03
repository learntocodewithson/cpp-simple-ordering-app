#include<iostream>
#include<string>
using namespace std;

struct MyCart {
  string name;
  int quantity, price;
};

// function declaration
void displayOrderingOptions();
void displayProducts();
void buyPizza(MyCart (&my_cart)[5], int &cart_index);
void editPizzaFromCart();
void deletePizzaFromCart();

int main(){
 int ordering_option, cart_index;
 bool exit_option = 0;
 MyCart my_cart[5];

 do {
   displayOrderingOptions();
   cout << "Enter any number from 1 to 4: ";
   cin >> ordering_option;

   switch(ordering_option){
    case 1:
     buyPizza(my_cart, cart_index);
     break;
    case 2:
     editPizzaFromCart();
     break;
    case 3:
     deletePizzaFromCart();
     break;
    case 4:
     exit_option = 1;
     cout << endl << "Thank you for using this app. Come again.";
     break;
    default:
     cout << "";
   }

 } while (!exit_option);

 return 0;
}

// function definition
void displayOrderingOptions(){
 cout << endl << "Welcome to Simple Ordering APP";
 cout << endl << "what would you like to do?";
 cout << endl << "1. Buy Pizza";
 cout << endl << "2. Edit Cart";
 cout << endl << "3. Remove product from my cart";
 cout << endl << "4. Exit" << endl;
}

void buyPizza(MyCart (&my_cart)[5], int &cart_index){
 int pizza_option, pizza_price, pizza_qty;
 string pizza_name;

 cout << endl <<"-- Buy Product --";
 displayProducts();
 cout << endl << endl << "What do you want to order? ";
 cin >> pizza_option;
 cout << "How many? ";
 cin >> pizza_qty;

 switch (pizza_option) {
  case 1:
   pizza_price = 160;
   pizza_name = "KP Hawaiian - 160";
   break;
  case 2:
   pizza_price = 260;
   pizza_name = "KP Pepperoni Supreme - 260";
   break;
  case 3:
   pizza_price = 295;
   pizza_name = "KP Beef Pizza(F) - 295";
   break;
  case 4:
   pizza_price = 310;
   pizza_name = "KP Special(F) - 310";
   break;
  default:
   pizza_price = 0;
   pizza_name = "";
   cout << "";
 }
 
 // save to array ...
 my_cart[cart_index].name = pizza_name;
 my_cart[cart_index].price = pizza_price;
 my_cart[cart_index].quantity = pizza_qty;

 cout << "Thank you, your pizza "<< my_cart[cart_index].name << " has been successfully added to your cart." << endl;

 cart_index++;
}

void editPizzaFromCart(){
 cout << endl <<"-- Edit Product From Cart --";
}

void deletePizzaFromCart(){
 cout << endl <<"-- Delete Product From Cart --";
}

void displayProducts(){
 cout << endl << "Pizza Products:";
 cout << endl << "1. KP Hawaiian - 160";
 cout << endl << "2. KP Pepperoni Supreme - 260";
 cout << endl << "3. KP Beef Pizza(F) - 295";
 cout << endl << "4. KP Special(F) - 310";
}
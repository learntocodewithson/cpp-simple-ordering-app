#include<iostream>
#include<string>
using namespace std;

struct MyCart {
  string name;
  int quantity, price;
};

// function declaration
void displayCart(MyCart (&my_cart)[5]);
void displayOrderingOptions();
void displayProducts();
void buyPizza(MyCart (&my_cart)[5], int &cart_index);
void editPizzaFromCart();
void deletePizzaFromCart(MyCart (&my_cart)[5]);
void removeElement(MyCart (&my_cart)[5], int position);

int main(){
 int ordering_option, cart_index;
 bool exit_option = 0;
 MyCart my_cart[5];

 cout << endl << "Welcome to Simple Ordering APP";

 do {
   displayCart(my_cart);
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
     deletePizzaFromCart(my_cart);
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
void displayCart(MyCart (&my_cart)[5]){
  int subtotal, total = 0;
  cout << endl << "===================" << endl;
  cout << endl << "MY CART (Order Summary):" << endl << endl;
  for (int i = 0; i < 5; i++) {
    if(my_cart[i].name != ""){
      subtotal = my_cart[i].price * my_cart[i].quantity;
      total += subtotal;
      cout << (i + 1) << ".) " << my_cart[i].quantity << " " << my_cart[i].name << " - " << my_cart[i].price << "(" << my_cart[i].quantity  << ") = " << subtotal << "\n";
    }
  }

  if(total > 0){
    cout << endl << "TOTAL: " << total;
  }
  cout << endl << "===================" << endl;
}

void displayOrderingOptions(){
 cout << endl << "what would you like to do?";
 cout << endl << "1. Buy Pizza";
 cout << endl << "2. Edit Cart";
 cout << endl << "3. Remove product from my cart";
 cout << endl << "4. Exit" << endl;
}

void buyPizza(MyCart (&my_cart)[5], int &cart_index){
 int pizza_option, pizza_price, pizza_qty;
 string pizza_name;

 cout << endl << "-- Buy Product --";
 displayProducts();
 cout << endl << endl << "What do you want to order? ";
 cin >> pizza_option;
 cout << "How many? ";
 cin >> pizza_qty;

 switch (pizza_option) {
  case 1:
   pizza_price = 160;
   pizza_name = "KP Hawaiian";
   break;
  case 2:
   pizza_price = 260;
   pizza_name = "KP Pepperoni Supreme";
   break;
  case 3:
   pizza_price = 295;
   pizza_name = "KP Beef Pizza(F)";
   break;
  case 4:
   pizza_price = 310;
   pizza_name = "KP Special(F)";
   break;
  default:
   pizza_price = 0;
   pizza_name = "";
   cout << "";
 }
 
 for(int i = 0; i < 5; i++){
  if(my_cart[i].name == ""){
    my_cart[i].name = pizza_name;
    my_cart[i].price = pizza_price;
    my_cart[i].quantity = pizza_qty;
    cart_index = i;
    break;
  }
 }

 cout << endl << "Thank you, your pizza "<< my_cart[cart_index].name << " has been successfully added to your cart." << endl << endl;

 cart_index++;
}

void editPizzaFromCart(){
 cout << endl <<"-- Edit Product From Cart --";
}

void deletePizzaFromCart(MyCart (&my_cart)[5]){
 int position;
 cout << endl << "-- Delete Product From Cart --";
 displayCart(my_cart);
 cout << endl << "Enter the position of the pizza that you want to remove: ";
 cin >> position;

 removeElement(my_cart, position);
}

void removeElement(MyCart (&my_cart)[5], int position){

  int index = position - 1;
 
  my_cart[index].name = "";
  my_cart[index].price = 0;
  my_cart[index].quantity = 0;

  // swapping - customized
  for(int i = 0; i < 5; i++){
   if(my_cart[i].name == ""){
    // update empty values using the next pizza
    my_cart[i].name = my_cart[i+1].name;
    my_cart[i].price = my_cart[i+1].price;
    my_cart[i].quantity = my_cart[i+1].quantity;

    my_cart[i+1].name = "";
    my_cart[i+1].price = 0;
    my_cart[i+1].quantity = 0;
   }
  }
}

void displayProducts(){
 cout << endl << "Pizza Products:";
 cout << endl << "1. KP Hawaiian - 160";
 cout << endl << "2. KP Pepperoni Supreme - 260";
 cout << endl << "3. KP Beef Pizza(F) - 295";
 cout << endl << "4. KP Special(F) - 310";
}
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
void buyPizza(MyCart (&my_cart)[5]);
void addToCart(MyCart (&my_cart)[5], string name, int price, int quantity);
void editPizzaFromCart(MyCart (&my_cart)[5]);
void deletePizzaFromCart(MyCart (&my_cart)[5]);
void removeElement(MyCart (&my_cart)[5], int position);
void payNow(MyCart (&my_cart)[5]);
void resetCart(MyCart (&my_cart)[5]);
int calculateTotal(MyCart (&my_cart)[5]);

int main(){
 int ordering_option;
 bool exit_option = 0;
 MyCart my_cart[5];

 cout << endl << "Welcome to Simple Ordering APP";

 do { 
   displayCart(my_cart);
   displayOrderingOptions();
   cout << "Enter any number from 1 to 5: ";
   cin >> ordering_option;

   switch(ordering_option){
    case 1:
     buyPizza(my_cart);
     break;
    case 2:
     editPizzaFromCart(my_cart);
     break;
    case 3:
     deletePizzaFromCart(my_cart);
     break;
    case 4:
     system("clear");
     payNow(my_cart);
     break;
    case 5:
     exit_option = 1;
     cout << endl << "Thank you for using this app. Come again.";
     break;
    default:
     exit_option = 1;
     cout << "";
   }

 } while (!exit_option);

 return 0;
}

// function definition
void displayCart(MyCart (&my_cart)[5]){
  int subtotal, total = 0;
  system("clear");
  cout << endl << "==============================" << endl;
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
  cout << endl << "==============================" << endl;
}

void displayOrderingOptions(){
 cout << endl << "what would you like to do?";
 cout << endl << "1. Buy Pizza";
 cout << endl << "2. Edit Cart";
 cout << endl << "3. Remove product from my cart";
 cout << endl << "4. Pay Now";
 cout << endl << "5. Exit" << endl;
}

void buyPizza(MyCart (&my_cart)[5]){
 int pizza_option, pizza_price, pizza_qty;
 string pizza_name;
 system("clear");
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
 }

 if(pizza_price == 0 && pizza_name == ""){
  cout << "No product found.";
 }else{
  addToCart(my_cart, pizza_name, pizza_price, pizza_qty);
 }
}

void addToCart(MyCart (&my_cart)[5], string name, int price, int quantity){
 for(int i = 0; i < 5; i++){
  if(my_cart[i].name == ""){
    my_cart[i].name = name;
    my_cart[i].price = price;
    my_cart[i].quantity = quantity;
    cout << endl << "Thank you, your pizza "<< my_cart[i].name << " has been successfully added to your cart." << endl << endl;
    break;
  }
 }
}

void editPizzaFromCart(MyCart (&my_cart)[5]){
 int position, quantity;

 cout << endl <<"-- Edit Product From Cart --";
 displayCart(my_cart);
 cout << endl << "Enter the position of the pizza that you want to edit: ";
 cin >> position;
 cout << "Enter the new quantity: ";
 cin >> quantity;

 if(quantity <= 0){
  removeElement(my_cart, position);
  cout << endl << my_cart[position-1].name << "has been removed from your cart.";
 }else{
  my_cart[position-1].quantity = quantity;
  cout << endl << "You've successfully changed the quantity of " << my_cart[position-1].name;
 }
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

void payNow(MyCart (&my_cart)[5]){
  int cash_on_hand, amount_change;
  int total = calculateTotal(my_cart);

  cout << endl << "--Pay Now --";
  cout << endl << "Total amount: " << total;
  cout << endl << "Enter the payment amount: ";
  cin >> cash_on_hand;

  if(total > cash_on_hand){
    system("clear");
    cout << endl << "Cash on hand should be greater than the total.";
    payNow(my_cart);
  }else{
    amount_change = cash_on_hand - total;
    cout << "Thank you, your change is " << amount_change;
    resetCart(my_cart);
  }
}

void resetCart(MyCart (&my_cart)[5]){
 for (int i = 0; i < 5; i++) {
  my_cart[i].name = "";
  my_cart[i].price = 0;
  my_cart[i].quantity = 0;
 }
}

int calculateTotal(MyCart (&my_cart)[5]){
 int subtotal, total = 0;
 for (int i = 0; i < 5; i++) {
  if(my_cart[i].name != ""){
    subtotal = my_cart[i].price * my_cart[i].quantity;
    total += subtotal;
  }
 }
 return total;
} 
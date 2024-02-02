# cpp-simple-ordering-app

Problem:
Create a C++ application on adding, removing, and/or updating a customer's orders by using arrays.

Product (list of products) - static
 - product_id, name, price
Order (dynamic at runtime)
 - product_id, quantity, total
Database
 - Array

Actions: 
- Create, Read, Update, Delete (CRUD)

=================
Screen 1: (portal)
Welcome to Simple Ordering APP
what would you like to do?
1. Buy
2. Edit Cart
3. Remove product from my cart
4. Exit

Enter any number form 1 to 4: 1 
— proceed to screen for buying if 1 is pick

=========

PICK: 1

Screen 2 for Buying (Add): 
Products:
1. Product A - 50
2. Product B - 100
3. Product C - 150
4. Product D - 200

What do you want to order? 1
How many? 2

Thank you, you ordered Product A (2pcs) with total of 100, and it is added on your cart.repeat Screen 1.


===================

PICK 2: (EDIT)

My Cart:
 1. Product A - 50(2) - 100
 2. Product B - 100(1) - 100

Total: 200

What would you to edit? 1
You choose to edit Product A.change quantity: 3

if 0 = delete the product
else if greater than 0 
update the product and recompute the total

update product - 
Thank you, you update the Product A with new quantity of 3 and new total of 150. Your car is now updated.

if 0: Product A is now remove on your cart.

Repeat Screen 1.

=====================

PICK: 3 (Delete)My Cart:
 1. Product A - 50(2) - 100
 2. Product B - 100(1) - 100

Total: 200

What would you like to delete? 1
Are you sure you want to delete Product A? (Y - yes, N - no): 

If yes - delete
else no - don’t delete

message: 
yes  - Product A is now remove on your cart.
no  - ignore

Repeat Screen 1.

============= 

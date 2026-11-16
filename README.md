# DSA_Coffe_finals

## Brew & Bean Co. - Coffee Inventory & Search System

A console-based C++ inventory system for a coffee shop that carries partner brands (Nescafe, Lavazza, Illy, and Kopiko). It lets a customer browse, search, filter, and sort the catalog, build a shopping cart, and join a checkout queue. An admin can undo or redo inventory changes.

Every feature is built on a data structure or algorithm from the course labs (Labs 1-8).

**Author:** [YOUR FULL NAME]  
**Course / Section:** CS201 - Data Structure and Algorithm Analysis, BS in Computer Engineering  
**Instructor:** Engr. Kaycee Calinaya  
**Date:** NOV. 17, 2026

---

## Features

| Menu | Feature | What it does |
|:---:|---|---|
| 1 | View Complete Catalog | Shows all products in a table with brand, price, and stock |
| 2 | Filter Products by Official Brand | Shows only the products of one partner brand |
| 3 | Search Products | Keyword search (linear search) or product ID search (BST) |
| 4 | Filter Products by Price Range | Finds products within a price range using binary search |
| 5 | Add Item to Shopping Cart | Cart with next / previous navigation (doubly linked list) |
| 6 | Process Customer Checkout Queue | Processes orders first in, first out (queue) |
| 7 | Perform Admin Undo Action | Undo or redo adding and restocking products (stack) |
| 8 | Display Partner Brand Banner Showcase | Banners of the partner brands that loop forever (circular list) |
| 9 | Sort Inventory Display | Sorts by price, stock, or brand |
| 10 | Exit | Closes the program |

---

## Partner Brands

| | |
|---|---|
| **Niche** | Coffee products (instant coffee, beans, ground coffee, capsules, ready-to-drink) |
| **Brands** | Nescafe, Lavazza, Illy, Kopiko |
| **Starting inventory** | 14 products |

---

## Scope and Delimitations

**Scope**

- Viewing, filtering, searching, and sorting the coffee catalog
- Shopping cart with forward and backward navigation
- First-in, first-out processing of customer orders
- Admin undo and redo for adding products and restocking
- Looping showcase of the partner brand banners

**Delimitations**

- Console-based only (no graphical interface)
- Limited to the coffee niche and the four partner brands
- Admin undo and redo cover only **add product** and **restock** actions
- Product data starts from the built-in starting inventory

---

## Lab Integration (Labs 1-8)

| Lab | Concept | Where it is used |
|:---:|---|---|
| 1 | Dynamic allocation | **Catalog**: dynamic array that doubles in size with `new[]` / `delete[]` |
| 2 | Doubly linked list | **Cart**: shopping cart with next / previous navigation (menu 5) |
| 3 | Circular linked list | **BrandShowcase**: partner brand banners that loop forever (menu 8) |
| 4 | Stack (LIFO) | **Admin** undo and redo of "add product" and "restock" (menu 7) |
| 5 | Queue (FIFO) | **Checkout** and order processing line (menu 6) |
| 6 | Binary Search Tree | **IdIndex**: product ID lookup in O(log n) (menu 3, ID search) |
| 7 | Searching | Linear keyword search (menu 3) and binary price-range search (menu 4) |
| 8 | Sorting | Quick sort for price and stock, insertion sort for brand (menu 9) |

---

## Product Structure

```cpp
struct Product {
    int id;
    string name;
    string category;
    string brand;
    double price;
    int stockQuantity;
};
```

---

## Memory Management

- Every `new` has a matching `delete` / `delete[]` in a destructor (catalog, BST, cart, brand showcase).
- Copying of classes that own memory is disabled to prevent double frees.
- The circular list is "opened" before deletion so it is freed safely.
- Input is validated, and empty carts, empty queues, missing products, and insufficient stock are handled.
- Checked with `-fsanitize=address,undefined`: **no leaks or memory errors**.

---

## Project Structure

```
DSA_Coffe_finals/
├── Makefile
├── README.md
├── .gitignore
│
├── main.cpp             program entry point, menu loop only
├── Product.h            Product struct
├── Utils.h/.cpp         toLower, fit (small string helpers)
├── Input.h/.cpp         validated input (readLine, readInt, readPrice)
├── Display.h/.cpp       table printing
│
├── Catalog.h/.cpp       Lab 1    - dynamic array
├── Cart.h/.cpp          Lab 2    - doubly linked list
├── BrandShowcase.h/.cpp Lab 3    - circular linked list
├── Shop.h/.cpp          Labs 4-5 - order queue, undo/redo stacks, starting data
├── IdIndex.h/.cpp       Lab 6    - binary search tree
├── Searching.h/.cpp     Lab 7    - linear and binary search
├── Sorting.h/.cpp       Lab 8    - quick sort, insertion sort, comparators
│
├── Menus.h              menu function declarations
├── MainMenu.cpp         main menu text
├── CatalogMenu.cpp      menus 1, 2, 3, 4, 8, 9
├── OrderMenu.cpp        menus 5, 6
└── AdminMenu.cpp        menu 7
```

---

## How to Compile and Run

**Compile**

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o coffee_shop
```

Or, if you have `make` installed:

```bash
make
```

**Run**

Windows:

```bash
.\coffee_shop.exe
```

Mac / Linux:

```bash
./coffee_shop
```

Programming Language

C++17

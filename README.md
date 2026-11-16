Brew & Bean Co.
Brand-Affiliated Coffee Inventory & Search System (CS201)

Data Structure and Algorithm Analysis - Final Output, BS in Computer Engineering

Project Description

A console-based coffee shop inventory and ordering system written in C++. It manages a multi-brand coffee catalog, lets customers search, filter and sort products, build a cart, and join a checkout queue, and gives the admin undo/redo for inventory changes.

Domain and Official Partner Brands

Niche: Coffee products (instant coffee, beans, ground coffee, capsules, ready-to-drink)

Partner brands: Nescafe, Lavazza, Illy, Kopiko (14 starting products)

Product Structure
cpp
struct Product {
    int id;
    string name;
    string category;
    string brand;
    double price;
    int stockQuantity;
};
Lab Integration (Labs 1-8)
Lab	Concept	Where it is used
1	Dynamic allocation	Catalog: dynamic array that doubles in size with new[] / delete[]
2	Doubly linked list	Cart: shopping cart with next / previous navigation (menu 5)
3	Circular linked list	BrandShowcase: partner brand banners that loop forever (menu 8)
4	Stack (LIFO)	Admin undo and redo of "add product" and "restock" (menu 7)
5	Queue (FIFO)	Checkout and order processing line (menu 6)
6	Binary Search Tree	IdIndex: product ID lookup in O(log n) (menu 3, ID search)
7	Searching	Linear keyword search (menu 3) and binary price-range search (menu 4)
8	Sorting	Quick sort for price and stock, insertion sort for brand (menu 9)
Menu
View Complete Catalog (tabular view with brand affiliations)
Filter Products by Official Brand
Search Products (keyword = linear search, product ID = BST)
Filter Products by Price Range (binary search)
Add Item to Shopping Cart (doubly linked list navigation)
Process Customer Checkout Queue (FIFO order queue)
Perform Admin Undo Action (LIFO stack pop; also add, restock, redo)
Display Partner Brand Banner Showcase (circular list cycle)
Sort Inventory Display (by price, stock, or brand)
Exit
Memory Management
Every new has a matching delete / delete[] in a destructor (catalog, BST, cart, brand showcase).
Copying of the classes that own memory is disabled to prevent double frees.
The circular list is "opened" before deletion so it is freed safely.
Input is validated, and empty carts, empty queues, missing products and insufficient stock are handled.
Checked with -fsanitize=address,undefined: no leaks or memory errors.
Project Structure
```
coffee_dsa_project/
├── Makefile
├── README.md
├── .gitignore
└── src/
    ├── main.cpp            program entry point, menu loop only
    ├── Product.h           Product struct
    ├── Utils.h/.cpp        toLower, fit (small string helpers)
    ├── Input.h/.cpp        validated input (readLine, readInt, readPrice)
    ├── Display.h/.cpp      table printing
    ├── Catalog.h/.cpp      Lab 1  - dynamic array
    ├── Cart.h/.cpp         Lab 2  - doubly linked list
    ├── BrandShowcase.h/.cpp Lab 3 - circular linked list
    ├── Shop.h/.cpp         Labs 4-5 - Order queue, undo/redo stacks, seed data
    ├── IdIndex.h/.cpp      Lab 6  - binary search tree
    ├── Searching.h/.cpp    Lab 7  - linear and binary search
    ├── Sorting.h/.cpp      Lab 8  - quick sort, insertion sort, comparators
    ├── Menus.h             menu function declarations
    ├── MainMenu.cpp        main menu text
    ├── CatalogMenu.cpp     menus 1, 2, 3, 4, 8, 9
    ├── OrderMenu.cpp       menus 5, 6
    └── AdminMenu.cpp       menu 7
```

How to Compile
```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o coffee_shop
```
(or just run `make` if you have it installed)

How to Run

Windows:
```bash
.\coffee_shop.exe
```

Mac/Linux:
```bash
./coffee_shop
```

Programming Language

C++17

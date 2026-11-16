#include <iostream>
#include "Menus.h"
using namespace std;

void printMenu() {
    cout << "\n==================================================================\n"
         << "  BREW & BEAN CO. - BRAND-AFFILIATED COFFEE INVENTORY & SEARCH (CS201)\n"
         << "==================================================================\n"
         << "1. View Complete Catalog (Tabular View with Brand Affiliations)\n"
         << "2. Filter Products by Official Brand (Nescafe, Lavazza, Illy, Kopiko)\n"
         << "3. Search Products (Keyword = Linear Search, ID = BST)\n"
         << "4. Filter Products by Price Range (Binary Search)\n"
         << "5. Add Item to Shopping Cart (Doubly Linked List Navigation)\n"
         << "6. Process Customer Checkout Queue (FIFO Order Queue)\n"
         << "7. Perform Admin Undo Action (LIFO Stack Pop)\n"
         << "8. Display Partner Brand Banner Showcase (Circular List Cycle)\n"
         << "9. Sort Inventory Display (By Price, Stock, or Brand)\n"
         << "10. Exit\n"
         << "==================================================================\n";
}

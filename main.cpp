
#include <iostream>
#include "Input.h"
#include "Menus.h"
#include "Shop.h"
using namespace std;

int main() {
    Shop shop;
    seedCatalog(shop);

    bool running = true;
    try {
        while (running) {
            printMenu();
            switch (readInt("Enter your choice: ", 1, 10)) {
                case 1: viewCatalog(shop); break;
                case 2: filterByBrand(shop); break;
                case 3: searchProducts(shop); break;
                case 4: filterByPrice(shop); break;
                case 5: cartMenu(shop); break;
                case 6: checkoutMenu(shop); break;
                case 7: adminMenu(shop); break;
                case 8: brandShowcaseMenu(shop); break;
                case 9: sortInventory(shop); break;
                case 10: running = false; break;
            }
        }
    } catch (const InputClosed&) {
        cout << "\n[Input closed]";
    }
    cout << "\nThank you for visiting Brew & Bean Co.!\n";
    return 0;
}

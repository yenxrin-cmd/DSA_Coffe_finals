#include <iomanip>
#include <iostream>
#include "Display.h"
#include "Input.h"
#include "Menus.h"
#include "Utils.h"
using namespace std;



static void showCartItem(Shop& s) {
    CartNode* n = s.cart.current();
    if (n == nullptr) { cout << "\nYour cart is empty.\n"; return; }
    Product* p = s.findById(n->productId);
    cout << "\n  Cart item (" << s.cart.size() << " total):\n  ";
    if (p) cout << p->name << " [" << p->brand << "]  x" << n->quantity
                << "  = PHP " << fixed << setprecision(2) << p->price * n->quantity << '\n';
    else cout << "(product no longer exists)\n";
}

void cartMenu(Shop& s) {
    while (true) {
        cout << "\n--- SHOPPING CART ---\n"
             << "  1. Add item\n  2. Next item  >>\n  3. Previous item  <<\n"
             << "  4. Remove current item\n  5. View all items\n  0. Back\n";
        int c = readInt("Choose: ", 0, 5);
        if (c == 0) return;

        if (c == 1) {
            int id = readInt("Product ID: ", 1, 1000000);
            Product* p = s.findById(id);
            if (!p) { cout << "  [!] Product not found.\n"; continue; }
            int q = readInt("Quantity: ", 1, 1000);
            int inCart = 0;
            for (CartNode* n = s.cart.first(); n; n = n->next)
                if (n->productId == id) inCart = n->quantity;
            if (inCart + q > p->stockQuantity) {
                cout << "  [!] Only " << p->stockQuantity << " in stock (" << inCart << " already in cart).\n";
                continue;
            }
            s.cart.add(id, q);
            cout << "  [OK] Added " << q << " x " << p->name << " to cart.\n";
        } else if (c == 2) {
            if (!s.cart.moveNext()) cout << "  Already at the last item (or cart is empty).\n";
            showCartItem(s);
        } else if (c == 3) {
            if (!s.cart.movePrev()) cout << "  Already at the first item (or cart is empty).\n";
            showCartItem(s);
        } else if (c == 4) {
            if (s.cart.empty()) { cout << "  Cart is empty.\n"; continue; }
            s.cart.removeCurrent();
            cout << "  [OK] Item removed.\n";
            showCartItem(s);
        } else {
            if (s.cart.empty()) { cout << "\nYour cart is empty.\n"; continue; }
            double total = 0;
            cout << "\n--- CART CONTENTS ---\n";
            for (CartNode* n = s.cart.first(); n; n = n->next) {
                Product* p = s.findById(n->productId);
                if (!p) continue;
                cout << (n == s.cart.current() ? " > " : "   ") << left << setw(30) << fit(p->name, 29)
                     << " x" << setw(4) << n->quantity << right << setw(10) << fixed << setprecision(2)
                     << p->price * n->quantity << '\n';
                total += p->price * n->quantity;
            }
            cout << "   Total: PHP " << total << "   (> marks current item)\n";
        }
    }
}



static void processNextOrder(Shop& s) {
    if (s.orders.empty()) { cout << "\nNo pending orders in the queue.\n"; return; }
    Order o = s.orders.front();
    s.orders.pop();

  
    for (const OrderLine& l : o.lines) {
        Product* p = s.findById(l.productId);
        if (!p || p->stockQuantity < l.quantity) {
            cout << "\n[!] Order #" << o.orderId << " could not be fulfilled: "
                 << (p ? p->name + " has only " + to_string(p->stockQuantity) + " in stock"
                       : string("a product no longer exists")) << ".\n";
            return;
        }
    }
    double total = 0;
    cout << "\n=== ORDER #" << o.orderId << " PROCESSED ===\nCustomer: " << o.customer << '\n';
    for (const OrderLine& l : o.lines) {
        Product* p = s.findById(l.productId);
        p->stockQuantity -= l.quantity;
        total += p->price * l.quantity;
        cout << "  " << left << setw(30) << fit(p->name, 29) << " x" << l.quantity
             << "  (stock left: " << p->stockQuantity << ")\n";
    }
    cout << "Total: PHP " << fixed << setprecision(2) << total << '\n';
}

void checkoutMenu(Shop& s) {
    cout << "\n--- CHECKOUT QUEUE (FIFO) ---\n"
         << "  1. Place order from my cart (join queue)\n"
         << "  2. Process next order in line\n"
         << "  3. View pending orders\n  0. Back\n";
    int c = readInt("Choose: ", 0, 3);

    if (c == 1) {
        if (s.cart.empty()) { cout << "\n[!] Your cart is empty.\n"; return; }
        string name = readLine("Customer name: ");
        if (name.empty()) { cout << "  [!] Name cannot be empty.\n"; return; }
        Order o{s.nextOrderId++, name, {}};
        for (CartNode* n = s.cart.first(); n; n = n->next) o.lines.push_back({n->productId, n->quantity});
        s.orders.push(o);
        s.cart.clear();
        cout << "  [OK] Order #" << o.orderId << " joined the queue (position " << s.orders.size() << ").\n";
    } else if (c == 2) {
        processNextOrder(s);
    } else if (c == 3) {
        if (s.orders.empty()) { cout << "\nNo pending orders.\n"; return; }
        queue<Order> copy = s.orders;
        cout << "\nPENDING ORDERS (front of line first)\n";
        while (!copy.empty()) {
            cout << "  #" << copy.front().orderId << " - " << copy.front().customer
                 << " (" << copy.front().lines.size() << " item type(s))\n";
            copy.pop();
        }
    }
}

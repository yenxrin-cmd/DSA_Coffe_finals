#include <iostream>
#include "Input.h"
#include "Menus.h"
using namespace std;

// Menu 7: admin panel with undo / redo (two stacks)
void adminMenu(Shop& s) {
    while (true) {
        cout << "\n--- ADMIN PANEL ---\n"
             << "  1. Add new product\n  2. Restock a product\n"
             << "  3. UNDO last action (stack pop)\n  4. REDO last undone action\n  0. Back\n"
             << "  (Undo history: " << s.undoStack.size() << ", redo: " << s.redoStack.size() << ")\n";
        int c = readInt("Choose: ", 0, 4);
        if (c == 0) return;

        if (c == 1) {
            string name = readLine("Product name: ");
            string cat = readLine("Category: ");
            string brand = readLine("Official partner brand: ");
            if (name.empty() || cat.empty() || brand.empty()) { cout << "  [!] No field may be empty.\n"; continue; }
            double price = readPrice("Price (PHP): ");
            int stock = readInt("Stock quantity: ", 0, 1000000);
            Product p{s.nextProductId++, name, cat, brand, price, stock};
            s.catalog.add(p);
            s.index.rebuild(s.catalog);
            s.undoStack.push({AdminAction::ADD_PRODUCT, p, p.id, 0});
            while (!s.redoStack.empty()) s.redoStack.pop();  // a new action clears redo history
            cout << "  [OK] Added product #" << p.id << ".\n";
        } else if (c == 2) {
            int id = readInt("Product ID: ", 1, 1000000);
            Product* p = s.findById(id);
            if (!p) { cout << "  [!] Product not found.\n"; continue; }
            int amt = readInt("Units to add: ", 1, 1000000);
            p->stockQuantity += amt;
            s.undoStack.push({AdminAction::RESTOCK, Product{}, id, amt});
            while (!s.redoStack.empty()) s.redoStack.pop();
            cout << "  [OK] " << p->name << " stock is now " << p->stockQuantity << ".\n";
        } else if (c == 3) {
            if (s.undoStack.empty()) { cout << "  Nothing to undo.\n"; continue; }
            AdminAction a = s.undoStack.top();
            if (a.type == AdminAction::ADD_PRODUCT) {
                s.catalog.removeById(a.productId);
                s.index.rebuild(s.catalog);
                cout << "  [UNDO] Removed product \"" << a.product.name << "\".\n";
            } else {
                Product* p = s.findById(a.productId);
                if (!p || p->stockQuantity < a.amount) {
                    cout << "  [!] Cannot undo: those units were already sold or the product is gone.\n";
                    continue;
                }
                p->stockQuantity -= a.amount;
                cout << "  [UNDO] Removed " << a.amount << " restocked units from " << p->name << ".\n";
            }
            s.undoStack.pop();
            s.redoStack.push(a);
        } else {
            if (s.redoStack.empty()) { cout << "  Nothing to redo.\n"; continue; }
            AdminAction a = s.redoStack.top();
            s.redoStack.pop();
            if (a.type == AdminAction::ADD_PRODUCT) {
                s.catalog.add(a.product);
                s.index.rebuild(s.catalog);
                cout << "  [REDO] Re-added product \"" << a.product.name << "\".\n";
            } else {
                Product* p = s.findById(a.productId);
                if (p) { p->stockQuantity += a.amount; cout << "  [REDO] Restocked " << p->name << " again.\n"; }
            }
            s.undoStack.push(a);
        }
    }
}

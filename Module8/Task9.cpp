//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <map>
#include <string>
#include <limits>



void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap) {
    auto it = inventoryMap.find(productId);
    if (it != inventoryMap.end()) {
        currentStock = it->second;
        return true;
    }
    currentStock = 0;
    return false;
}

void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
    if (inventoryMap.empty()) {
        std::cout << "The inventory is currently empty.\n";
    } else {
        for (const auto& pair : inventoryMap) {
            std::cout << "Product ID: " << pair.first << " | Stock: " << pair.second << "\n";
        }
    }

}



void addNewProduct(std::map<int, int>& inventory) {
    int productId, initialStock;

    std::cout << "\nEnter new Product ID: ";
    if (!(std::cin >> productId)) {
        std::cout << "Invalid input. Product ID must be an integer.\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(productId) > 0) {
        std::cout << "Product ID " << productId << " already exists. Please use the Restock option instead.\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter Initial Stock Quantity: ";
    if (!(std::cin >> initialStock) || initialStock < 0) {
        std::cout << "Invalid input. Stock must be a non-negative integer.\n";
        clearInputBuffer();
        return;
    }

    inventory[productId] = initialStock;
    std::cout << "Product " << productId << " added successfully with " << initialStock << " units.\n";
    clearInputBuffer();
}

void performSale(std::map<int, int>& inventory) {
    int productId, quantity;

    std::cout << "\nEnter Product ID to sell: ";
    if (!(std::cin >> productId)) {
        std::cout << "Invalid input.\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter Quantity to Sell: ";
    if (!(std::cin >> quantity) || quantity <= 0) {
        std::cout << "Invalid input. Quantity must be a positive integer.\n";
        clearInputBuffer();
        return;
    }

    int currentStock = 0;
    if (getProductStock(productId, currentStock, inventory)) {
        if (currentStock >= quantity) {
            inventory[productId] -= quantity;
            std::cout << "Sale successful. " << quantity << " units of Product " << productId << " sold.\n";
            std::cout << "Remaining stock: " << inventory[productId] << "\n";
        } else {
            std::cout << "Error: Insufficient stock. Only " << currentStock << " units available.\n";
        }
    } else {
        std::cout << "Error: Product ID " << productId << " not found in inventory.\n";
    }
    clearInputBuffer();
}

void performRestock(std::map<int, int>& inventory) {
    int productId, quantity;

    std::cout << "\nEnter Product ID to restock: ";
    if (!(std::cin >> productId)) {
        std::cout << "Invalid input.\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter Quantity to Restock: ";
    if (!(std::cin >> quantity) || quantity <= 0) {
        std::cout << "Invalid input. Quantity must be a positive integer.\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(productId) == 0) {
        std::cout << "Product ID " << productId << " not found. Adding as a new product.\n";
    }

    inventory[productId] += quantity;
    std::cout << "Restock successful. Product " << productId << " now has " << inventory[productId] << " units.\n";
    clearInputBuffer();
}

void checkProductStatus(const std::map<int, int>& inventory) {
    int productId, currentStock = 0;

    std::cout << "\nEnter Product ID to check: ";
    if (!(std::cin >> productId)) {
        std::cout << "Invalid input.\n";
        clearInputBuffer();
        return;
    }

    if (getProductStock(productId, currentStock, inventory)) {
        std::cout << "Product ID: " << productId << " | Current Stock: " << currentStock << "\n";
    } else {
        std::cout << "Product ID " << productId << " not found in inventory.\n";
    }
    clearInputBuffer();
}

void discontinueProduct(std::map<int, int>& inventory) {
    int productId;

    std::cout << "\nEnter Product ID to discontinue: ";
    if (!(std::cin >> productId)) {
        std::cout << "Invalid input.\n";
        clearInputBuffer();
        return;
    }

    if (inventory.erase(productId) > 0) {
        std::cout << "Product ID " << productId << " has been successfully removed from the inventory.\n";
    } else {
        std::cout << "Error: Product ID " << productId << " not found. Cannot discontinue.\n";
    }
    clearInputBuffer();
}



void ActionToPerform(std::map<int, int>& inventory) {
    int choice = -1;

    do {
        std::cout << "\n--- Inventory Management System ---\n";
        std::cout << "1. Add New Product\n";
        std::cout << "2. Perform Sale\n";
        std::cout << "3. Perform Restock\n";
        std::cout << "4. Check Product Status\n";
        std::cout << "5. Discontinue Product\n";
        std::cout << "6. Display All Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number from the menu.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                addNewProduct(inventory);
                break;
            case 2:
                performSale(inventory);
                break;
            case 3:
                performRestock(inventory);
                break;
            case 4:
                checkProductStatus(inventory);
                break;
            case 5:
                discontinueProduct(inventory);
                break;
            case 6:
                displayInventory(inventory, "Current Inventory Overview");
                break;
            case 0:
                std::cout << "Exiting menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option (0-6).\n";
                break;
        }
    } while (choice != 0);
}

int main() {
    std::map<int, int> productInventory;

    productInventory[101] = 50;
    productInventory[102] = 25;
    productInventory[103] = 100;
    productInventory[104] = 10;
    productInventory[105] = 75;

    displayInventory(productInventory, "Initial Inventory");
    ActionToPerform(productInventory);

    std::cout << "\nProgram execution completed. Goodbye!\n";

    return 0;
}
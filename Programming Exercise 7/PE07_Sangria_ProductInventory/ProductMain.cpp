// Program created by Prescious Apple D. Sangria
// BSCS - 1
// Programming Exercise 07

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "ProductInventory.h"

using namespace std;


// This function ensures that there is no empty input from the user
string validateInput(string input, string attribute) {
    do {
        if (input == "") {
            cout << "Please Input " << attribute << endl;
            cout << "Enter " << attribute << ": ";
            getline(cin, input);
        }
    } while (input == "");
    return input;
}

// This function ensures that only positive float numbers will be accepted
float validatePositiveFloatInput(string attribute) {
    float value;
    while (true) {
        cout << "Enter " << attribute << ": ";
        if (!(cin >> value) || value <= 0) {
            cout << "Invalid input. Please enter a valid positive floating-point number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

// This function ensures that only positive integers will be accepted

int validatePositiveIntegerInput(string attribute) {
    int value;
    while (true) {
        cout << "Enter " << attribute << " :";
        if (!(cin >> value) || value <= 0 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a valid positive integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
	// Variable Declaration
    string name;
    string brand;
    float price;
    int quantity;
    string description;
    string size;
    string color;
    string category;
    string material;
    string model;
    string warranty;
    string technicalSpecification;

	// User-input
    cout << "Product Inventory" << endl;
    cout << "=================================================" << endl;

    cout << "Enter Product Name: ";
    getline(cin, name);
    name = validateInput(name, "Product Name");

    cout << "Enter Brand Name: ";
    getline(cin, brand);
    brand = validateInput(brand, "Brand Name");

	price = validatePositiveFloatInput("Price");

	quantity = validatePositiveIntegerInput("Quantity");
    
    cout << "Enter Description: ";
    getline(cin, description);
    description = validateInput(description, "Description");

    cout << "Enter Size: ";
    getline(cin, size);
    size = validateInput(size, "Size");

    cout << "Enter Color: ";
    getline(cin, color);
    color = validateInput(color, "Color");

    do {
        cout << "Choose category: " << endl;
        cout << "[1] Clothing  [2] Electronics" << endl;
        cout << "Choice: ";
        getline(cin, category);
        category = validateInput(category, "Category");

        if (category != "1" && category != "2") {
            cout << "Invalid input. Please type again" << endl;
        }
    } while (category != "1" && category != "2");

	// Setting details for clothing products 
    if (category == "1") {
    	// Clothing instance
        Clothing clothing;
        
        // Setting values
        clothing.setName(name);
        clothing.setBrand(brand);
        clothing.setPrice(price);
        clothing.setQuantity(quantity);
        clothing.setDescription(description);
        clothing.setSize(size);
        clothing.setColor(color);
        clothing.setCategory("Clothing");
        cout << "Enter Material: ";
        getline(cin, material);
        material = validateInput(material, "Material");
        clothing.setMaterial(material);
        
        // Display output
        cout << "\n\n\n=================================================" << endl;
        cout << "PRODUCT SUMMARY: " << endl;
        cout << "Product Name: " << clothing.getName() << endl;
        cout << "Brand: " << clothing.getBrand() << endl;
        cout << "Price: " << clothing.getPrice() << endl;
        cout << "Quantity: " << clothing.getQuantity() << endl;
        cout << "Description: " << clothing.getDescription() << endl;
        cout << "Size: " << clothing.getSize() << endl;
        cout << "Color: " << clothing.getColor() << endl;
        cout << "Category: " << clothing.getCategory() << endl;
        cout << "Material: " << clothing.getMaterial() << endl;
    } else if (category == "2") {
    	// Electronics instance
        Electronics electronics;
        
        // Setting electronics
        electronics.setName(name);
        electronics.setBrand(brand);
        electronics.setPrice(price);
        electronics.setQuantity(quantity);
        electronics.setDescription(description);
        electronics.setSize(size);
        electronics.setColor(color);
        electronics.setCategory("Electronics");
        
        cout << "Enter Model: ";
        getline(cin, model);
        model = validateInput(model, "Model");
        electronics.setModel(model);
        
        cout << "Enter Warranty: ";
        getline(cin, warranty);
        warranty = validateInput(warranty, "Warranty");
        electronics.setWarranty(warranty);
        
        cout << "Enter Technical Specification: ";
        getline(cin, technicalSpecification);
        technicalSpecification = validateInput(technicalSpecification, "Technical Specification");
        electronics.setTechnicalSpecification(technicalSpecification);
        
        // Display Electronics Details
        cout << "\n\n\n=================================================" << endl;
        cout << "PRODUCT SUMMARY: " << endl;
        cout << "Product Name: " << electronics.getName() << endl;
        cout << "Brand: " << electronics.getBrand() << endl;
        cout << "Price: " << electronics.getPrice() << endl;
        cout << "Quantity: " << electronics.getQuantity() << endl;
        cout << "Description: " << electronics.getDescription() << endl;
        cout << "Size: " << electronics.getSize() << endl;
        cout << "Color: " << electronics.getColor() << endl;
        cout << "Category: " << electronics.getCategory() << endl;
        cout << "Model: " << electronics.getModel() << endl;
        cout << "Warranty: " << electronics.getWarranty() << endl;
        cout << "Technical Specification: " << electronics.getTechnicalSpecification() << endl;
    }

    return 0;
}



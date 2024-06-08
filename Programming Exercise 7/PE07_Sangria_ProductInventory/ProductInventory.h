#ifndef PRODUCTINVENTORY_H
#define PRODUCTINVENTORY_H

#include <string>

using namespace std;

class Product {
private:
    string name;
    string brand;
    float price;
    int quantity;
    string description;
    string size;
    string color;
    string category;

public:
    // Constructor
    Product() {}

    // Setter methods
    void setName(string newName) { name = newName; }
    void setBrand(string newBrand) { brand = newBrand; }
    void setPrice(float newPrice) { price = newPrice; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setDescription(string newDescription) { description = newDescription; }
    void setSize(string newSize) { size = newSize; }
    void setColor(string newColor) { color = newColor; }
    void setCategory(string newCategory) { category = newCategory; }

    // Getter methods
    string getName() { return name; }
    string getBrand() { return brand; }
    float getPrice() { return price; }
    int getQuantity() { return quantity; }
    string getDescription() { return description; }
    string getSize() { return size; }
    string getColor() { return color; }
    string getCategory() { return category; }
};

class Electronics : public Product {
private:
    string model;
    string warranty;
    string technical_specification;

public:
    Electronics() {}

    void setModel(string newModel) { model = newModel; }
    void setWarranty(string newWarranty) { warranty = newWarranty; }
    void setTechnicalSpecification(string newTechnicalSpecification) { technical_specification = newTechnicalSpecification; }

    string getModel() { return model; }
    string getWarranty() { return warranty; }
    string getTechnicalSpecification() { return technical_specification; }
};

class Clothing : public Product {
private:
    string material;

public:
    Clothing() {}

    void setMaterial(string newMaterial) { material = newMaterial; }
    string getMaterial() { return material; }
};

#endif // PRODUCTINVENTORY_H


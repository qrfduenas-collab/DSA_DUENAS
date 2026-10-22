#include <iostream>
#include <string>

class Grocery {
private:
    std::string name;
    double price;
    int quantity;

public:
    
    Grocery(std::string ralph = "", double prc = 0, int q = 0) {
        name = ralph;
        price = prc;
        quantity = q;
    }

    Grocery(const Grocery &z) {
        name = z.name;
        price = z.price;
        quantity = z.quantity;
    }

    Grocery& operator=(const Grocery &g) {
        if (this != &g) {
            name = g.name;
            price = g.price;
            quantity = g.quantity;
        }
        return *this;
    }

    ~Grocery() {}

    double calculateSum() {
        return price * quantity;
    }

    virtual void display() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Total Price:  " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total amount: " << calculateSum() << std::endl;
    }
};

class Fruit : public Grocery {
public:
    Fruit(std::string ralph, double prc, int q) : Grocery(ralph, prc, q) {}

    void display() override {
        std::cout << "[Fruit]" << std::endl;
        Grocery::display();
        std::cout << std::endl;
    }
};

class Vegetable : public Grocery {
public:
    Vegetable(std::string ralph, double prc, int q) : Grocery(ralph, prc, q) {}

    void display() override {
        std::cout << "Vegetables:" << std::endl;
        Grocery::display();
        std::cout << std::endl;
    }
};

double TotalSum(Grocery* list[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] != nullptr)
            total += list[i]->calculateSum();
    }

    return total;
}

int main() {

    Grocery* GroceryList[4];

    GroceryList[0] = new Fruit("Watermelom", 20, 17);
    GroceryList[1] = new Fruit("Lychee", 30, 18);
    GroceryList[2] = new Vegetable("Sayote", 60, 12);
    GroceryList[3] = new Vegetable("Carrots", 50, 10);

    std::cout << "Andrei's grocery list\n\n";

    for (int i = 0; i < 4; i++) {
        GroceryList[i]->display();
    }

    std::cout << "Total amount: " << TotalSum(GroceryList, 4) << std::endl;

    std::cout << "\nDeleting Carrots\n";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "\nUpdated Grocery List\n\n";

    for (int i = 0; i < 4; i++) {
        if (GroceryList[i] != nullptr)
            GroceryList[i]->display();
    }

    std::cout << "New Total amount: " << TotalSum(GroceryList, 4) << std::endl;

    for (int i = 0; i < 4; i++) {
        delete GroceryList[i];
    }

    return 0;
}
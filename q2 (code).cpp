#include <iostream>
#include <string>

class Product {
private:
    int productId;
    std::string productName;
    double price;

public:
    Product(int id, const std::string& name, double p) : productId(id), productName(name), price(p) {}

    void displayDetails() const {
        std::cout << "Product ID: " << productId << "\nName: " << productName << "\nPrice: $" << price << std::endl;
    }

    double getPrice() const {
        return price;
    }
};

class ShoppingCart {
private:
    Product** products;
    int numOfProducts;
    const int maxSize;

public:
    ShoppingCart(int maxSize) : maxSize(maxSize), numOfProducts(0) {
        products = new Product*[maxSize];
    }

    ~ShoppingCart() {
        for (int i = 0; i < numOfProducts; ++i) {
            delete products[i];
        }
        delete[] products;
    }

    void addProduct(Product* product) {
        if (numOfProducts < maxSize) {
            products[numOfProducts++] = product;
        } else {
            std::cout << "Cart is full!" << std::endl;
        }
    }

    void displayAllProducts() const {
        std::cout << "Products in the cart:" << std::endl;
        for (int i = 0; i < numOfProducts; ++i) {
            products[i]->displayDetails();
            std::cout << std::endl;
        }
    }

    double calculateTotalCost() const {
        double total = 0.0;
        for (int i = 0; i < numOfProducts; ++i) {
            total += products[i]->getPrice();
        }
        return total;
    }
};

class User {
private:
    int userId;
    ShoppingCart* cart;

public:
    User(int id) : userId(id), cart() {}

    void assignShoppingCart(ShoppingCart* shoppingCart) {
        cart = shoppingCart;
    }

    void displayDetails() const {
        std::cout << "User ID: " << userId << std::endl;
    }

    ShoppingCart* getShoppingCart() const {
        return cart;
    }
};

int main() {
    
    Product* p1 = new Product(1, "Item 1", 10.99);
    Product* p2 = new Product(2, "Item 2", 5.99);
    Product* p3 = new Product(3, "Item 3", 7.50);

    
    ShoppingCart* cart = new ShoppingCart(5);
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(p3);

    
    User user1(101);
    user1.assignShoppingCart(cart);

    
    user1.displayDetails();

    
    user1.getShoppingCart()->displayAllProducts();

    
    std::cout << "Total cost: $" << user1.getShoppingCart()->calculateTotalCost() << std::endl;

    
    delete p1;
    delete p2;
    delete p3;
    delete cart;

    return 0;
}


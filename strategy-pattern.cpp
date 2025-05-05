//Dones, Kyle Gabriel M.
// IT2A
#include <iostream>
using namespace std;

// base class
class DiscountStrategy {
public:
    virtual double calculateDiscount(double price) = 0; // pure virtual function
};

//derived class for no discount
class NoDiscount : public DiscountStrategy {
    private:
        double discount = 0.0;
    public:
        double calculateDiscount(double price) override {
            return price - (price * discount);
        }
};

//derived class for 10% discount
class TenPercentDiscount : public DiscountStrategy {
    private:
        double discount = 0.1;
    public:
        double calculateDiscount(double price) override {
            return price - (price * discount);
        }

};

//derived class for 20% discount
class TwentyPercentDiscount : public DiscountStrategy {
    private:
        double discount = 0.2;
    public:
        double calculateDiscount(double price) override {
            return price - (price * discount);
        }

};

// Cart class that uses the strategy pattern
class Cart{
    private:
        DiscountStrategy* discountStrategy;
    public:
    Cart(DiscountStrategy* discountStrategy) : discountStrategy(discountStrategy) {}
    double calculatePrice(double price) {
        return discountStrategy->calculateDiscount(price);
    }
    void setDiscountStrategy(DiscountStrategy* discountStrategy) {
        this->discountStrategy = discountStrategy;
    }
    ~Cart() {
        delete discountStrategy; // free memory
    }

};


int main() {

    double price;
    int discountType;

    cout << "Enter the price of the item: ";
    cin >> price;
    cout << "Select discount type (\n1: No Discount, \n2: 10% Discount, \n3: 20% Discount): ";
    cin >> discountType;

    if(discountType == 1){
        NoDiscount* noDiscount = new NoDiscount();
        Cart cart(noDiscount);
        cout<<"No discount applied." << endl;
        cout << "Final price"<< price << "Pesos" << endl;
    } else if(discountType == 2){
        TenPercentDiscount* tenPercentDiscount = new TenPercentDiscount();
        Cart cart(tenPercentDiscount);
        cout << "Original price: " << price << "Pesos" << endl;
        cout << "Discount applied: 10%" << endl;
        cout << "Amount saved: " << price - cart.calculatePrice(price) << "Pesos" << endl;
        cout << "Final price after discount: " << cart.calculatePrice(price) << "Pesos" << endl;
    } else if(discountType == 3){
        TwentyPercentDiscount* twentyPercentDiscount = new TwentyPercentDiscount();
        Cart cart(twentyPercentDiscount);
        cout << "Original price: " << price << "Pesos"<< endl;
        cout << "Discount applied: 20%" << endl;
        cout << "Amount saved: " << price - cart.calculatePrice(price) << "Pesos" << endl;
        cout << "Final price after discount: " << cart.calculatePrice(price) << "Pesos" << endl;
    } else {
        cout << "Invalid discount type selected." << endl;
    }
    
    return 0;
}

// Dones, Kyle Gabriel M.
// IT2A
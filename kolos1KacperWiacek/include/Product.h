#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>


class Product
{
    public:
        Product();
        Product(std::string _name, float _price, int _quantity, std::string _studentID);
        virtual ~Product();
        void setName(std::string s);
        void setPrice(float p);
        void setQuantity(int q);
        std::string getName();
        float getPrice();
        int getQuantity();
        void info();
    private:
        std::string name;
        float price;
        int quantity;
        std::string studentID;
};

#endif // PRODUCT_H

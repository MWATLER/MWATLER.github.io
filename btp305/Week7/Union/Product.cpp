// Structs with Unions
 // struct_union.cpp

#include <iostream>
#include <cstring>

enum class ProductId { sku, upc };

typedef struct {
    ProductId id; // enumeration type holds a symbol
    union { // some have skus, some upcs
        int  sku;
        char upc[14];
    } code;
} Product;

int main() {
    Product p[2];

    p[0].id = ProductId::sku;
    p[0].code.sku = 4789;
    p[1].id = ProductId::upc;
    strcpy_s(p[1].code.upc, 14, "0360002607555");

    for (int i = 0; i < 2; i++) {
        switch (p[i].id) {//the switch statement is one block of code
        case ProductId::sku:
            std::cout << p[i].code.sku << std::endl;
            break;
        case ProductId::upc:
            std::cout << p[i].code.upc << std::endl;
            break;
        }
    }
}
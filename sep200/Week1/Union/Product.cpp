// Structs with Unions
 // struct_union.cpp

#include <iostream>
#include <cstring>

enum ProductId { sku, upc };

typedef struct {
    ProductId id; // enumeration type holds a symbol
    union { // some have skus, some upcs
        int  sku;
        char upc[14];
    } code;
} Product;

int main() {
    Product p[2];

    p[0].id = sku;
    p[0].code.sku = 4789;
    p[1].id = upc;
    strcpy_s(p[1].code.upc, 14, "0360002607555");

    for (int i = 0; i < 2; i++)
        switch (p[i].id) {
        case sku:
            std::cout << p[i].code.sku << std::endl;
            break;
        case upc:
            std::cout << p[i].code.upc << std::endl;
            break;
        }
}
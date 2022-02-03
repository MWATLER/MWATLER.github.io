//Product.h - header file for product

#define BUFLEN 128

struct ProductInfo {//we are creating a new type called "struct ProductInfo"
	char product[BUFLEN];
	int sku;
	double price;
};
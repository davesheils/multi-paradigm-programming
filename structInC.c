#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product {
	char* name;
	double price;
};

struct ProductStock {
	struct Product product;
	int quantity;
};

struct Shop {
	double cash;
	struct ProductStock stock [20];

};

struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList [10];
	};

void printProduct (struct Product p){
	printf("-------------------\n");
	printf("PRODUCT NAME: %s \n PRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------------\n");
}

void printCustomer(struct Customer c){
	printf("-------------------\n");
	printf("CUSTOMER NAME: %s \n CUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	printf("-------------------\n");

};

int main(void) {
	struct Customer David = { "Jack", 100.0 };
	struct Product Bread = {"Sourdough", 1.50};
	struct ProductStock BreadStock = {Bread, 20};
	
	// printf("my name is %s\n", David.name);
	// printf("The bread type is %s.\n The cost is %.2f\n",Bread.name,Bread.price);
	// %f for floating point number. the .2 specifies 2 decimal places
	printf("There are %d %s in stock.\n",BreadStock.quantity, BreadStock.product.name);

	printProduct(Bread);
	printCustomer(David);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

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
	int index;

};

struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList [10]; // array with 10 items
	int index; // keeps track of number of items in shoppingList
	};

void printProduct (struct Product p){
	printf("-------------------\n");
	printf("PRODUCT NAME: %s \n PRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------------\n");
}

struct Shop createAndStockShop()
{
	// read stock.csv line by line
	// for each line, create a stuct productStock
	struct Shop shop = {200};
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
	// fp = file pointer
	
	int lineNumber = 1;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (lineNumber == 1)
		{
			double openingBalance = atof(line);
			// printf("OPENING BALANCE IS %.2f\n", openingBalance);
			shop.cash = openingBalance;
			// printf("", read);
		}
		else
		{
			// break line into fields using string tokeniser
			char *n = strtok(line, ",");
		char *p = strtok(NULL, ",");
		char *q = strtok(NULL, ",");
		int quantity = atoi(q);
		double price = atof(p);
		char *name = malloc(sizeof(char) * 50);
		strcpy(name, n);
		struct Product product = { name, price };
		struct ProductStock stockItem = { product, quantity };
		shop.stock[shop.index++] = stockItem;
		// printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
		}
		lineNumber = lineNumber + 1;
	}
	return shop;
}


void printCustomer(struct Customer c){
	
	printf("CUSTOMER NAME: %s \n CUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	
	for (int i = 0; i < c.index; i++)
	{
		printProduct(c.shoppingList[i].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
		printf("The cost to %s will be %.2f EUR.\n",c.name, c.shoppingList[i].quantity * c.shoppingList[i].product.price);
	}
	printf("-------------------\n");
};

void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
	}
}


int main(void) {
	// struct Customer David = { "David", 100.0 };
	// struct Product Bread = {"Sourdough", 1.50};
	// struct Product Beer  = {"Guinness", 2.49};

	// struct ProductStock BreadStock = {Bread, 20};
	// struct ProductStock BeerStock = {Beer, 5};

	// add item to customer list
	// David.shoppingList[David.index++] = BreadStock; //puts it at the index, which is then incremented
	// David.shoppingList[David.index++] = BeerStock;
	
	// printf("my name is %s\n", David.name);
	// printf("The bread type is %s.\n The cost is %.2f\n",Bread.name,Bread.price);
	// %f for floating point number. the .2 specifies 2 decimal places
	// printf("There are %d %s in stock.\n",BreadStock.quantity, BreadStock.product.name);

	// printProduct(Bread);
	// printCustomer(David);

	struct Shop shop = createAndStockShop();
	printShop(shop);
	return 0;
}
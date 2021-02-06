#include"Basket.h"
#include <iostream>

int main(){
    Basket bsk;
    bsk.add_item(Quote("123",45));
    bsk.add_item(Bulk_quote("345",45,3,0.15));
    bsk.total_receipt(std::cout);
}
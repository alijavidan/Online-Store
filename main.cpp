#include <iostream>
#include <vector>
#include "Buyer.h"
#include "Seller.h"
#include "Goods.h"
#include "functions.h"

using namespace std;

int main ( ) {

  string x;

  vector<Buyer*> buyer_ins;
  vector<Seller*> seller_ins;
  vector<Goods*> g;
  vector< vector<string> > db;
  int factor_number = 1;
  
  seller_ins.push_back ( new Seller ( "Shop Center Shop_Center 21 0" ) );

  while ( cin >> x ) {

    menu ( x , buyer_ins , seller_ins , g , db , factor_number );

  }

}
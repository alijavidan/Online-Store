#include "Seller.h"

Seller::Seller ( string str ) {

  stringstream iss ( str );

  string x;

  iss >> x;
  first_name = x;

  iss >> x;
  last_name = x;

  iss >> x;
  username = x;

  iss >> x;      
  phone_number = x;

  iss >> x;      
  money = str_to_int(x);

}

string Seller::get_username ( ) { return username; }
void Seller::set_money ( int arg  ) { money+= arg; }
int Seller::get_money ( ) { return money; }
void Seller::add_money ( int arg ) { money += arg; }

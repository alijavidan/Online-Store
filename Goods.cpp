#include "Goods.h"

Goods::Goods ( string str ) {

  stringstream iss ( str );

  string x;

  iss >> x;
  seller_username = x;

  iss >> x;
  goods_name = x;

  iss >> x;
  goods_price = str_to_int(x);

  iss >> x;      
  goods_count = str_to_int(x);

  count_offers = 0;

  special_counts = 0;

  buys = 0;

}

void Goods::set_as_special ( int c ) { special_counts += c; }

void Goods::rem_as_special ( int c ) { special_counts -= c; }

int Goods::get_special_counts (  ) { return special_counts; }
void Goods::set_count ( int arg ) { goods_count += arg; }
string Goods::get_name () { return goods_name; }
int Goods::get_count () { return goods_count; }

int Goods::get_price () {

  if ( count_offers > 10 )
    return ( goods_price * 0.9 );
    else if ( special_counts > 0 ) 
      return ( goods_price * 0.9 );
      else
        return goods_price;

}

string Goods::get_seller_username () { return seller_username; }

void Goods::decrese_count ( int arg0 , int arg1 ) {

  special_counts -= arg1;
  goods_count -= arg0;

}

bool Goods::ifcountoffers10 ( ) {

  if ( count_offers > 10 )
    return true;
    else 
      return false;

}

void Goods::increase_count_offers ( ) { count_offers++; }
void Goods::set_offeres_usernames ( string str ) { offerers_usernames.push_back ( str ); }
vector<string> Goods::get_offeres_usernames ( ) { return offerers_usernames; }
int Goods::get_buys ( ) { return buys; }
void Goods::increase_buys ( ) { buys++; }

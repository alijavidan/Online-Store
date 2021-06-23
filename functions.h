#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Seller.h"
#include "Buyer.h"
#include "Goods.h"
#include "caster.h"

using namespace std;

void swap ( string *xp , string *yp );
void sort ( vector<string> &out );
void add_user ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins );
void store ( string buyer_username , int s , vector<string> v , vector< vector<string> > &db );
bool if_is_30 ( string str , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void add_goods ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number );
void search_goods ( vector<Goods*> &g );
void factor ( string buyer_username , vector<string> out , int sum , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number );
void buy ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number );
void sale ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void remove_special ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void add_special ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void search_bestseller ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) ;
void search_sale ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void add_money ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void print_factor ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void request ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number );
void print_request ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db );
void menu ( string str , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number );

#endif
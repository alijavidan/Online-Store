#ifndef GOODS_H
#define GOODS_H

#include <vector>
#include <iostream>
#include <sstream>
#include "caster.h"

using namespace std;

class Goods {

  public :

    Goods ( string str );
    void set_as_special ( int c );
    void rem_as_special ( int c );
    int get_special_counts (  );
    void set_count ( int arg );
    string get_name ();
    int get_count ();
    int get_price ();
    string get_seller_username ();
    
    void decrese_count ( int arg0 , int arg1 );
    bool ifcountoffers10 ( );
    
    void increase_count_offers ( );
    void set_offeres_usernames ( string str );
    vector<string> get_offeres_usernames ( );
    int get_buys ( );
    void increase_buys ( );

  private : 

    string seller_username , goods_name;
    int goods_price , goods_count;
    int count_offers;
    vector<string> offerers_usernames;
    int special_counts;
    int buys;

};

#endif
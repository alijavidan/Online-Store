#ifndef SELLER_H
#define SELLER_H

#include <iostream>
#include <sstream>
#include "caster.h"

using namespace std;

class Seller {

  public :

    Seller ( string str );
    string get_username ( );
    void set_money ( int arg  );
    int get_money ( );
    void add_money ( int arg );

  private :
    
    string username;
    string first_name;
    string last_name;
    string phone_number;
    int money;

};

#endif

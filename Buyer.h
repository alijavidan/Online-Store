#ifndef BUYER_H
#define BUYER_H

#include <vector>
#include <iostream>
#include <sstream>
#include "caster.h"

using namespace std;

class Buyer {

  public :

    Buyer ( string str );
    string get_username ( void );
    string get_first_name ( );
    string get_last_name ( );
    string get_phone_number ( );
    int get_money ( );
    void set_money ( int arg  );
    void add_money ( int arg );
    
    void set_request ( string request );
    vector<string> get_requests ( );
    void req_pop ( );
    
  private : 

    string first_name;
    string last_name;
    string username;
    string phone_number;
    int money;
    vector<string> requests;
    vector<string> requests_names;

};

#endif

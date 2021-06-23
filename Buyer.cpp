#include "Buyer.h"

Buyer::Buyer ( string str ) {

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

string Buyer::get_username ( void ) { return username; }
string Buyer::get_first_name ( ) { return first_name; }
string Buyer::get_last_name ( ) { return last_name; }
string Buyer::get_phone_number ( ) { return phone_number; }
int Buyer::get_money ( ) { return money; }
void Buyer::set_money ( int arg  ) { money -= arg; }
void Buyer::add_money ( int arg ) { money += arg; }

void Buyer::set_request ( string request ) {

  if ( request[request.size()-1] == '$' ) {
    requests.push_back ( request );
    request.pop_back ( );
    requests_names.push_back ( request );
    } else
     if ( request[request.size()-1] == '@' ) {
    request.pop_back ();
    requests.erase ( requests.begin ( ) + str_to_int(request) );

    string str = requests[requests.size()-1];
    str.pop_back ();

    for ( int i = 0; i < requests_names.size ( ); i++ )
      if ( str == requests_names[i] ) {
        requests.pop_back ();
        requests_names.erase ( requests_names.begin ( ) + i );
      }
    
    } else
    requests.push_back ( request );

}

vector<string> Buyer::get_requests ( ) { return requests; }
void Buyer::req_pop ( ) { 
  
  requests.pop_back ( );

  string str = requests[requests.size()-1];
  str.pop_back ();
  
  for ( int i = 0; i < requests_names.size ( ); i++ )
    if ( str == requests_names[i] ) {
      requests.pop_back ();
      requests_names.erase ( requests_names.begin ( ) + i );
    }
}

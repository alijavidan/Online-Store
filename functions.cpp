#include "functions.h"

void swap ( string *xp , string *yp ) { 

    string temp = *xp; 
    *xp = *yp; 
    *yp = temp; 

} 

void sort ( vector<string> &out ) {

  int n = out.size ( );

  for ( int i = 0; i < n-1; i++)       
    for ( int j = 0; j < n-i-1; j++)   {
         
      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;

      if ( x1 > x2 ) 
        swap ( &out[j] , &out[j+1] ); 
      
    }

  for ( int i = 0; i < n-1; i++ )       
    for ( int j = 0; j < n-i-1; j++ )   {

      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;

      if ( x1 == x2 ) { 
        iss1 >> x1;
        iss2 >> x2;
        if ( str_to_int(x1) > str_to_int(x2) ) 
          swap ( &out[j] , &out[j+1] ); 
      }

    }

  for ( int i = 0; i < n-1; i++)       
    for ( int j = 0; j < n-i-1; j++)   {
           
      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4;

      iss1 >> x1 >> x3;
      iss2 >> x2 >> x4;

      if ( x1 == x2 && x3 == x4 ) {

        iss1 >> x1;
        iss2 >> x2;

        if ( str_to_int(x1) > str_to_int(x2) ) 
          swap ( &out[j] , &out[j+1] ); 

      }

    }

  for ( int i = 0; i < n-1; i++)       
    for ( int j = 0; j < n-i-1; j++)   {
         
      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4,x5,x6;

      iss1 >> x1 >> x3 >> x5;
      iss2 >> x2 >> x4 >> x6;

      if ( x1 == x2 && x3 == x4 && x5 == x6 ) {

      iss1 >> x1;
      iss2 >> x2;

      if ( x1 > x2 ) 
        swap ( &out[j] , &out[j+1] ); 

      }
    }
}

void add_user ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins ) {

  string str;

  getline ( cin , str );

  stringstream iss ( str );

  string x , y;
  iss >> x >> x >> x >> y >> y >> y;

  bool b;
  if ( y == "buyer" ) {

    b = false; 
    for ( int i = 0; i < buyer_ins.size ( ); i++ )
      if ( buyer_ins[i] -> get_username ( ) == x )
        b = true;
      
      if ( b == false ) {
        buyer_ins.push_back ( new Buyer ( str ) );
        cout << "Command Ok\n";
      }
      else 
        cout << "Command Failed\n";

  }

  else if ( y == "seller" ) {
    b = false;
    for ( int i = 0; i < seller_ins.size ( ); i++ )    
      if ( seller_ins[i] -> get_username ( ) == x )
        b = true;
      
      if ( b == false ) {
        seller_ins.push_back ( new Seller ( str ) );
        cout << "Command Ok\n";
      }
      else
        cout << "Command Failed\n";

  }    
} 

void store ( string buyer_username , int s , vector<string> v, vector< vector<string> > &db ) {

  v.push_back ( buyer_username );
  v.push_back ( to_string(s) );
  db.push_back ( v );
    
}


bool if_is_30 ( string str , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  vector< vector<string> > v;

  for ( int i = 0; i < g.size ( ); i++ ) {

    bool b = false;  
    for ( int j = 0; j < v.size ( ); j++ )      
      if ( g[i] -> get_name ( ) == v[j][0] ) {
        v[j][1] = to_string ( str_to_int ( v[j][1] ) + g[i] -> get_count ( ) );
        b = true;
      }

    if ( b == false ) {
      vector<string> p;
      p.push_back ( g[i] -> get_name () );
      p.push_back ( to_string(g[i] -> get_count ()) );
      v.push_back ( p );
    }
  
  }

  for ( int k = 0; k < v.size ( ); k++ )
    if ( v[k][0] == str ) 
      if ( str_to_int(v[k][1]) >= 30 ) 
        return true;
        else 
        return false;        

}

void add_goods ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number ) { 

  string str;
  getline ( cin , str );

  stringstream iss ( str );

  string seller_username , goods_name , buyer_username;
  int goods_price , goods_count;

  iss >> seller_username >> goods_name >> goods_price >> goods_count;

  bool b = false;
  for ( int i = 0; i < g.size(); i++  )
    if ( seller_username == g[i] -> get_seller_username () &&  goods_name == g[i] -> get_name () && goods_price == g[i] -> get_price () ) {
      b = true;
      g[i] -> set_count ( goods_count );
    }
  
  if ( b == false )
    g.push_back ( new Goods ( str ) );


  int sum = 0 , calc;
  vector<string> v;
  vector<string> vv;
  vector<string> myvec;
  for ( int roll = 0; roll < buyer_ins.size (); roll++ ) {
    myvec = buyer_ins[roll] -> get_requests ();
    for ( int rollp = 0; rollp <  myvec.size (); rollp++ ) {

        if ( myvec[rollp][myvec[rollp].size()-1] == '$' )
          continue;
        stringstream iss ( myvec[rollp] );

        iss >> goods_name >> goods_count >> seller_username;

                for ( int i = 0; i < g.size ( ); i++ )
        if ( g[i] -> get_name ( ) == goods_name && g[i] -> get_seller_username () == seller_username ) {
        
          for ( int j = 0; j < buyer_ins.size (); j++ )
          if ( buyer_ins[j] -> get_username () == buyer_ins[roll] -> get_username () ) {

          int t = g[i] -> get_special_counts () , temp = g[i] -> get_count (); 
          //
          int  special_price = g[i] -> get_price ();
          //
          calc = 0;
          vv.clear ();
          if ( g[i] -> get_special_counts () >= goods_count ) {
                calc = goods_count * g[i] -> get_price ();
                //
                vv.push_back ( goods_name + " " + to_string(g[i]->get_special_counts()) + " " + to_string ( g[i] -> get_price () ) + " " + seller_username + " " + to_string ( calc ) );
                //
                g[i] -> decrese_count ( goods_count , goods_count );
          } else {
            int k = 1;
            for ( ; k <= t; k++ ) {
              calc += g[i] -> get_price (); 
              g[i] -> decrese_count ( 1 , 1 );
            }
            //
            if ( k != 1 )
              vv.push_back ( goods_name + " " + to_string(t) + " " + to_string ( special_price ) + " " + seller_username + " " + to_string ( calc ) );
            int temp_calc = calc;
            //    
            int countthis = 0; 
            while ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) && goods_count - (k-1) - countthis > 0 ) {
              calc += (int)( g[i] -> get_price () * 0.9 );
              g[i] -> decrese_count ( 1 , 1 );
              countthis++;
            }
            //
            
            if ( countthis != 0 && k != 1  ) {

              vv.pop_back ( );
              vv.push_back ( goods_name + " " + to_string(t+countthis) + " " + to_string ( special_price ) + " " + seller_username + " " + to_string ( calc ) );
            
            } else if ( countthis != 0 )
                vv.push_back ( goods_name + " " + to_string(countthis) + " " + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + seller_username + " " + to_string ( calc - temp_calc ) );
              
            temp_calc = calc;
            //
            calc += ( goods_count - (k-1) - countthis ) * g[i] -> get_price ();
            g[i] -> decrese_count ( goods_count - (k-1) - countthis , 0 );
            //
            if ( goods_count - (k-1) - countthis != 0 )
              vv.push_back ( goods_name + " " + to_string(goods_count - (k-1) - countthis) + " " + to_string ( g[i] -> get_price () ) + " " + seller_username + " " + to_string ( calc - temp_calc ) );
            //
          }
        
          if ( calc <= buyer_ins[j] -> get_money () ) {

          if ( temp >= goods_count ) {
          
          sum += calc;

          for ( int j = 0; j < buyer_ins.size (); j++ )
            if ( buyer_ins[j] -> get_username () == buyer_ins[roll] -> get_username () ) {

              buyer_ins[j] -> set_money ( calc );
              string pass = to_string(rollp) + "@";
              buyer_ins[j] -> set_request ( pass );
            
            }

          for ( int j = 0; j < seller_ins.size (); j++ )
            if ( seller_ins[j] -> get_username () == seller_username )
              seller_ins[j] -> set_money (  calc );

            for ( int j = 0; j < vv.size (); j++ )
              v.push_back ( vv[j] );

          g[i] -> increase_buys ();

        }

          if ( g[i] -> get_count () == 0 ) 
            g.erase ( g.begin ( ) + i );
        }

        }

        }

      if ( v.size ( ) != 0 ) {

        factor ( buyer_ins[roll] -> get_username () , v , sum , buyer_ins , seller_ins , g , db , factor_number );
        store ( buyer_ins[roll] -> get_username () , sum , v , db );
                
        seller_ins[0] -> set_money ( (int)(sum*0.05) );

        }

      }
      }

}

void search_goods ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  string x1,x2;
  cin >> x1 >> x2;

  vector<string> out;

  for ( int i = 0; i < g.size( ); i++ )
    if ( g[i] -> get_name () == x1 && g[i] -> get_count ()  >= str_to_int(x2) ) {

      if ( g[i] -> ifcountoffers10 () )
          out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_count ()) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
          
          else if (  g[i] -> get_special_counts () > 0 ) {
            out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_special_counts ()) + " "  + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
            out.push_back ( g[i] -> get_name () + " " + to_string ( g[i] -> get_count () - g[i] -> get_special_counts () ) + " "  + to_string ( (int)(g[i] -> get_price ()*1.1) ) + " " + g[i] -> get_seller_username () );
            }
    
            else if ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) ) 
              out.push_back ( g[i] -> get_name () + " " + to_string ( g[i] -> get_count ()) + " "  + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + g[i] -> get_seller_username () );

              else       
                out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
    
    }

  sort ( out );

  for ( int i = 0; i < out.size( ); i++ )
    cout << i+1 << ". " << out[i] << '\n';

}

void factor ( string buyer_username , vector<string> out , int sum , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number ) {

  cout << "Factor number " << factor_number << '\n';

  factor_number ++;

  for ( int i = 0; i < buyer_ins.size ( ); i++ ) 
    if ( buyer_ins[i] -> get_username () == buyer_username ) 
      cout << buyer_ins[i] -> get_first_name () << " " << buyer_ins[i] -> get_last_name () + " " << buyer_username << " " << buyer_ins[i] -> get_phone_number () << '\n';

  sort ( out );

  for ( int i = 0; i < out.size( ); i++ ) {
      
    cout << i+1 << ". ";

    stringstream iss ( out[i] );

    string x;

    iss >> x;
    cout << x << " | ";

    iss >> x;
    cout << x << " | ";

    iss >> x;
    cout << x << " | ";

    iss >> x;
    cout << x << " | ";

    iss >> x;
    cout << x << "\n";

  }
  
  if ( out.size() != 0 )
    store ( buyer_username , sum , out , db );
    cout << "Goods Sum = " << sum << '\n' << "Total Sum = " << sum*1.05 << '\n';

} 

void buy ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number ) {

  int calc , sum = 0 , c = 0 , count;  
  char end = ',';  
  string str , name , buyer , seller;
  vector<string> v;
  vector<string> vv;

  while ( end != ';' ) {

    if ( c != 0 ) {

      getline ( cin , str );

      stringstream iss ( str );

      iss >> name >> count >> seller;

      string pure_seller = seller;

      pure_seller.pop_back ( ); 

      if ( seller[seller.size ( ) - 1] != ',' && seller[seller.size ( ) - 1] != ';' ) {

        cout << "Command Failed\n";
        return;

      }

      bool isthereorno = false;
      for ( int i = 0; i < g.size ( ); i++ )
        if ( g[i] -> get_name ( ) == name && g[i] -> get_seller_username () == pure_seller ) {
          
          isthereorno = true;
          for ( int j = 0; j < buyer_ins.size (); j++ )
            if ( buyer_ins[j] -> get_username () == buyer ) {

              int t = g[i] -> get_special_counts () , temp = g[i] -> get_count (); 
              //
              int  special_price = g[i] -> get_price ();
              //
              calc = 0;
              vv.clear ();
              if ( g[i] -> get_special_counts () >= count ) {
                    calc = count * g[i] -> get_price ();
                    //
                    vv.push_back ( name + " " + to_string(g[i]->get_special_counts()) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc ) );
                    //
                    g[i] -> decrese_count ( count , count );
              } else {
                int k = 1;
                for ( ; k <= t; k++ ) {
                  calc += g[i] -> get_price (); 
                  g[i] -> decrese_count ( 1 , 1 );
                }
                //
                if ( k != 1 )
                  vv.push_back ( name + " " + to_string(t) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                int temp_calc = calc;
                //    
                int countthis = 0; 
                while ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) && count - (k-1) - countthis > 0 ) {
                  calc += (int)( g[i] -> get_price () * 0.9 );
                  g[i] -> decrese_count ( 1 , 1 );
                  countthis++;
                }
                //
                if ( countthis != 0 && k != 1  ) {

                  vv.pop_back ( );
                  vv.push_back ( name + " " + to_string(t+countthis) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                
                } else if ( countthis != 0 )
                    vv.push_back ( name + " " + to_string(countthis) + " " + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                  
                temp_calc = calc;
                //
                calc += ( count - (k-1) - countthis ) * g[i] -> get_price ();
                g[i] -> decrese_count ( count - (k-1) - countthis , 0 );
                //
                if ( count - (k-1) - countthis != 0 )
                  vv.push_back ( name + " " + to_string(count - (k-1) - countthis) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                //
              }

              if ( calc <= buyer_ins[j] -> get_money () ) {

                if ( temp >= count ) {
             
                  sum += calc;

                  for ( int j = 0; j < buyer_ins.size (); j++ )
                    if ( buyer_ins[j] -> get_username () == buyer )
                      buyer_ins[j] -> set_money ( calc );


                  for ( int j = 0; j < seller_ins.size (); j++ )
                    if ( seller_ins[j] -> get_username () == seller )
                      seller_ins[j] -> set_money ( calc );


                  for ( int j = 0; j < vv.size (); j++ )
                    v.push_back ( vv[j] );

                  g[i] -> increase_buys ();

              }

                if ( g[i] -> get_count () == 0 ) 
                  g.erase ( g.begin ( ) + i );
            
            } else
              cout << "Command Failed\n";

        } 

      } if ( isthereorno == false )
          cout << "Command Failed\n";

    } else if ( c == 0 ) {

      getline ( cin , str );

      stringstream iss ( str );

      iss >> buyer >> name >> count >> seller;

      string pure_seller = seller;

      pure_seller.pop_back ( ); 

      if ( seller[seller.size ( ) - 1] != ';' && seller[seller.size ( ) - 1] != ',' ) {

        cout << "Command Failed\n";
        return;

      }

      c++;

      bool isthereorno = false;
      for ( int i = 0; i < buyer_ins.size ( ); i++ ) 
        if ( buyer == buyer_ins[i] -> get_username () ) {
          isthereorno = true;
        }

      if  ( isthereorno == false ) {
        cout << "Command Failed\n";
        return;
      }

      isthereorno = false; 
      for ( int i = 0; i < g.size ( ); i++ ) 
        if ( g[i] -> get_name ( ) == name && g[i] -> get_seller_username () == pure_seller ) {

        isthereorno = true;
        for ( int j = 0; j < buyer_ins.size (); j++ ) 
        if ( buyer_ins[j] -> get_username () == buyer ) {

            int t = g[i] -> get_special_counts () , temp = g[i] -> get_count (); 
            //
            int  special_price = g[i] -> get_price ();
            //
            calc = 0;
            vv.clear ();
            if ( g[i] -> get_special_counts () >= count ) {
                  calc = count * g[i] -> get_price ();
                  //
                  vv.push_back ( name + " " + to_string(g[i]->get_special_counts()) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc ) );
                  //
                  g[i] -> decrese_count ( count , count );
            } else {
              int k = 1;
              for ( ; k <= t; k++ ) {
                calc += g[i] -> get_price (); 
                g[i] -> decrese_count ( 1 , 1 );
              }
              //
              if ( k != 1 )
                vv.push_back ( name + " " + to_string(t) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
              int temp_calc = calc;
              //    
              int countthis = 0; 
              while ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) && count - (k-1) - countthis > 0 ) {
                calc += (int)( g[i] -> get_price () * 0.9 );
                g[i] -> decrese_count ( 1 , 1 );
                countthis++;
              }
              //
              
              if ( countthis != 0 && k != 1  ) {

                vv.pop_back ( );
                vv.push_back ( name + " " + to_string(t+countthis) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
              
              } else if ( countthis != 0 )
                  vv.push_back ( name + " " + to_string(countthis) + " " + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
              
              temp_calc = calc;
              //
              calc += ( count - (k-1) - countthis ) * g[i] -> get_price ();
              g[i] -> decrese_count ( count - (k-1) - countthis , 0 );
              //
              if ( count - (k-1) - countthis != 0 )
                vv.push_back ( name + " " + to_string(count - (k-1) - countthis) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
              //
            }

           if ( calc <= buyer_ins[j] -> get_money () ) {

            if ( temp >= count ) {
          
              sum += calc;

              for ( int j = 0; j < buyer_ins.size (); j++ )
                if ( buyer_ins[j] -> get_username () == buyer )
                  buyer_ins[j] -> set_money (  calc );


              for ( int j = 0; j < seller_ins.size (); j++ )
                if ( seller_ins[j] -> get_username () == seller )
                seller_ins[j] -> set_money (  calc );

             for ( int j = 0; j < vv.size (); j++ )
              v.push_back ( vv[j] );

              g[i] -> increase_buys ();

             }

          if ( g[i] -> get_count () == 0 ) 
            g.erase ( g.begin ( ) + i );

          } else
            cout << "Command Failed\n";
        }

      } if ( isthereorno == false )
        cout << "Command Failed\n";

    }
      
    end = seller[seller.size ( )-1];

  } 

  if ( v.size ( ) != 0 ) { 

    factor ( buyer , v , sum , buyer_ins , seller_ins , g , db , factor_number );
    
    seller_ins[0] -> set_money ( (int)(sum*0.05) );

  }

}

void sale ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) { 

string buyer_username , goods_name , seller_username;

cin >> buyer_username >> goods_name >> seller_username;  

bool isthereorno = false;
for ( int i = 0; i < buyer_ins.size ( ); i++ )
  if ( buyer_username == buyer_ins[i] -> get_username () )
    isthereorno = true;

if  ( isthereorno == false ) {
  cout << "Command Failed\n";
  return;
}

vector<string> v;
for ( int i = 0; i < g.size ( ); i++ ) 
  if ( g[i] -> get_seller_username () == seller_username && g[i] -> get_name () == goods_name ) {  
    v = g[i] -> get_offeres_usernames ( );
    for ( int j = 0; j < v.size ( ); j++ )
      if ( v[j] == buyer_username ) {
          cout << "Command Failed\n";
          return;
      }
    g[i] -> set_offeres_usernames ( buyer_username );
    g[i] -> increase_count_offers ();
  }

cout << "Command Ok\n";

} 

void remove_special ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  string seller_username , goods_name;
  int  goods_count;
  cin >> seller_username >> goods_name >> goods_count;

  bool isthereorno = false;
  for ( int i = 0; i < seller_ins.size ( ); i++ )
    if ( seller_username == seller_ins[i] -> get_username () )
      isthereorno = true;

  for ( int i = 0; i < g.size ( ); i++ )
    if ( goods_name == g[i] -> get_name () && goods_count <= g[i] -> get_count () )
      isthereorno = true;

  if  ( isthereorno == false ) {
    cout << "Command Failed\n";
    return;
  }

  for ( int i = 0; i < g.size (); i++ )
    if ( g[i] -> get_name () == goods_name && g[i] -> get_seller_username () == seller_username ) {
      g[i] -> rem_as_special ( goods_count );
    }

  cout << "Command Ok\n";

}


void add_special ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  string seller_username , goods_name;
  int  goods_count;
  cin >> seller_username >> goods_name >> goods_count;


  bool isthereorno = false;
  for ( int i = 0; i < seller_ins.size ( ); i++ )
    if ( seller_username == seller_ins[i] -> get_username () )
      isthereorno = true;

  if  ( isthereorno == false ) {
    cout << "Command Failed\n";
    return;
  }


  isthereorno = false;
  for ( int i = 0; i < g.size ( ); i++ )
    if ( goods_name == g[i] -> get_name () && goods_count <= g[i] -> get_count () )
      isthereorno = true;

  if  ( isthereorno == false ) {
    cout << "Command Failed\n";
    return;
  }

  for ( int i = 0; i < g.size (); i++ )
    if ( g[i] -> get_name () == goods_name && g[i] -> get_seller_username () == seller_username ) {
      g[i] -> set_as_special ( goods_count );
    }

  cout << "Command Ok\n";

}

void search_bestseller ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) { 

  vector<string> out;
  for ( int i = 0; i < g.size ( ); i++ )
    if ( g[i] -> get_buys () > 10 ) {   

      if ( g[i] -> ifcountoffers10 () )
          out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_count ()) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
          
          else if (  g[i] -> get_special_counts () > 0 ) {
            out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_special_counts ()) + " "  + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
            out.push_back ( g[i] -> get_name () + " " + to_string ( g[i] -> get_count () - g[i] -> get_special_counts () ) + " "  + to_string( (int)(g[i] -> get_price ()*1.1) ) + " " + g[i] -> get_seller_username () );
            }
    
            else if ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) ) 
              out.push_back ( g[i] -> get_name () + " " + to_string ( g[i] -> get_count ()) + " "  + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + g[i] -> get_seller_username () );

              else       
                out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
        
    }

    sort ( out );

    for ( int i = 0; i < out.size( ); i++ )
      cout << i+1 << ". " << out[i] << '\n';

}

void search_sale ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  vector<string> out;

  for ( int i = 0; i < g.size(); i++ ) {

    if ( g[i] -> ifcountoffers10 () )
      out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_count ()) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
    
      else if (  g[i] -> get_special_counts () > 0 ) {
        out.push_back ( g[i] -> get_name () + " " + to_string(g[i] -> get_special_counts ()) + " "  + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
        out.push_back ( g[i] -> get_name () + " " + to_string( g[i] -> get_count () - g[i] -> get_special_counts ()) + " "  + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
        }
        else if ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db  ) ) 
          out.push_back ( g[i] -> get_name () + " " + to_string ( g[i] -> get_count ()) + " "  + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + g[i] -> get_seller_username () );
        
    }

    sort ( out );

    for ( int i = 0; i < out.size( ); i++ )
      cout << i+1 << ". " << out[i] << '\n';

}

void add_money ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  string username;
  int money;
  cin >> username >> money; 

  bool b = false;
  for ( int i = 0; i < buyer_ins.size (); i++ )
    if ( username == buyer_ins[i] -> get_username () ) {
      buyer_ins[i] -> add_money ( money ); 
      b = true;
    }

  for ( int i = 0; i < seller_ins.size (); i++ )
    if ( username == seller_ins[i] -> get_username () ) {
      seller_ins[i] -> add_money ( money );
      b = true;
    }

if ( b == false )
  cout << "Comand Failed\n";
  else 
    cout << "Command Ok\n";

}

void print_factor ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) {

  string buyer_username;
  cin >> buyer_username;
  vector<string> out;

  for ( int ip = 0; ip < db.size (); ip++ )
    if ( db[ip][db[ip].size()-2] == buyer_username ) {
      cout << "Factor " << ip+1 << " " << buyer_username << '\n';
      out.clear();
      for ( int jp = 0; jp < db[ip].size ()-2; jp++ ) 
        out.push_back ( db[ip][jp] );
        
      sort ( out );

      for ( int i = 0; i < out.size( ); i++ )
        cout << i+1 << ". " << out[i] << '\n';

      cout << "Goods Sum = " << db[ip][db[ip].size()-1] << '\n' << "Total Sum = " << str_to_int(db[ip][db[ip].size()-1]) * 1.05 << '\n';
    
    }

}

void request ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number ) {

  string request_name , buyer_username , goods_name , seller_username;
  int goods_count;

  int c = 0 , sum = 0 , calc;

  vector<string> v;
  vector<string> vv;
  char end = ',';

  while ( end != ';' ) {

    if ( c != 0 ) {

      cin >> goods_name >> goods_count >> seller_username;

      string pure_seller = seller_username;

      pure_seller.pop_back ( ); 

      if ( seller_username[seller_username.size ( ) - 1] != ',' && seller_username[seller_username.size ( ) - 1] != ';' ) {

        cout << "Command Failed\n";
        return;

      }

      string str = goods_name + " " + to_string(goods_count) + " " + pure_seller;
      for ( int i = 0; i < buyer_ins.size (); i++ )
        if ( buyer_username == buyer_ins[i] -> get_username () )
          buyer_ins[i] -> set_request ( str );
      
      for ( int i = 0; i < g.size ( ); i++ )
        if ( g[i] -> get_name ( ) == goods_name && g[i] -> get_seller_username () == pure_seller ) {  

          for ( int j = 0; j < buyer_ins.size (); j++ )
          if ( buyer_ins[j] -> get_username () == buyer_username ) {

              int t = g[i] -> get_special_counts () , temp = g[i] -> get_count (); 
              //
              int  special_price = g[i] -> get_price ();
              //
              calc = 0;
              vv.clear ();
              if ( g[i] -> get_special_counts () >= goods_count ) {
                    calc = goods_count * g[i] -> get_price ();
                    //
                    vv.push_back ( goods_name + " " + to_string(g[i]->get_special_counts()) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc ) );
                    //
                    g[i] -> decrese_count ( goods_count , goods_count );
              } else {
                int k = 1;
                for ( ; k <= t; k++ ) {
                  calc += g[i] -> get_price (); 
                  g[i] -> decrese_count ( 1 , 1 );
                }
                //
                if ( k != 1 )
                  vv.push_back ( goods_name + " " + to_string(t) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                int temp_calc = calc;
                //    
                int countthis = 0; 
                while ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) && goods_count - (k-1) - countthis > 0 ) {
                  calc += (int)( g[i] -> get_price () * 0.9 );
                  g[i] -> decrese_count ( 1 , 1 );
                  countthis++;
                }
                //
                
                if ( countthis != 0 && k != 1  ) {

                  vv.pop_back ( );
                  vv.push_back ( goods_name + " " + to_string(t+countthis) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                
                } else if ( countthis != 0 )
                    vv.push_back ( goods_name + " " + to_string(countthis) + " " + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                  
                temp_calc = calc;
                //
                calc += ( goods_count - (k-1) - countthis ) * g[i] -> get_price ();
                g[i] -> decrese_count ( goods_count - (k-1) - countthis , 0 );
                //
                if ( goods_count - (k-1) - countthis != 0 )
                  vv.push_back ( goods_name + " " + to_string(goods_count - (k-1) - countthis) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                //
              }

          if ( calc <= buyer_ins[j] -> get_money () ) {

            if ( temp >= goods_count ) {
              
              sum += calc;

              for ( int j = 0; j < buyer_ins.size (); j++ )
                if ( buyer_ins[j] -> get_username () == buyer_username ) {

                  buyer_ins[j] -> set_money ( calc );
                  buyer_ins[j] -> req_pop ();
                
                }

              for ( int j = 0; j < seller_ins.size (); j++ )
                if ( seller_ins[j] -> get_username () == seller_username )
                  seller_ins[j] -> set_money ( calc );

              for ( int j = 0; j < vv.size (); j++ )
                v.push_back ( vv[j] );

              g[i] -> increase_buys ();

          }

            if ( g[i] -> get_count () == 0 ) 
              g.erase ( g.begin ( ) + i );
          
          }

        }

      }
         

    } else if ( c == 0 ) {

        c++;

        cin >> request_name >> buyer_username >> goods_name >> goods_count >> seller_username;

        string pure_seller = seller_username;

        pure_seller.pop_back ( ); 

        if ( seller_username[seller_username.size ( ) - 1] != ',' && seller_username[seller_username.size ( ) - 1] != ';' ) {

          cout << "Command Failed\n";
          return;

        }

        bool isthereorno = false;
        for ( int i = 0; i < buyer_ins.size ( ); i++ )
          if ( buyer_username == buyer_ins[i] -> get_username () )
            isthereorno = true;

        if  ( isthereorno == false ) {
          cout << "Command Failed\n";
          return;
        }

       string str = goods_name + " " + to_string(goods_count) + " " + pure_seller;
        
        for ( int i = 0; i < buyer_ins.size (); i++ )
          if ( buyer_username == buyer_ins[i] -> get_username () ) { 

            request_name.push_back ( '$' );
            buyer_ins[i] -> set_request ( request_name );
            buyer_ins[i] -> set_request ( str );

          }

        for ( int i = 0; i < g.size ( ); i++ )
          if ( g[i] -> get_name ( ) == goods_name && g[i] -> get_seller_username () == pure_seller ) {
        
          for ( int j = 0; j < buyer_ins.size (); j++ )
          if ( buyer_ins[j] -> get_username () == buyer_username ) {

              int t = g[i] -> get_special_counts () , temp = g[i] -> get_count (); 
              //
              int  special_price = g[i] -> get_price ();
              //
              calc = 0;
              vv.clear ();
              if ( g[i] -> get_special_counts () >= goods_count ) {
                    calc = goods_count * g[i] -> get_price ();
                    //
                    vv.push_back ( goods_name + " " + to_string(g[i]->get_special_counts()) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc ) );
                    //
                    g[i] -> decrese_count ( goods_count , goods_count );
              } else {
                int k = 1;
                for ( ; k <= t; k++ ) {
                  calc += g[i] -> get_price (); 
                  g[i] -> decrese_count ( 1 , 1 );
                }
                //
                if ( k != 1 )
                  vv.push_back ( goods_name + " " + to_string(t) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                int temp_calc = calc;
                //    
                int countthis = 0; 
                while ( if_is_30 ( g[i] -> get_name () , buyer_ins , seller_ins , g , db ) && goods_count - (k-1) - countthis > 0 ) {
                  calc += (int)( g[i] -> get_price () * 0.9 );
                  g[i] -> decrese_count ( 1 , 1 );
                  countthis++;
                }
                //
                
                if ( countthis != 0 && k != 1  ) {

                  vv.pop_back ( );
                  vv.push_back ( goods_name + " " + to_string(t+countthis) + " " + to_string ( special_price ) + " " + pure_seller + " " + to_string ( calc ) );
                
                } else if ( countthis != 0 )
                    vv.push_back ( goods_name + " " + to_string(countthis) + " " + to_string ( (int)(g[i] -> get_price () * 0.9) ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                
                temp_calc = calc; 
                //
                calc += ( goods_count - (k-1) - countthis ) * g[i] -> get_price ();
                g[i] -> decrese_count ( goods_count - (k-1) - countthis , 0 );
                //
                if ( goods_count - (k-1) - countthis != 0 )
                  vv.push_back ( goods_name + " " + to_string(goods_count - (k-1) - countthis) + " " + to_string ( g[i] -> get_price () ) + " " + pure_seller + " " + to_string ( calc - temp_calc ) );
                //
              }

          if ( calc <= buyer_ins[j] -> get_money () ) {

          if ( temp >= goods_count ) {
          
          sum += calc;

          for ( int j = 0; j < buyer_ins.size (); j++ )
            if ( buyer_ins[j] -> get_username () == buyer_username ) {
              buyer_ins[j] -> set_money ( calc );
              buyer_ins[j] -> req_pop ();
          }


          for ( int j = 0; j < seller_ins.size (); j++ )
            if ( seller_ins[j] -> get_username () == seller_username )
              seller_ins[j] -> set_money (  calc );

         for ( int j = 0; j < vv.size (); j++ )
           v.push_back ( vv[j] );

          g[i] -> increase_buys ();

        }

          if ( g[i] -> get_count () == 0 ) 
            g.erase ( g.begin ( ) + i );
        }

      }

    }
         
  }
      
    end = seller_username[seller_username.size ( )-1];

  } 

  if ( v.size( ) != 0 ) {

    seller_ins[0] -> set_money ( (int)(sum*0.05) );

    factor ( buyer_username , v , sum , buyer_ins , seller_ins , g , db , factor_number );
    store ( buyer_username , sum , v , db );

  }

}

void print_request ( vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db ) { 

  string buyer_username , seller_username , goods_name , request_name;
  int goods_count;
  cin >> buyer_username;

  vector<string> myvec;

  int i = 0;
  for ( int roll = 0; roll < buyer_ins.size (); roll++ ) 
    if ( buyer_ins[roll] -> get_username () == buyer_username ) {
      myvec = buyer_ins[roll] -> get_requests ();
        if ( myvec.size ( ) == 0 )
          return;
      cout << "Request " << i+1 << " ";
      int j = 0;
      for ( int rollp = 0; rollp <  myvec.size (); rollp++ ) {

          if ( myvec[rollp][myvec[rollp].size()-1] == '$' ) {
            
            myvec[rollp].pop_back ();
            request_name = myvec[rollp]; 
            cout << request_name << " " << buyer_username << '\n';
            j = 0;
            continue;
          }

        stringstream iss ( myvec[rollp] );
        iss >> goods_name >> goods_count >> seller_username;
        cout << j+1 << ". " << goods_name << " " << goods_count << " " << seller_username << '\n'; 
        j++;
      }
      i++;
    }
      
}

void menu ( string str , vector<Buyer*> &buyer_ins , vector<Seller*> &seller_ins , vector<Goods*> &g , vector< vector<string> > &db , int &factor_number ) {

  if ( str == "add_user" )
    add_user ( buyer_ins , seller_ins );

  else if ( str == "add_goods" ) {
    add_goods ( buyer_ins , seller_ins , g , db , factor_number );
    cout << "Command Ok\n";

  }
  
  else if ( str == "search" ) { search_goods ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "buy" ) { buy ( buyer_ins , seller_ins , g , db , factor_number ); }
  else if ( str == "sale" ) { sale ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "add_special" ) { add_special ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "remove_special" ) { remove_special ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "search_sale" ) { search_sale ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "search_bestseller" ) { search_bestseller ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "add_money" ) { add_money ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "print_factor" ) { print_factor ( buyer_ins , seller_ins , g , db ); }
  else if ( str == "request" ) { request ( buyer_ins , seller_ins , g , db , factor_number ); }
  else if ( str == "print_request" ) { print_request ( buyer_ins , seller_ins , g , db ); }

  else {

    string str;

    getline ( cin , str );

    while ( str[str.size()-1] == ','  )
      getline ( cin , str );
 
    cout << "Command Failed\n";

  }

}

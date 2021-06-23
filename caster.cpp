#include "caster.h"

int str_to_int (string str){
  int x = 0;
  for ( int i=0 ; i<str.length ( ) ; i++ ){
    for( int j = 0 ; j <= 9 ; j++ ){
      if ( j == (int)str[i] - 48)
        x = x * 10 + j;
    }  
  }
  return x;
}

/*XXX This Document was modified on 1636009669 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node node;
struct node {
 int l;
 node *n;
};

node *n_create (  )
{
 node *a = malloc ( sizeof ( node ) );
 a->l = 0;
 a->n = 0;

 return a;
}

void n_gen ( node ** p, int m )
{
 node **r = p;
 if( !r )
  return;

 while( 1 ) {
  if( !*r ) {
   *r = n_create (  );
   break;
  } else if( ( *r )->l < m ) {
   ( *r )->l++;
   break;
  } else if( ( *r )->l >= m ) {
   ( *r )->l = 0;
   r = &( *r )->n;
  }
 }
}

void n_puts ( void **data, int n )
{
 printf ( "%s", data[n] );
}

void n_iter ( node * r, void ( *my_func ) ( void **data, int n ), void **data )
{
 if( !r )
  return;
 my_func ( data, r->l );
 if( !r->n ) {
  printf ( "%s\n", "@gmail.com" );
 }
 n_iter ( r->n, my_func, data );
}

int main ( signed Argsc, char *( Args[] ) )
{

 node *f = n_create (  );

 while( 1 ) {
  n_iter ( f, n_puts, ( void ** )Args + 1 );
  n_gen ( &f, Argsc - 2 );
 }
 return 0;
}

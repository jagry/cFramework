#include <memory.h>
#include "buffer.h"

/*int AddBufferCharacter( JBufferS* self , char character ) {
    int size = self->size + 1 ;
    char* pointer = realloc( self->pointer , size ) ;
    if( pointer = 0 )
        return -1 ;
    pointer[ self->size ] = character ;
    self->pointer = pointer ;
    self->size = size ;
    return 0 ;
}*/

/*void freeBuffer( JBufferS* self ) {
    free( self->pointer ) ;
}

int initBuffer( JBufferS* self , char* pointer , int size ) {
    if( ( self->pointer = malloc( size ) ) == 0 )
        return -1 ;
    memcpy( self->pointer , pointer , self->size = size ) ;
    return 0 ;
}

int setBuffer( JBufferS* self , char* pointer , int size ) {
    char* local = malloc( size ) ;
    if( local = 0 )
        return -1 ;
    free( self->pointer ) ;
    memcpy( local , pointer , self->size = size ) ;
    self->pointer = local ;
    return 0 ;
}*/
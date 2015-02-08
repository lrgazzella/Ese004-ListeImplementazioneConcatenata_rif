#include <stdlib.h>
#include "linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key) {
    
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    if(nuovo != NULL){
        nuovo->next = *first;
        nuovo->key = key;
        *first = nuovo;
    }else{
        return -1;
    }
    
    return 0;
} //-1

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    LLElement **scorri;
    scorri = first;
    if(nuovo != NULL){

        while((*scorri) != NULL){
            scorri = &((*scorri)->next);
        }
        nuovo->next = NULL;
        nuovo->key = key;
        *scorri = nuovo;
    }else{
        return -1;
    }
    
    return 0;
} //-1

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position) {
    
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    LLElement ** scorri;
    scorri = first;
    int i;
    
    if(nuovo != NULL){
        for(i=0; i<position ; i++){
            scorri = &((*scorri)->next);
        }
        nuovo->next = *scorri;
        nuovo->key = key;
        *scorri = nuovo; 
    }else{
        return -1;
    }
    return 0;
    
} //-1

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first) {
    int size = 0;
       
    while(first != NULL){
        size++;
        first = first->next;
    }
    
    return size;
} //-1

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key) {
    int i;

    for(i=0; ((i<position) && (first!=NULL)) ; i++){
        first = first->next;
    }
    
    if(first != NULL){
        *key = first->key;
        return 0;
    }
    
    return -1;
} //-1

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    int i;
    
    for(i=0 ; ((i<startPosition) && (first!=NULL)) ; i++){
        first = first->next;
    }
    
    while(first != NULL){
        if(first->key == key){
            *position = i;
            return 0;
        }else{
            first = first->next;
            i++;
        }
    }
    
    return -1;
} //-1

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first) {
    
    LLElement * ultimo = NULL;
    
    if(*first != NULL){
        ultimo = *first;
        *first = (*first)->next;
        free(ultimo);
        return 0;
    }else{
        printf("La lista è vuota \n");
        return -1;
    }
   
} //-1

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) {
    
    LLElement **scorri;
    
    if(*first != NULL){
        scorri = first;
        while((*scorri)->next != NULL){
            scorri = &((*scorri)->next);
        }
        free(*scorri);
        *scorri = NULL;
        return 0;
    }
    
    return -1;
    
}//-1

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position) {
    
    LLElement ** scorri;
    LLElement * elimina;
    
    int i;
    
    if(*first != NULL){
        scorri = first;
        for(i=0; i<position && *scorri!=NULL; i++){
            scorri = &((*scorri)->next);
        }
        
        if(*scorri != NULL){
            elimina = *scorri;
            *scorri = (*scorri)->next;
        }
        
        free( elimina );
        return 0;
    }
    return -1;
}  //-1

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    
    
    LLElement *elimina;
    
    while(*first != NULL) {
        elimina = *first;
        *first = (*first)->next;
        free(elimina);
        return 0;
    }
    return -1;
    
} //0
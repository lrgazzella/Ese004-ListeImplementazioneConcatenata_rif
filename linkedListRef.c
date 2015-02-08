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
} //0

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    // TODO Implementation needed
    return -1;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position) {
    // TODO Implementation needed
    return -1;
}

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

    for(i=0; i<position ; i++){
        first = first->next;
    }
    
    if(first != NULL){
        *key = first->key;
        return 0;
    }
    
    return -1;
} //0

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    
    for(*position=0 ; *position<startPosition ; *position++){
        first = first->next;
    }
    
    while(first != NULL){
        if(first->key == key){
            return 0;
        }else{
            first = first->next;
            *position++;
        }
    }
    
    return -1;
}

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first) {
    // TODO Implementation needed
    return -1;
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) {
    // TODO Implementation needed
    return -1;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position) {
    // TODO Implementation needed
    return -1;
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    // TODO Implementation needed
    return -1;
}
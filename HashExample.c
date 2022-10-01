#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20
//code by krish
typedef struct node{
   int data;   
   int key;
}nd;
nd* arr[SIZE]; 
nd* robot;
nd* element;

int hashCode(int key){
   return key % SIZE;
}

nd *search(int key){
   int index = hashCode(key);  
   while(arr[index] != NULL){
      if(arr[index]->key == key)
         return arr[index]; 
      ++index;
      index %= SIZE;
   }        
   return NULL;        
}

void insert(int key,int data){
   nd *element = (nd*) malloc(sizeof(nd));
   element->data = data;  
   element->key = key;
   int index = hashCode(key);
   while(arr[index] != NULL && arr[index]->key != -1){
      ++index;
      index %= SIZE;
   }
   arr[index] = element;
}

nd* delete(nd* element){
   int key = element->key;
   int index = hashCode(key);
   while(arr[index] != NULL){
      if(arr[index]->key == key){
         nd* temp = arr[index]; 
         arr[index] = robot; 
         return temp;
      }
      ++index;
      index %= SIZE;
   }      
	
   return NULL;        
}

void display(){
   int i = 0;
	printf("Start ->");
   for(i = 0; i<SIZE; i++){
      if(arr[i] != NULL)
         printf("(%d,%d) ->",arr[i]->key,arr[i]->data);
      else
         printf(" ");
   }
   printf("End\n");
}

int main(){
   robot = (nd*)malloc(sizeof(nd));
   robot->data = -1;  
   robot->key = -1; 
   insert(11, 20);
   insert(12, 70);
   insert(42, 80);
   insert(14, 25);
   insert(32, 44);
   insert(14, 32);
   insert(23, 11);
   insert(13, 78);
   insert(37, 97);
   display();
   element = search(32);
   if(element != NULL){
      printf("Element found: %d\n", element->data);
   } else{
      printf("Element not found\n");
   }
   delete(element);
   element = search(32);
   printf("After deletion: ");
   if(element != NULL){
      printf("Element found: %d\n", element->data);
   } else{
      printf("Element not found\n");
   }
   return 0;
}

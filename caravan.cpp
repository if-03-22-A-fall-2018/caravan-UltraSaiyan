/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include "pack_animal.h"
#include "general.h"
#include <stdlib.h>
#include <stdio.h>
struct Node{
  PackAnimal animal;
  Node* next;
};
struct CaravanImplementation{
  Node* head;
};

Caravan new_caravan()
{
  Caravan list=(Caravan)malloc(sizeof(CaravanImplementation));
  list->head=0;
  return list;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node* current=caravan->head;

  if(caravan->head!=0)
  {
    count++;
    while(current->next!=0)
    {
      count++;
      current=current->next;
    }

  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  struct Node* current = caravan->head;

  while(current!= 0){
    struct Node* bam = current;
    current = current->next;
    sfree(bam);
  }
    sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{

  if(animal==0)
  {
    return;
  }

  if(caravan->head==0)
  {
    caravan->head=(Node*)malloc(sizeof(Node));
    caravan->head->next=0;
    caravan->head->animal=animal;
    add_to_caravan(animal,caravan);
  }

  else{
    Node* node=(Node*)malloc(sizeof(Node));
    node->animal=animal;


    node->next=caravan->head;
    caravan->head=node;

    add_to_caravan(animal,caravan);
  }


}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node* current = caravan->head;
  if(caravan->head!=0)
  {
    if(caravan->head->animal==animal)
    {
      caravan->head = caravan->head->next;
        remove_from_caravan(animal,caravan);
      sfree(current);

    }
    else{
      while(current->next!=0)
      {
        if(current->next->animal!=animal)
        {
          current=current->next;
        }
        else{
          break;
        }
      }
      if(current->next != 0){
        Node* between = current->next;
        current->next = current->next->next;
          remove_from_caravan(animal,caravan);
        sfree(between);
      }
    }
  }

}

int get_caravan_load(Caravan caravan)
{
  return 1;
}

void unload(Caravan caravan)
{
}

int get_caravan_speed(Caravan caravan)
{
  return 1;
}

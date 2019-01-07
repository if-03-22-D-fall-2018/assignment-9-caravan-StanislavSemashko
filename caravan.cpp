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

#include <stdlib.h>
#include "caravan.h"
#include "general.h"

#define CAMEL_MAX_SPEED 20
#define HORSE_MAX_SPEED 50

typedef struct NodeImplementation* Node;

struct CaravanImplementation
{
  int length;
  Node head;
};
struct NodeImplementation
{
  PackAnimal animal;
  struct NodeImplementation* next;
};


Caravan new_caravan()
{
  Caravan new_caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  new_caravan->length = 0;
  new_caravan->head = 0;
  return new_caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while (current !=0)
  {
    Node to_delate = current;
    current = current->next;
    sfree(to_delate);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0)
  {
    // if(get_caravan(animal) != 0 && get_caravan(animal) != caravan)
    // {
    //         remove_pack_animal(get_caravan(animal), animal);
    // }

    Node current = caravan->head;
    while (current!= 0)
    {
      if (current->animal == animal)return;
      current = current->next;
    }
    current = caravan->head;
    Node newNode = (Node)malloc(sizeof(struct NodeImplementation));
    newNode->animal = animal;
    newNode->next = 0;
    if (caravan->head == 0)
    {
      caravan->head = newNode;
      add_to_caravan(animal, caravan);
      caravan->length++;
    }
    else
    {
      while (current->next != 0)
      {
        current = current->next;
      }
      current->next = newNode;
      add_to_caravan(animal, caravan);
      caravan->length++;
      
    }
  }

}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0)
  {
    Node current = caravan->head;
    if (current != 0 && current->animal == animal )
    {
      caravan->head = current->next;
      sfree(current);
      remove_from_caravan(animal, caravan);
      caravan->length--;
      return;
    }
    while (current->next != 0 && current->next->animal != animal)
    {
      current = current->next;
    }
    if (current->next != 0 )
    {
      current->next = current->next->next;
      sfree(current->next);
      remove_from_caravan(animal, caravan);
    }
  }

}

int get_caravan_load(Caravan caravan)
{
  int load = 0;
  Node current = caravan->head;
  while (current != 0)
  {
    load += get_load(current->animal);
    current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
  while (current != 0)
  {
    unload(current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  int speed = HORSE_MAX_SPEED;
  Node current = caravan->head;
  while (current != 0)
  {
    if (get_actual_speed(current->animal)<speed)
    {
    speed = get_actual_speed(current->animal);
    }
    current = current->next;
  }
  return speed;
}
void optimize_load(Caravan caravan)
{

}

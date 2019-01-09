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
  int len;
  Node head;
  Node last;
};
struct NodeImplementation
{
  PackAnimal animal;
  struct NodeImplementation* next;

};




Caravan new_caravan()
{
  Caravan new_caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  new_caravan->len = 0;
  new_caravan->head = 0;
  new_caravan-> last = 0;
  return new_caravan;
}

/**
* @return Die Länge einer Karawane, d.h., die Anzahl der Tiere in der Karawane.
*/
int get_length(Caravan caravan)
{
  return caravan->len;
}

/**
* Entfern alle Tiere aus einer Karawane und löscht die Karawane.
*/
void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while (current != 0)
  {
    Node delate = current;
    sfree(delate);
    current = current->next;
  }
  sfree(caravan);

}

/**
* Fügt ein Packtier zu einer Karawane hinzu.
*/
void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0)
  {
    if (get_caravan(animal) != 0 && get_caravan(animal) != caravan)
    {
      remove_pack_animal(get_caravan(animal),animal);
    }
    Node current = caravan->head;
    while(current != 0)
    {
      if (current->animal == animal) return;
      current = current->next;
    }
    Node new_node = (Node)malloc(sizeof(struct NodeImplementation));
    new_node->animal = animal;
    new_node->next = 0;
    if (caravan->head == 0)
    {
      caravan->head = new_node;
      caravan->last = new_node;
      caravan->len++;
      add_to_caravan(animal,caravan);
    }
    else
    {
      caravan->last->next = new_node;
      caravan->last = new_node;
      caravan->len++;
      add_to_caravan(animal,caravan);
    }
  }

}

/**
* Entfernt ein Packtier aus einer Karawane.
*/
void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0)
  {

    Node current = caravan->head;
    if (current != 0 && current->animal == animal)
    {
      caravan->head = current->next;
      sfree(current);
      remove_from_caravan(animal, caravan);
      caravan->len--;
    }
    else
    {
      while (current->next != 0 && current->next->animal != animal)
      {
        current = current->next;
      }
      if (current->next != 0)
      {
        Node to_free = current->next;
            current->next = current->next->next;
            sfree(to_free);
            remove_from_caravan(animal, caravan);
            caravan->len--;
      }

    }

  }

}

/**
* @return Die Geschwindigkeit einer Karawane. Diese richtet sich nach der Geschwindigkeit des
* langsamsten Tiers in der Karawane.
*/
int get_caravan_speed(Caravan caravan)
{
  int speed = HORSE_MAX_SPEED;
  Node current = caravan->head;
  while (current != 0)
  {
    if (get_actual_speed(current->animal) < speed)
    {
      speed = get_actual_speed(current->animal);
    }
    current = current->next;

  }
  return speed;
}

/**
* @return Die Gesamtanzahl der Ballen einer Karawane.
*/
int get_caravan_load(Caravan caravan)
{
  int summ = 0;
  Node current = caravan->head;
  while (current != 0)
  {
    summ += get_load(current->animal);
    current = current->next;
  }
  return summ;
}

/**
* Entl&auml;dt die gesamte Karawane. D.h. es wird jedes Tier in der Karawane von seinen Ballen
* befreit.
*/
void unload(Caravan caravan)
{
  Node current = caravan->head;
  while (current != 0)
  {
    unload(current->animal);
    current = current->next;
  }
}

/**
* Verteilt die Last der Ballen so auf die einzelnen Tiere, dass die Geschwindigkeit der Karawane
* maximal ist.
*/
void optimize_load(Caravan caravan)
{

}

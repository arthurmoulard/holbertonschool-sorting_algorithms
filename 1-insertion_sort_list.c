#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: is the list to sort
 * Return: nothing
 */
insertion_sort_list(listint_t **list)
{
    listint_t *current, *a, *b;

    /* Vérification : liste vide ou un seul élément → déjà triée */
    if (!list || !*list || !(*list)->next)
        return;

    /*
     * current : on démarre au 2e élément (car le 1er est "déjà trié")
     */
    for (current = (*list)->next; current; current = current->next)
    {
        b = current;          /* L'élément qu'on veut insérer */
        a = b->prev;          /* Le précédent, à comparer */

        /*
         * Tant que a existe et que la valeur de a est > b, on doit les échanger.
         * (On remonte b vers la gauche dans la partie triée)
         */
        while (a && a->n > b->n)
        {
            /*
             * Relier le nœud avant 'a' avec 'b'.
             * Si a n'a pas de précédent → b devient la nouvelle tête.
             */
            if (a->prev)
                a->prev->next = b;
            else
                *list = b;

            /*
             * Relier le nœud après 'b' avec 'a'.
             */
            if (b->next)
                b->next->prev = a;

            /*
             * ÉCHANGER a et b :
             *
             * avant :
             *   a <-> b
             *
             * après :
             *   b <-> a
             *
             * b monte, a descend.
             */
            b->prev = a->prev;
            a->next = b->next;
            a->prev = b;
            b->next = a;

            /* Affichage pour les checkers */
            print_list(*list);

            /*
             * Après l'échange : b a pris la place de a.
             * On continue à comparer b avec l'élément à gauche :
             * a = b->prev (NOUEAU précédent)
             */
            a = b->prev;
        }
    }
}
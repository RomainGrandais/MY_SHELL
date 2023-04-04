/*
** EPITECH PROJECT, 2022
** STRUCT LIST CHAINE
** File description:
** struct for list chaine
*/

#ifndef __MYLIST_H__
    #define __MYLIST_H__

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char * const *av);

#endif /* !MYLIST_H__ */

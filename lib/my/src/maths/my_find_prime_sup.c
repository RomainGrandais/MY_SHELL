/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** find the smallest prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int sup)
{
    while ( my_is_prime(sup) == 0) {
        sup++;
    }
    return (sup);
}

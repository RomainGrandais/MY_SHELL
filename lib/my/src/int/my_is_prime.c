/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** found if nb is prime
*/

int my_compute_square_root(int nb);

int my_is_prime(int nb)
{
    if ( nb == 2 || nb == 3)
        return (1);
    if (nb < 2 || nb % 2 == 0)
        return (0);
    for (int i = 3; i < nb / 2 ; i += 2) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

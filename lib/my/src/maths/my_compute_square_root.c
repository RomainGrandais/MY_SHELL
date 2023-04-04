/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** return the square root
*/

int my_compute_square_root(int nb)
{
    int carre = 1;
    int result = 0;

    if ( nb == 1)
        return (1);
    if ( nb == 0 || nb < 0)
        return (0);

    while ( carre < nb) {
        if (result != nb)
            result = carre * carre;
        if (carre > 46340)
            return (0);
        if ( result == nb)
            return (carre);
        carre++;
    }
    return (0);
}

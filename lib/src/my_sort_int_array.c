/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Sorts an integer array in ascending order.
*/

void sort(int *, int);

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size) {
        sort(array, size);
        i += 1;
    }
}

void sort(int *array, int size)
{
    int c = 0;
    int j = 0;

    while (j < size - 1) {
        if (array[j] > array[j + 1]) {
            c = array[j];
            array[j] = array[j + 1];
            array[j + 1] = c;
        }
        j += 1;
    }
    j = 0;
}

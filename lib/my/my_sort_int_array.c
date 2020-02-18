/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** sort integer
*/

void my_sort_int_array(int *array, int size);
int my_sort_strlen(int *array);
void swap_that_int(int *array, int y);

void my_sort_int_array(int *array, int size)
{
    int my_array;

    size--;
    for (int i = size ; i > 0 ; i--) {
        for (int y = size ; y > 0  ; y--) {
            swap_that_int(array, y);
        }
    }
}

int my_sort_strlen(int *array)
{
    int n_len = 0;

    while (*(array + n_len) != '\0') {
        n_len++;
    }
    return (n_len);
}

void swap_that_int(int *array, int y)
{
    int my_array;

    if (array[y] < array[y - 1]) {
        my_array = array[y];
        array[y] = array[y - 1];
        array[y - 1] = my_array;
    }
}

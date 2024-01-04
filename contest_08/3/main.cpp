#include <iostream>

int* new_array(int len, int value);
int set_new_length(int** array, int old_len, int new_len);
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array);
int dot(const int* a, const int* b, int len);
int* find(int* array, int len, int value);
void delete_array(int** array);

int main(){
    int len_first, len_second,
            first_init_val, second_init_val;
    std::cin >> len_first >> first_init_val >> len_second >> second_init_val;
    int* first  = new_array(len_first, first_init_val);
    int* second = new_array(len_second, second_init_val);

    int new_len_first;
    std::cin >> new_len_first;
    len_first = set_new_length(&first, len_first, new_len_first);
    for(int i=0; i < new_len_first; i++){
        int value;
        std::cin >> value;
        first[i] = value;
    }

    len_second = merge(&second, len_second, first, len_first);

    len_second = set_new_length(&second, len_second, len_first);

    int value = dot(first, second, len_first);

    int* value_ptr;
    while( (value_ptr = find(second, len_second, value)) != nullptr ){
        *value_ptr = 0;
    }

    for (int i=0; i < len_second; i++) std::cout << second[i] << ' ';

    delete_array(&first);
    delete_array(&first);  // Так и задумано
    delete_array(&second);
    delete_array(&second); // Так и задумано
}

// Ваш код будет вставлен сюда

int* new_array(int size, int value) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
    return array;
}

int set_new_length(int** list, int before_len, int new_len) {
    int* bag_in = new int[before_len];
    for (int i = 0; i < before_len; i++) {
        bag_in[i] = (*list)[i];
    }
    *list = new int[new_len];
    for (int i = 0; i < new_len; i++) {
        if (i < before_len) {
            (*list)[i] = bag_in[i];
        }
        else {
            (*list)[i] = 0;
        }
    }
    return new_len;
}

int merge(int** dest_list, int len_dest_list, const int* src_list, int len_src_list) {
    int* bag_in = new int[len_dest_list];
    for (int i = 0; i < len_dest_list; i++) {
        bag_in[i] = (*dest_list)[i];
    }
    *dest_list = new int[len_dest_list + len_src_list];
    for (int i = 0; i < len_dest_list + len_src_list; i++) {
        if (i < len_dest_list) {
            (*dest_list)[i] = bag_in[i];
        }
        else {
            (*dest_list)[i] = src_list[i - len_dest_list];
        }
    }
    return len_dest_list + len_src_list;
}

int dot(const int* a, const int* b, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int* find(int* list, int len, int value) {
    int* result = nullptr;
    for (int i = 0; i < len; i++) {
        if (list[i] == value) {
            result = &list[i];
            break;
        }
    }
    return result;
}

void delete_array(int** list) {
    if (*list != nullptr) {
        delete[] *list;
        *list = nullptr;
    }
}
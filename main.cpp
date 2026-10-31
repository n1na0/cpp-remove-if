#include <iostream>

struct Point {
    int x, y;
};

// шаблон
template <typename T, typename P>
void remove_if_custom(T* arr, size_t& n, P pred) {
    size_t write_idx = 0;
    for (size_t i = 0; i < n; ++i) {
        if (!pred(arr[i])) {
            arr[write_idx] = arr[i];
            write_idx++;
        }
    }
    n = write_idx;
}

int main() {
    // Тесты для int
    int nums[] = {1, 2, -3, 4, 5, -6, 7, 8, 9, 10, 12, 0};
    size_t n = sizeof(nums) / sizeof(nums[0]);

    // Копия
    int arr[12];
    for (size_t i = 0; i < n; ++i) arr[i] = nums[i];
    size_t cur_n = n;

    remove_if_custom(arr, cur_n, [](int x) { return x % 2 == 0; }); // удаляем четные
    std::cout << "Четные удалены: ";
    for (size_t i = 0; i < cur_n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";


    // Тесты для Point
    Point pts[] = {{0, 0}, {1, 2}, {0, 5}, {-3, 4}, {0, 0}, {7, 8}};
    size_t p_n = sizeof(pts) / sizeof(pts[0]);

    Point p_arr[6];
    for (size_t i = 0; i < p_n; ++i) p_arr[i] = pts[i];
    size_t cur_p_n = p_n;

    remove_if_custom(p_arr, cur_p_n, [](Point p) { return p.x == 0 && p.y == 0; }); // удаляем (0,0)
    std::cout << "Точки (0,0) удалены: ";
    for (size_t i = 0; i < cur_p_n; ++i) std::cout << "(" << p_arr[i].x << "," << p_arr[i].y << ") ";
    std::cout << "\n";

    return 0;
}
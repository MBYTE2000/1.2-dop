#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int n, k;
    cout << "Введите количество камней: ";
    cin >> n;
    cout << "Введите значение k: ";
    cin >> k;

    // Создаем массив камней
    int *stones = new int[n];
    for (int i = 0; i < n; i++) {
        stones[i] = i + 1;
    }

    // Удаляем каждый k-ый элемент из массива, пока его длина не станет меньше k
    int len = n;
    int i = k - 1;
    while (len >= k) {
        for (int j = i; j < len - 1; j++) {
            stones[j] = stones[j + 1];
        }
        len--;
        i += k - 1;
        i %= len;
    }

    // Выводим оставшиеся камни и их количество
    cout << "Оставшиеся камни: ";
    for (int i = 0; i < len; i++) {
        cout << stones[i] << " ";
    }
    cout << endl;
    cout << "Количество оставшихся камней: " << len << endl;

    return 0;
}

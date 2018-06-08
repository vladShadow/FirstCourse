#include <iostream>
using namespace std;

int main() {
    int prodNum[3] = {500, 400, 510};  //виготовляється на заводах
    int needNum[3] = {310, 390, 450};  //потреби магазинів
    int prodPrice[3] = {25, 20, 23};   //ціна виготовлення
    int transPrice[9] = {7, 5, 1, 2, 3, 2, 3, 4, 5};//ціна транспортування
    int resultNum[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//шукані невідомі

    //обчислюємо повну ціну транспортування (ціна виготовлення + ціна перевезення)
    int fullPrice[9];
    for (int i = 0; i <= 8; i++) {
        fullPrice[i] = transPrice[i] + prodPrice[i % 3];
    }

    //Сортуємо по зростанню повної ціни транспортування
    int sortedIndexes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j < 8; j++) {
            if (fullPrice[j] > fullPrice[j + 1]) {
                int tempPrice = fullPrice[j];
                fullPrice[j] = fullPrice[j + 1];
                fullPrice[j + 1] = tempPrice;
                int tempIndex = sortedIndexes[j];
                sortedIndexes[j] = sortedIndexes[j + 1];
                sortedIndexes[j + 1] = tempIndex;
            }
        }

    //Обчислюємо кількості перевезеної продукції - x1...x9
    for (int i = 0; i <= 8; i++) {
        int index = sortedIndexes[i];
        if (needNum[index / 3] != 0 && prodNum[index % 3] != 0)
            if (prodNum[index % 3] >= needNum[index / 3]) {
                resultNum[index] += needNum[index / 3];
                prodNum[index % 3] -= needNum[index / 3];
                needNum[index / 3] = 0;
            } else {
                resultNum[index] += prodNum[index % 3];
                needNum[index / 3] -= prodNum[index % 3];
                prodNum[index % 3] = 0;
            }
    }

    //Обчислюємо вартість всіх транспортувань - значення цільової функції
    int y = 0;
    for (int i = 0; i<=8; i++) {
        y += resultNum[sortedIndexes[i]]*fullPrice[i];
    }

    //Виводимо результати
    cout << "Відповідь:" << endl;
    for (int i = 0; i <= 8; i++) {
        cout << resultNum[i] << " ";
        if (i == 2 || i == 5) cout << endl;
    }
    cout << endl<< "y = " << y;

    return 0;
}
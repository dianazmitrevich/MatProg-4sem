
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include "Boat.h"
#define NN 25
#define MM 5
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int V = 1500;
        // v[NN] = { 100,  200,   300,  400,  500,  150 },
        // c[NN] = { 10,   15,    20,   25,   30,  25 };
    int v[NN], c[NN];

    for (int i = 0; i < NN; i++) {
        v[i] = rand() % 800 + 100;
        c[i] = rand() % 140 + 10;
    }

    short  r[MM];
    int cc = boat(
        V,   // [in]  максимальный вес груза
        MM,  // [in]  количество мест для контейнеров     
        NN,  // [in]  всего контейнеров  
        v,   // [in]  вес каждого контейнера  
        c,   // [in]  доход от перевозки каждого контейнера     
        r    // [out] результат: индексы выбранных контейнеров  
    );
    std::cout << std::endl << "- Задача о размещении контейнеров на судне";
    std::cout << std::endl << "- общее количество контейнеров    : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров : " << MM;
    std::cout << std::endl << "- ограничение по суммарному весу  : " << V;
    std::cout << std::endl << "- вес контейнеров                 : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- доход от перевозки              : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- доход от перевозки              : " << cc;
    std::cout << std::endl << "- общий вес выбранных контейнеров : ";
    int s = 0; for (int i = 0; i < MM; i++) s += v[r[i]]; std::cout << s;
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}



/*#include <iostream>
#include <iomanip>
#include "Boat.h"
#include "tchar.h"
#include <time.h>
#define NN 36
#define MM 6
#define SPACE(n) std::setw(n) << " "
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int V = 1500;
        //v[NN] = { 250, 560, 670, 400, 200, 270, 370, 330, 330, 440, 530, 120,
        //       200, 270, 370, 330, 330, 440, 700, 120, 550, 540, 420, 170,
        //       600, 700, 120, 550, 540, 420, 430, 140, 300, 370, 310, 120 },
        //c[NN] = { 15,26,  27,  43,  16,  26,  42,  22,  34,  12,  33,  30,
        //       42,22,  34,  43,  16,  26,  14,  12,  25,  41,  17,  28,
        //       12,45,  60,  41,  33,  11,  14,  12,  25,  41,  30,  40 };

    int v[NN], c[NN];

    for (int i = 0; i < NN; i++) {
        v[i] = rand() % 800 + 100;
        c[i] = rand() % 140 + 10;
    }

    short r[MM];
    int maxcc = 0;
    clock_t t1, t2;
    std::cout << std::endl << "-- Задача об оптимальной загрузке судна -- ";
    std::cout << std::endl << "-  ограничение по весу    : " << V;
    std::cout << std::endl << "-  количество мест        : " << MM;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "   контейнеров        вычисления  ";
    for (int i = 25; i <= NN; i++)
    {
        t1 = clock();
        int maxcc = boat(V, MM, i, v, c, r);
        t2 = clock();
        std::cout << std::endl << SPACE(7) << std::setw(2) << i << SPACE(15) << std::setw(5) << (t2 - t1);
    }
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}
*/
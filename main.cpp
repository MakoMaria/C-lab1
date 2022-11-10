#include <iostream>
#include <Windows.h> //кириллица
#include <math.h> //позволит использовать значение числа пи
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

//к коду можно было применить директиву using для всех идентификаторов в пространстве имен (using namespace std;),
// для сокращения времени написания, но можно обойтись и без этого )))

void task1(){
    int b1, b2, h;
    std::cout << "ЗАДАНИЕ 1" << std::endl;
    std::cout << "Введите значения сторон" << std::endl;
    std::cin >> b1 >> b2;
    std::cout << "Введите значение высоты" << std::endl;
    std::cin >> h;
    std::cout << "Площадь трапеции" << std::endl;
    std::cout << ((b1+b2)*h)*1/2 << std::endl;

    std::cout << "  " << std::endl; //строка для удобства отображения на коноли (чтоб красиво было)
}

void task2(){

    std::cout << "ЗАДАНИЕ 2" << std::endl;
    int r;
    std::cout << "Введите радиус" << std::endl;
    std::cin >> r;
    std::cout << "Площадь круга" << std::endl;
    std::cout << M_PI * r * r << std::endl;
    std::cout << "Длина окружности" << std::endl;
    std::cout << 2 * M_PI * r << std::endl;

    std::cout << "  " << std::endl;

}

void task3(){

    std::cout << "ЗАДАНИЕ 3" << std::endl;
    int a,b;
    std::cout << "Введите первый катет: " << "\n"; // "\n" выполняет ту же функцию, что и "endl", но "endl" вызывает очистку выходного буфера при каждом вызове. Конкретно в этой лараторной они выполняют одинаковую функцию, поэтому я использую оба варианта
    std::cin >> a;
    std::cout << "Введите второй катет: " << "\n";
    std::cin >> b;
    std::cout <<"Гипотенуза равна: " << sqrt(a*a+b*b) << "\n";
    std::cout << "Площадь равна: " << a*b/2 << "\n";

    std::cout << "  " << std::endl;

}

void task4(){
    std::cout << "ЗАДАНИЕ 4" << std::endl;  //можно было решать через деление и присвоение значений отдельным переменным,
    // а потом просто просуммировать их, но через сокращенную запись операций выглядит симпатичнее

    int n,sum;
    std::cout << "Введите четырехзначное число" << std::endl;
    std::cin >> n;
    sum = 0; // присваиваем переменной суммы значение 0
    while (n>=10) //условие цикла (пока оставшееся от деления n >= 10)
    {
        sum += n%10; // a += b => a = a + b
        n /= 10; // a /= b => a = a / b
    }
    sum += n; // добавляем к сумме первую цифру числа
    std::cout << sum << std::endl;

    std::cout << "  " << std::endl;

}

void task5(){

    std::cout << "ЗАДАНИЕ 5" << std::endl; //тут может быть ошибка в формуле, не знаю точную для перевод между системами координат
    int x,y;
    std::cout << "Введите декартову координату X " << std::endl;
    std::cin >> x;
    std::cout << "Введите декартову координату Y " << std::endl;
    std::cin >> y;
    std::cout <<" Полярная координата X" << std::endl << atan(y/x) << std::endl;
    std::cout << "Полярная координата Y " << std::endl << sqrt(x*x + y*y) << std::endl;

    std::cout << "  " << std::endl;

}

void task6(){

    std::cout << "ЗАДАНИЕ 6" << std::endl; //тут может быть ошибка в формуле, не знаю точную для перевод между системами координат
    int x,y,r,f;
    std::cout << "Введите полярную координату X " << std::endl;
    std::cin >> x;
    std::cout << "Введите полярную координату Y " << std::endl;
    std::cin >> y;
    std::cout << "Введите полярный радиус" << std::endl;
    std::cin >> r;
    std::cout << "Введите полярный угол" << std::endl;
    std::cin >> f;
    std::cout << "Декартова координата X" << std::endl << r * sin(f) << std::endl;
    std::cout << "Декартова координата Y" << std::endl << r * cos(f) << std::endl;

    std::cout << "  " << std::endl;

}

void task7(){

    std::cout << "ЗАДАНИЕ 7" << std::endl;
    double a,b,c,d,x1,x2;
    std::cout << "Введите a,b,c исходя из общего вида уравнения a*x^2 + b*x + c =0 : " << "\n";
    std::cin >> a >> b >> c;
    d = b*b - 4*a*c; //формула дискриминанта
    if (d > 0) {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        std::cout << "Корни: " << x1 << ", " << x2 << "\n";
    }
    if (d == 0) {
        x1 = x2 = -(b / (2 * a));
        std::cout << "Корни: " << x1 << ", " << x2 << "\n";
    }
    if (d < 0) {
        std::cout << "Уравнение не имеет действительных корней" << "\n";
    }

    std::cout << "  " << std::endl;

}

void task8(){

    std::cout << "ЗАДАНИЕ 8" << std::endl;
    double q,w,e,m,n,l,m1,n1,l1;
    std::cout << "Введите стороны треугольника" << std::endl;
    std::cin >> q >> w >> e;
    if ( (q+w) > e && (w + e) > q && (q + e) > w ) {//из введенных сторон можно "составить" треугольник
         m = sqrt((2 * q * q) + (2 * w * w) - (e *e)) / 4; //находим медианы исходного треугольника
         n = sqrt((2 * w * w) + (2 * e * e) - (q * q)) / 4;
         l = sqrt((2 * e * e) + (2 * q * q) - (w * w)) / 4;

         m1 = (sqrt(2 * m * m + 2 * n * n - l * l)) / 2; //находим медианы нового треугольника
         n1 = (sqrt(2 * n * n + 2 * l * l - m * m)) / 2;
         l1 = (sqrt(2 * l * l + 2 * m * m - n * n)) / 2;

        std::cout << "Медиана 1  " << m1 << std::endl;
        std::cout << "Медиана 2  " << n1 << std::endl;
        std::cout << "Медиана 3  " << l1 << std::endl;
    }

    else {
        std::cout << "Это не треугольник. Введите другие значения" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task9(){

    std::cout << "ЗАДАНИЕ 9" << std::endl;
    int k, hours, minutes;
    std::cout << "Введите количество секунд" << std::endl;
    std::cin >> k;

    while (k >= 86400) //86400 - количество секунд в сутках. цикл нужен, чтобы количество часов насинало отсчет с новых суток (чтобы избежать 37 часов, например)
    {
        k = k - 86400;
    }
    minutes = k / 60;
    hours = minutes / 60;
    minutes = minutes % 60; // остаток от деления часов = минутам

    std::cout << "Прошло " << hours << " ч " << minutes << " мин " <<std::endl;

    std::cout << "  " << std::endl;

}

void task10(){

    std::cout << "ЗАДАНИЕ 10" << std::endl;
    int a,b,c;
    std::cout << "Введите стороны a.b.c треугольника" << std::endl;
    std::cin >> a >> b >> c;
    if ( (a == b) or (b == c) or (a == c)) { // в равнобедренном треугольнике 2 стороны равны
        std::cout << "Треугольник является равнобедренным" << std::endl;
    }
    else {
        std::cout << "Треугольник не является равнобедренным" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task11(){

    std::cout << "ЗАДАНИЕ 11" << std::endl;
    int p;
    std::cout << "Введите стоимость покупки" << std::endl;
    std::cin >> p;
    if (p > 1000) {
        std::cout << "Стоимость покупки с учетом скидки 10% = " << p - (p/10) << std::endl; // вычитаем из стоимости 1/10 часть стоимости
    }
    else {
        std::cout << "Сумма покупки не превышает 1000 рублей. Стоимость без учета скидки = " << p << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task12(){

    std::cout << "ЗАДАНИЕ 12" << std::endl;
    int h,w;
    std::cout << "Введите свой рост" << std::endl;
    std::cin >> h;
    std::cout << "Введите свой вес" << std::endl;
    std::cin >> w;

    if (w > (h - 100)) {
        std::cout << "Вам стоит немного сбросить вес, до идеала  -" << w - (h-100) << std::endl;
    }
    else if (w < (h - 100)) {
        std::cout << "Вам стоит набрать вес, до идеала  +" << (h-100) - w << std::endl;
    }
    else if (w == (h - 100)) {
        std::cout << "Ваш вес идеален )))" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task13(){

    std::cout << "ЗАДАНИЕ 13" << std::endl;

    srand(time(0)); // time устанавливает в качестве базы текущее время, чтобы рандомайзер выдавал разные значения
    int n1 = rand() % 9 +1; // +1, чтобы установить диапазон от 1 до 9
    int n2 = rand() % 9 +1;
    std::cout << "Первое число - " << n1 << std::endl;
    std::cout << "Второе число - " << n2 << std::endl;
    system("Pause");

    std::cout << "Введите произведение этих чисел" << std::endl;
    int c;
    std::cin >> c;

    if (c == (n1 * n2)) {
        std::cout << "Вы правы, молодец)" << std::endl;
    }
    else {
        std::cout << "Вы ошиблись, попробуйте ещё раз(" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task14(){

    std::cout << "ЗАДАНИЕ 14" << std::endl;
    int time, price, day, h;
    std::cout << "Введите цену за час" << std::endl;
    std::cin >> price;
    std::cout << "Введите длительность переговоров в часах" << std::endl;
    std::cin >> time;
    std::cout << "Введите день недели (цифра от 1 до 7) " << std::endl;
    std::cin >> day;

    if (day <= 7 and day >= 1) {
        if (day == 6 or day ==7) {
            h = ((price * time) / 100) * 80;
            std::cout << "Стоимость переговоров:  " << h << std::endl;
        }
        else {
            std::cout << "Стоимость переговоров:  " << (price * time) << std::endl;
        }
    }
    else {
        std::cout << "Ошибка при вводе дня недели " << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task15(){

    std::cout << "ЗАДАНИЕ 15" << std::endl;
    int month;
    std::cout << "Введите номер месяца" << std::endl;
    std::cin >> month;

    if (month == 1) {
        std::cout << "Январь, зима" << std::endl;
    }
    else if (month == 2) {
        std::cout << "Февраль, зима" << std::endl; // а в c++ есть подобие сокращения elif как в Python?
    }
    else if (month == 3) {
        std::cout << "Март, весна" << std::endl;
    }
    else if (month == 4) {
        std::cout << "Апрель, весна" << std::endl;
    }
    else if (month == 5) {
        std::cout << "Май, весна" << std::endl;
    }
    else if (month == 6) {
        std::cout << "Июнь, лето" << std::endl;
    }
    else if (month == 7) {
        std::cout << "Июль, лето" << std::endl;
    }
    else if (month == 8) {
        std::cout << "Август, лето" << std::endl;
    }
    else if (month == 9) {
        std::cout << "Сентябрь, осень" << std::endl;
    }
    else if (month == 10) {
        std::cout << "Октябрь, осень" << std::endl;
    }
    else if (month == 11) {
        std::cout << "Ноябрь, осень" << std::endl;
    }
    else if (month == 12) {
        std::cout << "Декабрь, зима" << std::endl;
    }
    else {
        std::cout << "Ошибка при вводе" << std::endl;
    }
    std::cout << "  " << std::endl;

}

void task16(){

    std::cout << "ЗАДАНИЕ 16" << std::endl;
    int num,n1,n2,n3,n4,n5,n6,a,b;
    std::cout << "Введите шестизначное число" << std::endl;
    std::cin >> num;

    n1 = num / 100000; // выделяем первую цифру
    n2 = (num - n1 * 100000) / 10000; // из начального числа вычитаем первую цифру домноженную на количество разрядов, чтобы сделать число пятизначным
    n3 = (num - n1 * 100000 - n2 * 10000) / 1000;
    n4 = (num - n1 * 100000 - n2 * 10000 - n3 * 1000) / 100;
    n5 = (num - n1 * 100000 - n2 * 10000 - n3 * 1000 - n4 * 100) / 10;
    n6 = num % 10;

    if ( (n1 + n2 + n3) == (n4 + n5 + n6) ) {
        std::cout << "Число является 'счастливым' )" << std::endl;
    }
    else {
        std::cout << "Число не является 'счастливым' )" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task17(){

    std::cout << "ЗАДАНИЕ 17" << std::endl;
    int n;
    std::cout << "Введите число копеек" << std::endl;
    std::cin >> n;

    if (n >= 1 and n < 100) {
        if ( n == 1 or n%10 == 1) {
            std::cout << n << " копейка" << std::endl;
        }
        if ( (n >= 2 and n < 5) or (n%10 >= 2 and n %10 < 5)) {
            std::cout << n << " копейки" << std::endl;
        }
        if ( (n >= 5 and n <= 9) or (n % 10 >= 5 and n % 10 <= 9) or (n > 10 and n < 20)) {
            std::cout << n << " копеек" << std::endl;
        }
    }
    else {
        std::cout << "Введено неверное число" << std::endl;
    }
    std::cout << "  " << std::endl;

}

void task18(){

    std::cout << "ЗАДАНИЕ 18" << std::endl;
    int num,n1,n2,n3,n4;
    std::cout << "Введите натуральное четырехзначное число" << std::endl;
    std::cin >> num;

    n1 = num / 1000;
    n2 = (num - n1 * 1000) / 100;
    n3 = (num - n1 * 1000 - n2 * 100) / 10;
    n4 = num % 10;

    if ( n1 == n4 and n2 == n3) {
        std::cout << "Число является палиндромом" << std::endl;
    }
    else {
        std::cout << "Число не является палиндромом" << std::endl;
    }

    std::cout << "  " << std::endl;

}


void task19(){

    std::cout << "ЗАДАНИЕ 19" << std::endl;
    int num,n1,n2,n3, b;
    std::cout << "Введите трехзнчное число" << std::endl;
    std::cin >> num;

    n1 = num / 100;
    n2 = (num - n1 * 100) / 10;
    n3 = num % 10;

    std::cout << "Введите число b" << std::endl;
    std::cin >> b;

    if ((n1 * n2 * n3) > b) {
        std::cout << "19.1  Произведение цифр числа больше числа b" << std::endl;
    }
    else {
        std::cout << "19.1  Произведение цифр числа меньше числа b" << std::endl;
    }

    if ((n1 + n2 + n3) % 7 == 0) { //если остаток от деления на 7 = 0 тогда число кратно 7
        std::cout << "19.2  Сумма цифр числа кратна 7" << std::endl;
    }
    else {
        std::cout << "19.2  Сумма цифр числа не кратна 7" << std::endl;
    }

    std::cout << "  " << std::endl;

}

void task20(){

    std::cout << "ЗАДАНИЕ 20" << std::endl;
    int a,b,c,d;
    std::cout << "Введите стороны a и b первого треугольника" << std::endl;
    std::cin >> a >> b;
    std::cout << "Введите стороны c и d первого треугольника" << std::endl;
    std::cin >> c >> d;

    if (a < c and b < d)  {
        std::cout << "Прямоугольник со сторонами a и b можно поместить в прямоугольник со сторонами c и d" << std::endl;
    }
    else if (a < d and b < c) {
        std::cout << "Прямоугольник со сторонами a и b можно поместить в прямоугольник со сторонами c и d" << std::endl;
    }
    else {
        std::cout << "Прямоугольник со сторонами a и b нельзя поместить в прямоугольник со сторонами c и d" << std::endl;
    }


    std::cout << "  " << std::endl;

}

void task21() {

    std::cout << "ЗАДАНИЕ 21" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "char16_t: " << sizeof(char16_t) << " bytes" << std::endl;
    std::cout << "char32_t: " << sizeof(char32_t) << " bytes" << std::endl;
    std::cout << "short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double: " << sizeof(long double) << " bytes" << std::endl;

}

int main() {
    SetConsoleOutputCP(CP_UTF8);//обращение к библиотеке для вывода на русском языке
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();
    task13();
    task14();
    task15();
    task16();
    task17();
    task18();
    task19();
    task20();
    task21();
    return 0;
}



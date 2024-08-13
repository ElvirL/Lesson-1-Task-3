/*
Задание 3. Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:
• имя и фамилия человека;
• количество денег, которые были выплачены лицу;
• дата выплаты в формате ДД.ММ.ГГГГ.

На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной 
суммой выплат.
Пример данных ведомости

Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019ш

Что оценивается
Корректное отображение общей суммы выплат и самого крупного получателя денежных средств.

Как отправить работу на проверку
Прислать ссылку на repl.it или файл .срр с решением.
*/

#include <fstream>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    ifstream salary_file;
    salary_file.open("salary.txt");

    string name;
    string surname;
    int salary;
    string date;
    int max_salary = 0;
    string name_surname_max_salary;
    int sum_salary = 0;

    while (!salary_file.eof()){
        salary_file >> name;
        salary_file >> surname;
        salary_file >> salary;
        salary_file >> date;
        sum_salary+=salary;

        if (salary > max_salary){
            max_salary = salary;
            name+= " " + surname;
            name_surname_max_salary = name;
        }

    }

    cout << "Общая сумма выплат: " << sum_salary << endl;
    cout << "Максимальная сумма выплат: " << name_surname_max_salary;

}
#include <iostream>
#include "List.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* head = new list;
    head->id = rand() % 20 + 1;
    head->next = NULL;
    build(head);

    cout << "Начальный список выглядит так: " << endl;
    print(head);
    cout << endl;
    system("pause");
    system("cls");

    int sw;
    int flag = 1;
    int el_id;
    int marker;
    while (flag)
    {
        cout << "Выберите действие:" << endl;
        cout << "1.Закончить выполнение программы" << endl;
        cout << "2.Вставить элемент в начало списка" << endl;
        cout << "3.Вставить элемент в список до заданного" << endl;
        cout << "4.Вставить элемент в список после заданного" << endl;
        cout << "5.Вставить элемент в хвост" << endl;
        cout << "6.Удалить первый элемент" << endl;
        cout << "7.Удалить последний элемент" << endl;
        cout << "8.Удалить заданный элемент" << endl;
        cout << "9.В списке из каждой группы подряд идущих одинаковых элементов оставить только один" << endl;
        cout << "10.Показать список" << endl;
        cin >> sw;
        system("cls");

        switch (sw)
        {
            case 1:
                flag = 0;
                break;
            case 2:
                cout << "Какой элемент вы хотите добавить?" << endl;
                cin >> el_id;
                push(&head, el_id);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "Какой элемент вы хотите добавить?" << endl;
                cin >> el_id;
                cout << endl << "До какого элемента вы хотите вставить " << el_id << "?" << endl;
                cin >> marker;
                push_before(&head, marker, el_id);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "Какой элемент вы хотите добавить?" << endl;
                cin >> el_id;
                cout << endl << "После какого элемента вы хотите вставить " << el_id << "?" << endl;
                cin >> marker;
                push_after(head, marker, el_id);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "Какой элемент вы хотите добавить?" << endl;
                cin >> el_id;
                push_tail(head, el_id);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 6:
                pop(&head);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 7:
                pop_last(head);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 8:
                cout << "Какой элемент вы хотите удалить?" << endl;
                cin >> el_id;
                pop_marker(&head, el_id);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 9:
                individual(head);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
            case 10:
                print(head);
                system("cls");
                print(head);
                system("pause");
                system("cls");
                break;
        }

    }


    return 0;
}

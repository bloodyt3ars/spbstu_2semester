using namespace std;
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>


//Отбор(с N до M символа)
//Замена всех первых строчных букв слов прописными.
//Удаление символов сначала строки


string save_or_not(string str, string new_str)
{
    char choice;
    string result;
    input:
    cout << "Хотите сохранить результат?" << endl << "Введите 1, если желает сохранить процесс редактирования. 0, если отменить. " << endl << "Ввод: ";
    cin >> choice;
    if ((choice != '1') && (choice != '0'))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Ввод неверный, попробуйте еще раз." << endl;
        goto input;
    }
    else if (choice == '1')
    {
        result = new_str;
    }
    else if (choice == '0')
    {
        result = str;
    }
    return result;
}


string string_input()
{
    cout << "---------------------------------------------" << endl;
    string input_string;
    cout << "Введите строку для дальнейшей работы с ней" << endl;
    cout << "Ввод: ";
    getline(cin, input_string);
    return input_string;
    cout << "---------------------------------------------" << endl;
}


string selection_from_to(string str)
{
    cout << "---------------------------------------------" << endl;
    int n, m;
    string new_str = str;
    cout << "Вы выбрали п.1. Отбор(с N до M символа)" << endl;
    input1:
    cout << "Введите N. N должен быть меньше M и не меньше 0." << endl<<"Ввод: ";
    cin >> n;
    if ((cin.fail()) || (n < 0))
    {
        cout << "Ввод неверный, попробуйте еще раз" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        goto input1;
    }
    input2:
    cout << "Введите M. M должен быть больше N и не больше " <<size(new_str) << endl << "Ввод: ";
    cin >> m;
    if ((cin.fail()) || (m > size(new_str)) || (m < n))
    {
        cout << "Ввод неверный, попробуйте еще раз" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        goto input2;
    }
    new_str = new_str.substr(n, m);
    cout << "Результат отбора от " << n << " до " << m << " символа(ов): " << new_str << endl;
    str = save_or_not(str, new_str);
    cout << "---------------------------------------------" << endl;
    return str;
}


string first_lowercase_letters_with_uppercase(string str)
{
    cout << "---------------------------------------------" << endl;
    string new_str = str;
    cout << "Вы выбрали п.2. Замена всех первых строчных букв слов прописными" << endl;
    for (int i = 0; i < size(new_str); i++)
    {
        new_str[i] = toupper(new_str[i]);
        while (new_str[i] != ' ' && i < size(new_str))
        {
            i++;
        }
    }
    cout << "Результат замены всех первых строчных букв слов прописными: " << endl << new_str << endl;
    str = save_or_not(str, new_str);
    cout << "---------------------------------------------" << endl;
    return str;
    
}


string deleting_char_from_beginning_line(string str)
{
    cout << "---------------------------------------------" << endl;
    string key;
    string new_str = str;
    cout << "Вы выбрали п.3. Удаление символов сначала строки" << endl;
    input:
    cout << "Введите символ, который хотите удалить: ";
    getline(cin, key);
    if (new_str.find(key)== std::string::npos)
    {
        cout << "Что-то не нашли такого символа..." << endl << "Может попробуем еще раз?" << endl;
        goto input;
    }
    else
    {
        new_str = new_str.erase(new_str.find(key), size(key));
    }
    
    cout << "Результат удаления символов сначала строки: " << endl << new_str << endl;
    str = save_or_not(str, new_str);
    cout << "---------------------------------------------" << endl;
    return str;
}


int main()
{
    string main_string;
    bool bool_var = true;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "---------------------------------------------" << endl;
    cout << "Привет. Ты попал в лабараторную работу номер 10." << endl;
    cout << "Это текстовый редактор. Тут ты сможешь сделать: " << endl;
    cout << "1. Отбор(с N до M символа)" << endl;
    cout << "2. Замена всех первых строчных букв слов прописными" << endl;
    cout << "3. Удаление символа сначала строки" << endl;
    cout << "8. Ввод новой строки." << endl;
    cout << "9. Сохранение текста в файл." << endl;
    cout << "0. Выход из программы." << endl;
    main_string = string_input();
    while (bool_var)
    {
        char choice;
        cout << "Введите номер пункта, который желаете выполнить. Что бы завершить выполнение программы введите 0. " << endl<<"Ввод: ";
        cin >> choice;
        if ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '8') && (choice != '9') && (choice != '0'))
        {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Ввод неверный, попробуйте еще раз." << endl;
        }
        else if (choice == '1')
        {
            cin.ignore(32767, '\n');
            main_string = selection_from_to(main_string);
        }
        else if (choice == '2')
        {
            cin.ignore(32767, '\n');
            main_string = first_lowercase_letters_with_uppercase(main_string);
        }
        else if (choice == '3')
        {
            cin.ignore(32767, '\n');
            main_string = deleting_char_from_beginning_line(main_string);
        }
        else if (choice == '8')
        {
            cin.ignore(32767, '\n');
            main_string = string_input();
        }
        else if (choice == '9')
        {
            cin.ignore(32767, '\n');
            cout << "Вы выбрали сохранение в файл. Он находится в папке с программой." << endl;
            ofstream fout;
            fout.open("my_file.txt");
            if (!fout.is_open())
            {
                cout << "Ошибка открытия файла!" << endl;
            }
            else
            {
                fout << main_string;
            }
            fout.close();
            
        }
        else if (choice == '0')
        {
            cin.ignore(32767, '\n');
            cout << "Спасибо за использование моей программы. До свидания." << endl;
            bool_var = false;
        }
    };
}


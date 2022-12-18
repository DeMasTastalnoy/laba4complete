#include <iostream>
#include <locale>

using namespace std;

void remove(char* exp, unsigned short int* startindex, unsigned short int* count)
{
    unsigned short int i = 0;
    unsigned short int sum = 0;
    while (exp[i] != '*')
    {
        i++;
        sum++;
    }
    char* new_exp = new char[sum + 1];
    for (i = 0; i < sum; i++)
    {
        new_exp[i] = exp[i];
    }
    for (i = *startindex; i < *count + *startindex; i++)
    {
        new_exp[i] = ' ';
    }
    for (i = *startindex; i < sum; i++)
    {
        exp[i] = ' ';
    }
    unsigned short int j;
    for (i = *startindex; i < sum; i++)
    {
        for(j = *startindex;j < sum;j++)
            if (new_exp[j] != ' ')
            {
                swap(exp[i], new_exp[j]);
                i++;
            }
    }
    delete[] new_exp;

}

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned short int startindex;
    unsigned short int count;
    unsigned short int size;
    cout << "Введите длину выражения" << endl;
    cin >> size;
    char* exp = new char[size + 1];
    exp[size] = '*';
    cout << "Введите строку" << endl;
    for (int i = 0; i < size; i++)
        cin >> exp[i];
    cout << "Введите номер начального символа и количество символов" << endl;
    cin >> startindex >> count;
    while (startindex > size || count > (size - startindex))
    {
        startindex = 0;
        count = 0;
        cout << "Повторите ввод" << endl;
        cin >> startindex >> count;
    }
    remove(exp, &startindex, &count);
    cout << endl;
    cout << exp;
    delete[] exp;
    return 0;
}
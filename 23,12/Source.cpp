#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


struct MinValue 
{
    int operator()(const vector<int>& v) const 
    {
        return *min_element(v.begin(), v.end());
    }
};


struct MaxValue
{
    int operator()(const vector<int>& v) const
    {
        return *max_element(v.begin(), v.end());
    }
};


struct SortDescending
{
    void operator()(vector<int>& v) const 
    {
        sort(v.begin(), v.end(), greater<int>());
    }
};


struct SortAscending 
{
    void operator()(vector<int>& v) const 
    {
        sort(v.begin(), v.end());
    }
};


struct IncreaseValues 
{
    int constant;
    IncreaseValues(int c) : constant(c) {}

    void operator()(vector<int>& v) const 
    {
        for (int& x : v) 
        {
            x += constant;
        }
    }
};


struct DecreaseValues 
{
    int constant;
    DecreaseValues(int c) : constant(c) {}

    void operator()(vector<int>& v) const 
    {
        for (int& x : v)
        {
            x -= constant;
        }
    }
};


struct RemoveValue 
{
    int value;
    RemoveValue(int v) : value(v) {}

    void operator()(vector<int>& v) const
    {
        v.erase(remove(v.begin(), v.end(), value), v.end());
    }
};

int main()
{
    vector<int> numbers = { 5, 1, 9, 3, 7, 3, 2, 8, 6 };

    MinValue minValue;
    cout << "Минимальное значение: " << minValue(numbers) << endl;

    MaxValue maxValue;
    cout << "Максимальное значение: " << maxValue(numbers) << endl;

    SortDescending sortDesc;
    sortDesc(numbers);
    cout << "Сортировка по убыванию: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    SortAscending sortAsc;
    sortAsc(numbers);
    cout << "Сортировка по возрастанию: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    IncreaseValues increaseBy5(5);
    increaseBy5(numbers);
    cout << "Увеличение значений на 5: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    DecreaseValues decreaseBy3(3);
    decreaseBy3(numbers);
    cout << "Уменьшение значений на 3: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    RemoveValue removeValue(5);
    removeValue(numbers);
    cout << "Удаление элементов, равных 5: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    return 0;
}

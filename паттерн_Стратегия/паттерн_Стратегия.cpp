#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Реализовать паттерн "Стратегия"
Применить две стратегии сортировки - по возрастанию и по убыванию
*/

// Создание интерфейса для стратегий
class SortStrategy 
{
    public:
    virtual void Sort(vector<int>& list) abstract;
};

// Создание конкретного класса стратегии сортировки по возрастанию
class AscendingSortingStrategy : public SortStrategy {
public:
    void Sort(vector<int>& list) override 
    {
        sort(list.begin(), list.end());
    }
};

// Создание конкретного класса стратегии сортировки по убыванию
class DescendingSortingStrategy : public SortStrategy 
{
    public:
    void Sort(vector<int>& list) override 
    {
        sort(list.rbegin(), list.rend());
    }
};

// Создание класса, который будет применять выбранную стратегию
class SortingContext 
{
    SortStrategy* strategy;
    public:
    SortingContext(SortStrategy* strategy) : strategy(strategy) {}

    void setSortingStrategy(SortStrategy* strategy) 
    {
        this->strategy = strategy;
    }
    void performSort(std::vector<int>& list) 
    {
        strategy->Sort(list);
    }
};
int main() 
{
    setlocale(LC_ALL, "");
    vector<int> list = { 5, 1, 4, 2, 8 };
    cout << "Исходные данные: ";
    for (auto& i : list)
        cout << i << " ";
    cout << endl;
    SortingContext context(new AscendingSortingStrategy());
    context.performSort(list);
    cout << "Сортировка в порядке возрастания: ";
    for (auto& i : list)
        cout << i << " ";
    cout << endl;
    context.setSortingStrategy(new DescendingSortingStrategy());
    context.performSort(list);
    cout << "Сортировка в порядке убывания: ";
    for (auto& i : list)
        cout << i << " ";
    cout << endl;
    return 0;
}
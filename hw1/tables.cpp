#include <iostream>
#include <vector>

struct Table {
    const int np;
    const double tb;
    double avg;

    Table(int num_people, double total_bill) : 
        np(num_people), 
        tb(total_bill)
    {
        if (tb > 0.0) avg = tb/np;
        else avg = 0.0;
    }

    Table() : Table(0, 0.00) {}
};

int main() {
    std::vector<Table> tables = {};
    int num_people = {};
    double total_bill = {};
    std::cout << "Enter the number of people and total bill: " << std::endl;
    while (std::cin >> num_people >> total_bill) {
        Table new_table = Table(num_people, total_bill);
        tables.push_back(new_table);
        std::cout << "avg: " << new_table.avg << std::endl;
    }
    return 0;
}

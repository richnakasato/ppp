#include <iostream>
#include <vector>
#include <iomanip>

struct Table
{
    const int num_customers;
    const double bill, tip;
    double total_bill, avg_bill;

    Table(int num_cust, double bill, double tip) :
        num_customers(num_cust),
        bill(bill),
        tip(tip)
    {
        total_bill = bill + tip;
        if (num_customers) avg_bill = total_bill/num_customers;
        else avg_bill = 0;
    }

    Table() : Table(0, 0.0, 0.0) {}

    void print(void);
};

void Table::print() {
    std::cout << "cust: " << num_customers << std::endl;
    std::cout << "bill: " << total_bill << std::endl;
    std::cout << "avg: " << avg_bill << std::endl;
}

// should be refactored so we dont recalculate EVERYTHING on each iteration
struct TableStats
{
    int total_cust;
    int total_tables;
    double total_bill;
    double total_tip;
    double max_tip;
    double min_tip;

    TableStats(const std::vector<Table> &tables) :
        total_cust(0),
        total_tables(0),
        total_bill(0.0),
        total_tip(0.0),
        max_tip(0.0),
        min_tip(0.0)
    {
        total_tables = tables.size();
        for (auto table : tables) {
            total_cust += table.num_customers;
            total_bill += table.bill;
            total_tip += table.tip;
            if (max_tip == 0 || max_tip < table.tip/table.num_customers)
                max_tip = table.tip/table.num_customers;
            if (min_tip == 0 || min_tip > table.tip/table.num_customers)
                min_tip = table.tip/table.num_customers;
        }
    }

    void print(void);
};

void TableStats::print(void) {
    std::cout << "You have waited on a total of " << total_cust << " people at " << total_tables << " tables" << std::endl;
    std::cout << "The average bill per table is $" <<  total_bill/total_tables << ", and the average bill per person is $" <<  total_bill/total_cust << std::endl;
    std::cout << "The average tip per table is $" <<  total_tip/total_tables << ", and the average tip per person is $" <<  total_tip/total_cust << std::endl;
    std::cout << "The average rate of tipping is $" <<  100*total_tip/total_bill << "%" << std::endl;
    std::cout << "The biggest tip you received was $" <<  max_tip << " per person at the table" << std::endl;
    std::cout << "The smallest tip you received was $" <<  min_tip << " per person at the table" << std::endl;
}

int main() {
    std::vector<Table> tables = {};
    std::cout << "Enter number of customers, bill, and tip:" << std::endl;
    std::cout << std::setprecision(2) << std::fixed;
    int cust;
    double bill, tip;
    while(std::cin >> cust >> bill >> tip) {
        Table temp = {cust, bill, tip};
        if (temp.num_customers && temp.total_bill) {
            tables.push_back(temp);
        }
        TableStats stats = TableStats(tables);
        stats.print();
    }
    return 0;
}

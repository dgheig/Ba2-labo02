#ifndef DATE_H
#define DATE_H

enum class Month {

};

class Date {
    public:
        Date(unsigned day, unsigned month, unsigned year);
        Date(unsigned day, Month month, unsigned year);

    private:
        unsigned _year;
        unsigned _month;
        unsigned _day;
};

#endif

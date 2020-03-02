#include "date.h"

std::ostream& operator<<(std::ostream& os, const Date& date){
    return date.afficher(os);
}
std::ostream & Date::afficher(std::ostream &os) const{
    return os << _day  << "." << _month << "." << _year;
}

bool Date::operator==(const Date &date) const {
    if(this->_year == date._year){
        if(this->_month == date._month){
            if(this->_day == date._day){
                return true;
            }
        }
    }
    return false;
}

bool Date::operator!=(const Date &date) const {
    if(this->_year != date._year){
        if(this->_month != date._month){
            if(this->_day != date._day){
                return true;
            }
        }
    }
    return false;
}

bool Date::operator<(const Date &date) const {
    if(this->_year < date._year){
        if(this->_month < date._month){
            if(this->_day < date._day){
                return true;
            }
        }
    }
    return false;
}

bool Date::operator>(const Date &date) const {
    if(this->_year > date._year){
        if(this->_month > date._month){
            if(this->_day > date._day){
                return true;
            }
        }
    }
    return false;
}

bool Date::operator<=(const Date &date) const {
    return *this == date or *this < date;
}

bool Date::operator>=(const Date &date) const {
    return *this == date or *this > date;
}

Date Date::operator+(int jours) const {

}

Date Date::operator-(int jours) const {

}


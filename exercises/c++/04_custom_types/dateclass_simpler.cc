#include<iostream>
#include<string>
#include <stdbool.h>





enum class mnth : unsigned int { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec , count=12 };

//returns the month after the current one 
mnth month_add(const mnth current_month) {
	if (current_month==mnth::dec) {
			return mnth::jan;
	}
	 else {
		auto out = static_cast<unsigned int>(current_month) + 1;
		return mnth(out);
	}
}

//converts the month into days value, taking leap years into account
unsigned int month_days( const mnth mm, bool leap_year) {
	
	unsigned int out{0};
	
	switch (mm) {
    case mnth::jan:
      	out = 31;
      	break;
    case mnth::feb:
      	out = 28;
		if (leap_year) {++out;};
      	break;
	case mnth::mar:
      	out = 31;
      	break;
	case mnth::apr:
      	out = 30;
      	break;
	case mnth::may:
      	out = 31;
      	break;
	case mnth::jun:
      	out = 30;
      	break;
	case mnth::jul:
      	out = 31;
      	break;
	case mnth::aug:
      	out = 31;
      	break;
	case mnth::sep:
      	out = 30;
      	break;
	case mnth::oct:
     	out = 31;
      	break;
	case mnth::nov:
      	out = 30;
      	break;
	case mnth::dec:
      	out = 31;
      	break;
    default:
      	std::cout << "Warning: unrecognised month." << std::endl;
      	break;
	}
			
			
	return out;
	
}

// overload to print the month as a string
std::ostream& operator<<(std::ostream& os, const mnth& mm) {

	std::string _month = "";
	
	switch (mm) {
    case mnth::jan:
      _month = "January" ;
      break;
    case mnth::feb:
      _month = "February" ;
      break;
	case mnth::mar:
      _month = "March" ;
      break;
	case mnth::apr:
      _month = "April" ;
      break;
	case mnth::may:
      _month = "May" ;
      break;
	case mnth::jun:
      _month = "June" ;
      break;
	case mnth::jul:
      _month = "July" ;
      break;
	case mnth::aug:
      _month = "August" ;
      break;
	case mnth::sep:
      _month = "September" ;
      break;
	case mnth::oct:
      _month = "October" ;
      break;
	case mnth::nov:
      _month = "November" ;
      break;
	case mnth::dec:
      _month = "December" ;
      break;
    default:
     std::cout << "Warning: unrecognised month." << std::endl;
      break;
  }
	
  os << _month;
  return os;
}

//is the current year leap?
bool is_leap( const int y) {
	
	bool out = false;
	
	if ( y%4==0 ) {
		if (y%100 != 0) {
			out = true;
		}
		else if ( y%400==0 ) {
			out = true;
		}
	} 
	
	return out;
}



class Date {
	unsigned int _day;
	mnth _month;
	int _year;
	
	public:
	
	Date(const unsigned int dd, const mnth mm,const int yy) 
		: _day{dd}, _month{mm}, _year{yy} {}
	
	unsigned int day() const {
		return _day;
	}
	
	mnth month() const{
		return _month;	
	}
	
	int year() const{
		return _year;	
	}
	
	void add_days(const unsigned int n) ;
	
	unsigned int Date2days() const ;
		
	
};

bool operator==(const Date& lhs, const Date& rhs) {
	bool out= false;
	if ( (lhs.day() == rhs.day()) && (lhs.month() == rhs.month() ) && (lhs.year() == rhs.year()) ) {
		out=true;
	}
	return out;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return !( lhs==rhs);
}

//convert a Date into an absolute days value
unsigned int Date::Date2days() const {
	
	unsigned int out{_day};
	const bool leap_year{is_leap(_year)};
	
	auto m{mnth::jan};
	while (true) {
		if (m==_month) {break; }
		out += 	month_days(m,leap_year);
		m=month_add(m) ;
	}
	
	return out;
	
}

void Date::add_days(const unsigned int n) {
	
	//this variable will be modified during the script
	unsigned int days_left{n};

	unsigned int end_of_month;
	
	while (days_left>0) {
		end_of_month = month_days(_month, false) - _day ;
			
		//shift the months forward 
		if  ( days_left > end_of_month ) {
			//decrement the days left to add, increment the month
			days_left = days_left - end_of_month;
			_month = month_add(_month ) ;
			//update the days till the end of the month
			end_of_month = month_days(_month, false);
			//pretend we're at "day 0" so once we no longer roll into next month
			//we simply add the days left
			_day = 0;
			//if the new month is january we rolled into next year
			if (_month == mnth::jan) {
				++_year;	
			}
			
		}
		//otherwise just increment the days
		else {
			_day = _day + days_left;	
			days_left = 0;
		}
			
		
		
		
	}
	
}

//print the whole date at once
std::ostream& operator<<(std::ostream& os, const Date & d) {
	os << d.day() << " " << d.month() << " " << d.year();
	return os;
  }




int main() {
	unsigned int dd{21};
	auto mm{mnth::nov};
	int yy{2020};
	Date date1{dd,mm,yy};
	
	//test date printout, colective and per element
	std::cout << "Date 1 : " << date1 <<std::endl;
	std::cout << date1.day() << std::endl ;
	std::cout << date1.month() << std::endl ;
	std::cout << date1.year() << std::endl ;
	
	//test functions
	std::cout << "Date 1 is day " << date1.Date2days() << " of the year." << std::endl;
	std::cout << "The month after " << date1.month() << " is " << month_add(date1.month()) << std::endl;
	
	//test day addition
	Date date2 = date1;
	date2.add_days(41);
	std::cout << "Date 2 : " << date2 <<std::endl;
	
	//test leap years
	for (int i=yy; i<2110; i+=4) {
		//std::cout << "Is " << i << " leap? : " << is_leap(i)  << std::endl ;	
	}
	
	
	bool comp1 = ( date1 != date2);
	bool comp2 = ( date1 == date1);
	
	std::cout << comp1 << std::endl;
	std::cout << comp2 << std::endl;
	
	Date date3{16,mnth::feb,2029};
	
	std::cout << "Date 3 : " << date3 <<std::endl;
	std::cout << is_leap(date3.year() ) <<std::endl;
	
	return 0;
	
	
}
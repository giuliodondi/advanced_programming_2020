#include<iostream>
#include<string>
#include <stdbool.h>





enum class mnth : unsigned int { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec , count=12 };

//returns the month after or before the current one based on a switch
//switch ==1 is forwards, -1 is backwards
mnth month_add_sub(const mnth current_month, int swch) {
	if (abs(swch) != 1 ) {
		std::cout << "Error : undefined switch for month subtraction/addition.\n" <<
			" Please use -1 to subtract a month and 1 to add a month." << std::endl;
	} else {
		if (swch == 1 && current_month==mnth::dec) {
				return mnth::jan;
		}
		else if (swch == -1 && current_month==mnth::jan) {
				return mnth::dec;
		} else {
			auto out = static_cast<unsigned int>(current_month) + swch;
			return mnth(out);
		}
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

//returns the length of the year, taking leap years into account
unsigned int year_length (unsigned int y, bool leap_year) {
	
	if (leap_year) {
		return 366;
	} else {
		return 365;
	}

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
	
	unsigned int Date2days();
	
	
	//print the whole date at once
	friend std::ostream& operator<<(std::ostream& os, const Date & d) {
		os << d._day << " " << d._month << " " << d._year;
		return os;
	  }
	
	
	
};

bool operator==(const Date& lhs, const Date& rhs) {
	bool out= false;
	if ( (lhs.day() == rhs.day()) && (lhs.month() == rhs.month() ) && (lhs.year() == rhs.year()) ) {
		out=true;
	}
	return out;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	bool out= true;
	if ( (lhs.day() == rhs.day()) && (lhs.month() == rhs.month() ) && (lhs.year() == rhs.year()) ) {
		out=false;
	}
	return out;
}

//convert a Date into an absolute days value
unsigned int Date::Date2days() {
	
	unsigned int out{_day};
	bool leap_year{is_leap(_year)};
	
	auto m{mnth::jan};
	while (true) {
		if (m==_month) {break; }
		out += 	month_days(m,leap_year);
		m=month_add_sub(m,1) ;
	}
	
	return out;
	
}

void Date::add_days(const unsigned int n) {
	
	//this variable will be modified during the script
	int days_left{n};
	unsigned int abs_days_left;
	
	bool forwards;
	bool leap_year;
	bool month_pre_leap{ (_month==mnth::jan) || (_month==mnth::feb) };
	
	unsigned int till_end_year;
	unsigned int till_end_month;
	
	
	while (days_left!=0) {
		abs_days_left = abs(days_left);
		forwards = (days_left>0);
		
		if (forwards) {
			till_end_year = year_length(_year,false) - Date2days(); 
		} else {
			till_end_year = Date2days() - 1;
		}
		
		std::cout << "2 end of year:" << till_end_year << std::endl;
		
		
		if (abs_days_left > till_end_year ) {
			if (forwards) {
				days_left = days_left - year_length(_year,false);
				++_year;
			} else {
				--_year;
				days_left = days_left + year_length(_year,false);
			}
			
			std::cout << days_left << std::endl;
			
		} else {
			//based on whether we need to move in the past or future
			//we determing the number of days that separate us to prev or next month
			
			if (forwards) {
				till_end_month = month_days(_month, false) - _day;
			} else {
				till_end_month = _day -1;
			}
			
			std::cout << "2 end of month:" << till_end_month << std::endl;
			
			//shift the months forward or backwards
			if  ( abs_days_left > till_end_month ) {
				if (forwards) {
					days_left = days_left - month_days(_month, false);
					_month = month_add_sub(_month, 1 ) ;
				} else {
					_month = month_add_sub(_month, -1 ) ;
					days_left = days_left + month_days( _month, false);	
				}
				std::cout << days_left << std::endl;
			}
			//otherwise just increment the days
			else {
				_day = _day + days_left;	
				days_left = 0;
			}
			
		}
		
		
	}
	
}




int main() {
	unsigned int dd{21};
	auto mm{mnth::nov};
	int yy{2019};
	Date date1{dd,mm,yy};
	
	//test date printout, colective and per element
	std::cout << "Date 1 : " << date1 <<std::endl;
	std::cout << date1.day() << std::endl ;
	std::cout << date1.month() << std::endl ;
	std::cout << date1.year() << std::endl ;
	
	//test functions
	std::cout << "Date 1 is day " << date1.Date2days() << " of the year." << std::endl;
	std::cout << "The month before " << date1.month() << " is " << month_add_sub(date1.month(),-1) << std::endl;
	std::cout << "The month after " << date1.month() << " is " << month_add_sub(date1.month(),1) << std::endl;
	
	//test day addition
	Date date2 = date1;
	date2.add_days(-325);
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
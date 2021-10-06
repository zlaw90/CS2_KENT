#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp"

////////////////////////////////////////////////////////////
class Date {
public:
            Date()  {};
            Date(String, String, int);

    String  getDay()                   const { return day   ; };
    String  getMonth()                 const { return month ; };
    int     getYear()                  const { return year  ; };
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
            Time(int, int, int);
    int     getHour()                  const{ return hour   ; };
    int     getSecond()                const{ return second ; };
    int     getMinute()                const{ return minute ; };
  private:
    int     hour, minute, second;
};

////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);

  String    getHost    ()              const{ return host;           };
  int       getNumBytes()              const{ return number_of_bytes; };
  friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

//131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625
//             0 1 2             0  1  2 3      4    5        6         7   8    9
//   ip                       date    time                request      status  #bytes
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

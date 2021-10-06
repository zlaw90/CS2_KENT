//
//
// File:        logentry.cpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "logentry.hpp"

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
LogEntry::LogEntry(String s)
{
  // ...
  std::vector<String> fullVec = s.split(' ');
  //std::cout << fullVec.size() << '\n';
  //std::cout << s << '\n';
  /*if(fullVec.size() != 9)
  {
    fullVec.clear();
    host = "null";
  }*/

  if(fullVec.size() == 10)
  {
    std::vector<String> timeVec = fullVec[3].split(':');
    std::vector<String> dateVec = timeVec[0].split('/');
    host = fullVec[0];
    date = Date(dateVec[0], dateVec[1], dateVec[2].convToInt());
    time = Time(timeVec[1].convToInt(), timeVec[2].convToInt(), timeVec[3].convToInt());
    request = fullVec[5] + fullVec[6] + fullVec[7];
    status = fullVec[8];
    number_of_bytes = fullVec[9].convToInt();
  }
}


std::ostream& operator<<(std::ostream& out, const LogEntry& log)
{
  /*if(log.host == "null")
  {
    out << "Invalid LogEntry, continuing." << '\n';
    return out;
  }*/

  out << "Host: " << log.host << ", Date: " << log.date.getMonth() << " " << log.date.getDay();
  out << ", " << log.date.getYear() << ", Time: " << log.time.getHour() <<":";
  out << log.time.getMinute() << ":" << log.time.getSecond() << ", Request: ";
  out << log.request << ", Status: " << log.status << ", Bytes: "<< log.number_of_bytes;
  out << std::endl;


  return out;
}

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
std::vector<LogEntry> parse(std::istream& in)
{
  std::vector<LogEntry> result;
  String tmp;
  while (!in.eof())
  {
    tmp = tmp.getLine(in);
    LogEntry newLog(tmp);

    if(!in.eof()) { result.push_back(newLog); }
  }
  return result;
}

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
void output_all(std::ostream& out, const std::vector<LogEntry>& logVec)
{
  for(unsigned int i = 0; i < logVec.size(); ++i)
  {
    out << logVec[i] << std::endl;
  }
}

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logVec)
{
  for(unsigned int i = 0; i < logVec.size(); ++i)
  {
    /*if(logVec[i].getHost() == "null")
    {
      std::cout << "Invalid LogEntry, continuing." << '\n';
      continue;
    }*/
    out << "Host member: " << logVec[i].getHost() << std::endl;
  }
}

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
int byte_count(const std::vector<LogEntry> & logVec)
{
  int byteCount = 0;
  for(unsigned int i = 0; i < logVec.size(); ++i)
  {
    /*if(logVec[i].getHost() == "null") { continue; }*/
    byteCount += logVec[i].getNumBytes();
  }
  return byteCount;
}
////////////////////////////////////////////////////////////
Time::Time(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

///////////////////////////////////////////////////////////
Date::Date(String d, String m, int y)
{
  std::vector<String> dayVec = d.split('[');
  day = dayVec[1];
  month = m;
  year = y;
}

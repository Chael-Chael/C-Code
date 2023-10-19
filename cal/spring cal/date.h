#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

// **************************************
// Functions used in this program
// **************************************
//

//Functions on different year
int isleapyear(int year);
int getDaySeqOnJan1(int year);

// Functions about month and day
int  getMonthLength(int month);
int  getDaySeq(int month, int day);
//
// Functions for properties of one day
int  getMonth(int daySeqOfYear);
int  getDay(int daySeqOfYear);
int  getDaySeqOfWeek(int daySeqOfYear);
//
// Functions for day movement calculation
int  getNextMonday(int daySeqOfYear);
int  getThisSunday(int daySeqOfYear);
//
// Functions support school calendar display
void printOneDay(int daySeqOfYear);


#endif // DATE_H_INCLUDED

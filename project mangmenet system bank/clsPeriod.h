#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;
    clsPeriod() {}
    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = DateTo;
    }
    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();

        cout << "Period End: ";
        EndDate.Print();
    }

    static int PeriodLengthInDays(clsPeriod Period, bool IncludeEnDay = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEnDay);
    }
    static  bool IsDateInPeriod(clsDate Date, clsPeriod Period)
    {
        if (clsDate::CompareDates(Date, Period.StartDate) == clsDate::After && clsDate::CompareDates(Date, Period.EndDate) == clsDate::Before)
        {
            return true;
        }

        return (clsDate::CompareDates(Date, Period.StartDate) == clsDate::Equal);
    }
    static  bool IsDateInPeriod(clsDate Date, clsDate From, clsDate To)
    {
        return !(clsDate::CompareDates(Date, From) == clsDate::Before ||
            clsDate::CompareDates(Date, To) == clsDate::After);
    }
    static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {

            while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateInPeriod(Period1.StartDate, Period2))
                {
                    OverlapDays++;
                }

                Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
            }
        }
        else
            while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (IsDateInPeriod(Period2.StartDate, Period1))
                    OverlapDays++;
                Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
            }
        return OverlapDays;
    }

};





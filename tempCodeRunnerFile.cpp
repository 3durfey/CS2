
            }

        }

};

int main()

{
    int day, month, year;
    cout << "Enter day in the form Month/Day/Year: ";
    while(!(cin >> month))
    {
        validate("entire date");
    }
    cin.ignore(1); 
    while(!(cin >> day))
    {
        validate("day and year");
    }
    cin.ignore(1);
    while(!(cin >> year))
    {
        validate("year");
    }
    date userdate(day, month, year);


}
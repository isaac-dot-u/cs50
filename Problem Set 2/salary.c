#include <stdio.h>

// Script to work out my new recurring fortnightly paycheck

int main(void)
{
    float old_salary = 2449.78;
    // Fortnightly after tax

    float catchup_salary = 2865.76;
    // First paycheck with raise, backdated to 1 July

    int days_passed = 23 + 21 + 5;
    // Working days since 1 July

    float old_pd = 2449.78/10;
    float extra_pd = (catchup_salary - old_salary)/days_passed;
    // Pay per business day

    float new_pd = old_pd + extra_pd;
    float new_salary = new_pd * 10;
    // Calculate new fortnightly pay

    printf("Old salary: %f\n", old_salary);
    printf("Extra pay per day: %f\n", extra_pd);
    printf("New salary: %f\n", new_salary);

}

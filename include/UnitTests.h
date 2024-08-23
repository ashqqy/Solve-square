#ifndef UNIT_TESTS
#define UNIT_TESTS

struct UnitData 
    {
    int test_num;
    double a, b, c;
    double x1_exp, x2_exp;
    int num_roots_exp;
    };

int UnitTest (UnitData unit_data);
void AllUnitTests ();

#endif //UNIT_TESTS

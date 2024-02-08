#include "pch.h"
#include "../hamhanded/hamhanded.h"

//TEST(hhCalcOld, Operations) {
//	EXPECT_EQ(12, hhCalcOld("125-5/10"));
//	EXPECT_EQ(260, hhCalcOld("125+5*2"));
//}
//TEST(hhCalcOld, CheckDoubleAndMoreSignSymbols) {
//	EXPECT_EQ(-1, hhCalcOld("10+-35-2"));
//}
//TEST(hhCalcOld, CheckOtherSymbols) {
//	EXPECT_EQ(362, hhCalcOld("10+35$2"));
//	EXPECT_EQ(-1, hhCalcOld("3#%@4+48"));
//}

TEST(hhCalc, MultiPriority) {
	EXPECT_EQ(hhCalc("2*3+6-4/2-2+2"), 10);
	EXPECT_EQ(hhCalc("2+3+6-4/2-2+2"), 9);
	EXPECT_EQ(hhCalc("5+2+2*2*2-10"), 5);
}
TEST(hhCalc, MultyPriorityFloat) {
	EXPECT_NEAR(hhCalcFloat("1232.64+3.3999999999+6.73-4.2567/2.93333-2.1+2.2"), 1232.64 + 3.3999999999 + 6.73 - 4.2567 / 2.93333 - 2.1 + 2.2, 0.000001);
	EXPECT_NEAR(hhCalcFloat("5.321+2.6+2.38888*9992.2333333*2.123456789-10.9"), 5.321 + 2.6 + 2.38888 * 9992.2333333 * 2.123456789 - 10.9, 0.000001);
}

// Need to do else
//TEST(hhCalc, MultiPriority) {
//	EXPECT_EQ(hhCalc("0b101+0x2Ab0F*02/10-2+2"), 40);
//}
//
//TEST(hhCalc, hhCalcAddFloat) {
//	EXPECT_EQ(hhCalcAddFloat("add(1.234, 2.345,  34.456, 23.45)"), 40);
//}
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
	EXPECT_EQ(hhCalcFloat("2.6+3.3+6.7-4.2/2.9-2.1+2.2"), 2.6 + 3.3 + 6.7 - 4.2 / 2.9 - 2.1 + 2.2);
	EXPECT_EQ(hhCalcFloat("5.3+2.6+2.3*2.2*2.1-10.9"), 5.3 + 2.6 + 2.3 * 2.2 * 2.1 - 10.9);
}

// Need to do else
//TEST(hhCalc, MultiPriority) {
//	EXPECT_EQ(hhCalc("0b101+0x2Ab0F*02/10-2+2"), 40);
//}
//
//TEST(hhCalc, hhCalcAddFloat) {
//	EXPECT_EQ(hhCalcAddFloat("add(1.234, 2.345,  34.456, 23.45)"), 40);
//}
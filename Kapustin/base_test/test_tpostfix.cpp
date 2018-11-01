#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, correct_string_works_right)
{
    const string p = "2+2";
    TPostfix bf;
    EXPECT_FALSE(bf.isCorrect(p+"++++2"));
}
TEST(TPostfix, postfix_form_works_correct)
{
    const string bf = "2+2";
    const string expbf = "2 2 + ";
    TPostfix pf;
    pf.toPostfix(bf);
    EXPECT_EQ(expbf, pf.getPostfix());
}
TEST(TPostfix, cannot_postfix_incorrect_string)
{
    const string bf = "2++2";
    TPostfix pf;
    ASSERT_ANY_THROW(pf.toPostfix(bf););
}
TEST(TPostfix, calculate_works_correct)
{
    const string bf = "2+2";
    TPostfix pf;
    pf.toPostfix(bf);
    const double expbf = 4;
    EXPECT_EQ(expbf, pf.calculate());
}
TEST(TPostfix, calculate_works_correct2)
{
    const string bf = "1+2+3*2-1";
    TPostfix pf;
    pf.toPostfix(bf);
    const double expbf = 8;
    EXPECT_EQ(expbf, pf.calculate());
}


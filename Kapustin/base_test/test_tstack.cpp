#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, cannot_create_negative)
{

    ASSERT_ANY_THROW(TStack<int> st(-2));
}
TEST(TStack, can_create_too_large)
{
    ASSERT_ANY_THROW(TStack<int> st(1000));
}
TEST(TStack, is_created_stack_is_empty)
{
    TStack<int> st();
    EXPECT_TRUE(1, st.isEmpty());
}
TEST(TStack, filled_stack_is_full)
{
    TStack<int> st(1);
    st.push_back(2);
    EXPECT_TRUE(1, st.isFull());
}
TEST(TStack, push_back_adds_an_element)
{
    TStack<int> st(1);
    st.push_back(2);
    EXPECT_EQ(2, st.top());
}
TEST(TStack, push_back_changes_size)
{
    TStack<int> st(2);
    st.push_back(2);
    st.push_back(1);
    EXPECT_EQ(2, st.GetSize());
}
TEST(TStack, push_does_nothing_when_stack_is_full)
{
    TStack<int> st(2);
    st.push_back(2);
    st.push_back(1);
    ASSERT_NO_THROW(st.push_back(10));
    EXPECT_TRUE(1, st.top());
}
TEST(TStack, pop_deletes_top_element)
{
    TStack<int> st(2);
    st.push_back(2);
    st.push_back(1);
    st.pop();
    EXPECT_EQ(1, st.GetSize());
}
TEST(TStack, pop_returns_top_element)
{
    TStack<int> st(2);
    st.push_back(2);
    st.push_back(10);
    EXPECT_EQ(10, st.pop());
}
TEST(TStack, pop_doesnt_throw_when_stack_is_empty)
{
    TStack<int> st(1);
    st.push_back(2);
    ASSERT_NO_THROW(st.pop());
}
TEST(TStack, top_gives_correct_elem)
{
    TStack<int> st(1);
    st.push_back(2);
    EXPECT_EQ(2,st.top());
}
TEST(TStack, top_doesnt_remove_elem)
{
    TStack<int> st(2);
    st.push_back(2);
    st.push_back(10);
    st.top();
    EXPECT_EQ(10, st.top());
}


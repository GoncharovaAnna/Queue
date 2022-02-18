#include "../Queue/TQueue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int>(10));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int>(-10));
}

TEST(TQueue, queue_after_creating_is_empty)
{
  TQueue<int> aQueue(10);
  ASSERT_EQ(aQueue.IsEmpty(), true);
}

TEST(TQueue, can_push_element_to_empty_queue)
{
  TQueue<int> aQueue(10);
  ASSERT_NO_THROW(aQueue.Push(1));
}

TEST(TQueue, can_push_element_to_nonfull_queue)
{
  TQueue<int> aQueue(2);
  aQueue.Push(1);
  ASSERT_NO_THROW(aQueue.Push(1));
}

TEST(TQueue, cant_push_element_to_full_queue)
{
  TQueue<int> aQueue(1);
  aQueue.Push(1);
  ASSERT_ANY_THROW(aQueue.Push(1));
}

TEST(TQueue, cant_pop_element_from_empty_queue)
{
  TQueue<int> aQueue(10);
  ASSERT_ANY_THROW(aQueue.Pop());
}
TEST(TQueue, can_push_and_pop)
{
  TQueue<int> aQueue(10);
  aQueue.Push(10);
  ASSERT_EQ(aQueue.Pop(), 10);
}

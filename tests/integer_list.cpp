#include <gtest/gtest.h>
#include <linkedlist.hpp>

class IntegerListTests : public testing::Test
{
public:	
	LinkedList<int> integerList;

	virtual void SetUp()
	{
		integerList.clear();
	}

	virtual void TearDown()
	{
	}

};

TEST_F(IntegerListTests, IntegersCanBeAddedToTheList)
{
	//given:
	int number = 32;
	
	//when:
	integerList.addLast(number);

	//then:
	EXPECT_EQ(integerList.size(), 1);
	EXPECT_EQ(integerList.get(0), number);
	EXPECT_EQ(integerList.getFirst(), number);
	EXPECT_EQ(integerList.getLast(), number);
}

TEST_F(IntegerListTests, IntegersCanBeRemovedFromTheList)
{
	//given:
	int number = 32;
	
	//when:
	integerList.addLast(number);
	integerList.addLast(10); // Will be removed
	integerList.remove(1);

	//then:
	EXPECT_EQ(integerList.size(), 1);
	EXPECT_EQ(integerList.get(0), number);
	EXPECT_EQ(integerList.getFirst(), number);
	EXPECT_EQ(integerList.getLast(), number);
}

TEST_F(IntegerListTests, ListCanBeIteratedToRetrieveEveryElement)
{
	//given:
	int first = 32;
	int last = 40;
	
	//when:
	for (int i = first; i <= last; i++)
	{
		integerList.addLast(i);
	}

	//then:
	EXPECT_EQ(integerList.size(), 9);
	for (int i = first; i <= last; i++)
	{
		EXPECT_EQ(integerList.get(i - first), i);
	}

	EXPECT_EQ(integerList.get(0), first);
	EXPECT_EQ(integerList.getFirst(), first);
	EXPECT_EQ(integerList.getLast(), last);
	EXPECT_EQ(integerList.get(integerList.size() - 1), last);
}

TEST_F(IntegerListTests, IntegerListCanBeCleared)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);

	//when:
	integerList.clear();

	//then:
	EXPECT_EQ(integerList.size(), 0);
}

TEST_F(IntegerListTests, IntegerListCanBeDeepCopied)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);

	//when:
	// This calls the copy constructor of the linked list. LinkedList(LinkedList& list)
	LinkedList<int> copy = integerList;

	// This calls the assignment operator of the linked list. LinkedList& operator=(LinkedList& list)
	LinkedList<int> copy2; copy2 = integerList;

	//then:
	EXPECT_EQ(integerList.size(), copy.size());
	EXPECT_EQ(integerList.get(0), copy.get(0));
	EXPECT_EQ(integerList.get(1), copy.get(1));

	EXPECT_EQ(integerList.size(), copy2.size());
	EXPECT_EQ(integerList.get(0), copy2.get(0));
	EXPECT_EQ(integerList.get(1), copy2.get(1));
}

TEST_F(IntegerListTests, IntegerListShiftRightTest)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);
	integerList.addLast(50);
	integerList.addLast(60);
	integerList.addLast(70);
	integerList.addLast(80);
	integerList.addLast(90);
	integerList.addLast(100);

	//when:
	// This is a cyclic shift right. Basically it just moves the last element to the first position.
	integerList.shiftr(3);

	//then:
	EXPECT_EQ(integerList.size(), 8);
	EXPECT_EQ(integerList.get(0), 80);
	EXPECT_EQ(integerList.get(1), 90);
	EXPECT_EQ(integerList.get(2), 100);
	EXPECT_EQ(integerList.get(3), 32);
	EXPECT_EQ(integerList.get(4), 40);
	EXPECT_EQ(integerList.get(5), 50);
	EXPECT_EQ(integerList.get(6), 60);
	EXPECT_EQ(integerList.get(7), 70);
}

TEST_F(IntegerListTests, IntegerListShiftLeftTest)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);
	integerList.addLast(50);
	integerList.addLast(60);
	integerList.addLast(70);
	integerList.addLast(80);
	integerList.addLast(90);
	integerList.addLast(100);

	//when:
	// This is a cyclic shift left. Basically it just moves the first element to the last position.
	integerList.shiftl(3);

	//then:
	EXPECT_EQ(integerList.size(), 8);
	EXPECT_EQ(integerList.get(0), 60);
	EXPECT_EQ(integerList.get(1), 70);
	EXPECT_EQ(integerList.get(2), 80);
	EXPECT_EQ(integerList.get(3), 90);
	EXPECT_EQ(integerList.get(4), 100);
	EXPECT_EQ(integerList.get(5), 32);
	EXPECT_EQ(integerList.get(6), 40);
	EXPECT_EQ(integerList.get(7), 50);
}

TEST_F(IntegerListTests, IntegerListChopLeft)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);
	integerList.addLast(50);
	integerList.addLast(60);

	//when:
	integerList.chopLeft(2);

	//then:
	EXPECT_EQ(integerList.size(), 2);
	EXPECT_EQ(integerList.get(0), 50);
	EXPECT_EQ(integerList.get(1), 60);
}

TEST_F(IntegerListTests, IntegerListChopRight)
{
	//given:
	integerList.addLast(32);
	integerList.addLast(40);
	integerList.addLast(50);
	integerList.addLast(60);

	//when:
	integerList.chopRight(1);

	//then:
	EXPECT_EQ(integerList.size(), 2);
	EXPECT_EQ(integerList.get(0), 32);
	EXPECT_EQ(integerList.get(1), 40);
}

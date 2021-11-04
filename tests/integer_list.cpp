#include <gtest/gtest.h>
#include <LinkedList.hpp>

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

TEST_F( IntegerListTests, IntegersCanBeAddedToTheList )
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

TEST_F( IntegerListTests, IntegersCanBeRemovedFromTheList )
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

TEST_F( IntegerListTests, ListCanBeIteratedToRetrieveEveryElement )
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
	EXPECT_EQ(integerList.get(0), first);
	EXPECT_EQ(integerList.getFirst(), first);
	EXPECT_EQ(integerList.getLast(), last);

	for (int i = first; i <= last; i++)
	{
		EXPECT_EQ(integerList.get(i - first), i);
	}
}
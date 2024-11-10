#include "pch.h"
#include "CppUnitTest.h"
#include "../PDC_LAB9/source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInitializeGraph)
		{
			initializeGraph();

			for (int i = 0; i < MAX_VERTICES; ++i) {
				Assert::AreEqual(0, edgeCount[i]);
				Assert::IsFalse(visited[i]);
				Assert::AreEqual(0, bfsNumber[i]);
			}
		}

		TEST_METHOD(TestAddEdge)
		{
			initializeGraph();

			addEdge(0, 1);
			addEdge(1, 2);

			Assert::AreEqual(1, edgeCount[0]);
			Assert::AreEqual(2, edgeCount[1]);
			Assert::AreEqual(1, edgeCount[2]);

			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(0, adjList[1][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
		}

		TEST_METHOD(TestLoadGraphFromFile)
		{
			initializeGraph();

			ofstream testFile("test_graph.txt");
			testFile << "0 1\n";
			testFile << "1 2\n";
			testFile.close();

			loadGraphFromFile("test_graph.txt");

			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
		}

		TEST_METHOD(TestBreadthFirstSearch)
		{
			initializeGraph();
			addEdge(0, 1);
			addEdge(0, 2);
			addEdge(1, 3);
			addEdge(1, 4);
			addEdge(2, 5);
			addEdge(3, 6);

			breadthFirstSearch(0);

			Assert::AreEqual(1, bfsNumber[0]);
			Assert::AreEqual(2, bfsNumber[1]);
			Assert::AreEqual(3, bfsNumber[2]);
			Assert::AreEqual(4, bfsNumber[3]);
			Assert::AreEqual(5, bfsNumber[4]);
			Assert::AreEqual(6, bfsNumber[5]);
			Assert::AreEqual(7, bfsNumber[6]);

			for (int i = 0; i < 7; ++i) {
				Assert::IsTrue(visited[i]);
			}
		}
	};
}

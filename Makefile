all:

	clang++-5.0 src/main.cpp src/LinkList.cpp src/Node.cpp src/BinaryTree.cpp src/Utilities.cpp -g -std=c++17 -o bin/algmet.out

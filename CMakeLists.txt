cmake_minimum_required(VERSION 3.16)
project(lists_angelicasanchezbarreto)

set(CMAKE_CXX_STANDARD 11)

include_directories(mock)
include_directories(structures)
include_directories(structures/lists)
include_directories(structures/lists/iterators)
include_directories(test)

add_executable(lists_angelicasanchezbarreto
    mock/mocker.cpp
    mock/mocker.h
    structures/lists/iterators/bidirectional_iterator.h
    structures/lists/iterators/forward_iterator.h
    structures/lists/circular.h
    structures/lists/forward.h
    structures/lists/linked.h
    structures/lists/list.h
    structures/lists/node.h
    structures/queue.h
    structures/stack.h
    test/tester.cpp
    test/tester.h
    main.cpp)

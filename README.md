
My solutions for
[Baekjoon](https://www.acmicpc.net/),
[leetcode](https://leetcode.com/problemset/all/),
[programmers](http://programmers.co.kr/learn/challenges)
problems

```shell
$ ./run.sh [cpp file path]
$ ./run.sh "leetcode/728. Self Dividing Numbers.cpp" # example
```

# Know-How

1. main 함수 맨 앞에 `ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);`를 붙여주면 빨라진다!
1. `ios::sync_with_stdio(false)`를 쓰면 stdio 함수를 쓰면 안 된다! (pringf, scanf, getchar 등등)
1. 2차원 배열에서 근접 요소를 살필때 `int neighbors[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}`을 이용하면 코드가 깔끔해진다!
1. `std::endl`은 느리다. 따라서 코드 위에 `#define endl "\n"`을 해주면 빨라진다!
1. string에서 []로 접근하는 것 보다 int array에서 []로 접근하는게 빠르니 웬만하면 int array로 변환해주는게 좋다!

# Binary Search

- The painter’s partition problem: 배열을 N개로 자른 후 각 부분 배열의 합의 최솟값을 구하는 문제
  - https://www.acmicpc.net/problem/2343
  - https://www.geeksforgeeks.org/painters-partition-problem/
  - 비슷한 문제
    - https://www.acmicpc.net/problem/13397

# Dynamic Programming

- Circular DP: 1번째 값과 N번째 값을 인접했다고 본다.
  - https://www.acmicpc.net/problem/17404

# Graph

- [연결 요소의 개수 구하기](https://www.acmicpc.net/problem/11724): DFS, BFS를 visit 배열이 전부 true가 될 때 까지 반복
- [이분그래프 판별](https://www.acmicpc.net/problem/1707): DFS, BFS로 빨강 파랑 칠해가면서 해결
- [unweighted undirected graph의 MST](https://programmers.co.kr/learn/courses/30/lessons/49189?language=cpp): BFS
- 위상 정렬
  - https://www.acmicpc.net/problem/2252
  - https://www.acmicpc.net/problem/1766
  - https://www.acmicpc.net/problem/2056
  - https://www.acmicpc.net/problem/1516
- 플로이드 워셜 알고리즘: 모든 정점에서 모든 정점으로의 최단 비용 O(n^3)
  - [프로그래머스 - 순위](https://programmers.co.kr/learn/courses/30/lessons/49191)
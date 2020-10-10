# GeeksforGeeks - Dynamic Programming

### Basic Problems

1. [Link](https://www.geeksforgeeks.org/ugly-numbers/) 약수가 2, 3, 5로만 이루어진 수 중에 N번째로 큰 수 찾기
1. [피보나치 수](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/)
1. [카탈란 수](https://www.geeksforgeeks.org/program-nth-catalan-number/)
    - [정의](https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98)
    - N개의 노드로 만들 수 있는 이진 트리 수
    - N+2각형을 삼각형으로 자를 수 있는 경우의 수
    - 한 변의 길이가 N인 Grid에서 대각선을 지나지 않고 반대쪽 끝으로 갈 수 있는 경우의 수
    - [기타등등](https://www.geeksforgeeks.org/applications-of-catalan-numbers/)
1. [Link](https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/) 크기가 N인 집합을 분할할 수 있는 경우의 수 ([벨 수](https://ko.wikipedia.org/wiki/%EB%B2%A8_%EC%88%98))
1. [Link](https://www.geeksforgeeks.org/binomial-coefficient-dp-9/) 이항계수의 점화식 (nCr), 파스칼의 삼각형
1. [Link](https://www.geeksforgeeks.org/permutation-coefficient/) 순열계수의 점화식 (nPr)
1. [Link](https://www.geeksforgeeks.org/tiling-problem/) 2x1 크기의 타일을 2xN 크기의 바닥에 붙이는 가짓수 (=피보나치)
1. [Link](https://www.geeksforgeeks.org/gold-mine-problem/) 2차원 배열에서 한 변에서 다른 변으로 가는 경로의 가중치의 최댓값
1. [동전 교환 문제](https://www.geeksforgeeks.org/coin-change-dp-7/)
    - M원을 금액이 다른 N개의 동전으로 만들 수 있는 가짓수
    - N개의 동전으로 M원을 만들 수 있는 가짓수 = N개의 동전으로 (M-n)원을 만들 수 있는 가짓수 + (N-1)의 동전으로 M원을 만들 수 있는 가짓수 (여기서 n은 가장 큰 금액)
1. [Link](https://www.geeksforgeeks.org/friends-pairing-problem/) n명을 1명 또는 2명씩 묶어주는 경우의 수
    - 점화식: f(n) = f(n - 1) + (n - 1) * f(n - 2)
1. 
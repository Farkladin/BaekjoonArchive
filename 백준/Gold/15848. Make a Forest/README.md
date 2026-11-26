# [Gold I] Make a Forest - 15848 

[문제 링크](https://acmicpc.net/problem/15848) 

### 성능 요약

메모리: 26768 KB, 시간: 180 ms

### 분류

자료 구조, 그리디, 정렬

### 제출 일자

2026년 11월 26일 16:43:57

### 문제 설명

<p>In 1736, Leonhard Euler wrote a paper on the Seven Bridges of Königsberg which is regarded as the first paper in the history of graph theory. Nowadays, the study of graph theory is considered very important as indicated by the fact that most textbooks in discrete mathematics have a chapter on graph theory.</p>

<p>This problem is related to graph theory, especially on tree and forest. Given N tuples (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>), your task is to construct a forest with a minimum number of trees which satisfies the following seven requirements:</p>

<ol>
	<li>Each tree in the forest is a rooted tree;</li>
	<li>Each node x in the forest has a value x.A;</li>
	<li>Each edge (x, y) in the forest has a value (x, y).B;</li>
	<li>Each tuple (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>) appears exactly once in the forest as two nodes with a parent-child relationship (parent node p and child node c) where: u<sub>i</sub> = p.A, v<sub>i</sub> = c.A, and w<sub>i</sub> = (p, c).B;</li>
	<li>For any non-root and non-leaf node x in the forest, (p, x).B is smaller than any (x, c).B, where p is x's parent and c is x's child;</li>
	<li>All nodes in the forest have at most M children.</li>
	<li>The forest should contain exactly N edges.</li>
</ol>

<p>To simplify the problem, it is guaranteed that wi in any tuple is unique, i.e. no two tuples with the same wi.</p>

<p>Output the number of trees in such forest (the forest should have the minimum number of trees).</p>

### 입력 

 <p>The first line contains two integers: N M(1 ≤ N, M ≤ 100,000) in a line denoting the number of tuples and the maximum number of children for each node in the forest. The next N following lines, each contains three integers: u<sub>i</sub> v<sub>i</sub> w<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ 2,000,000,000; 1 ≤ w<sub>i</sub> ≤ N) in a line denoting the tuple (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>). It is guaranteed that there will be no two tuples with the same w<sub>i</sub>. </p>

### 출력 

 <p>The output contains an integer denoting the number of trees in a forest with a minimum number of trees which satisfies the given requirements, in a line.</p>


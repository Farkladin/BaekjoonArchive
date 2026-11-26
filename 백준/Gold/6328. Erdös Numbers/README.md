# [Gold III] Erdös Numbers - 6328 

[문제 링크](https://acmicpc.net/problem/6328) 

### 성능 요약

메모리: 3192 KB, 시간: 40 ms

### 분류

너비 우선 탐색, 자료 구조, 그래프, 그래프 탐색, 해시를 사용한 집합과 맵, 집합과 맵, 문자열

### 제출 일자

2026년 11월 26일 16:43:57

### 문제 설명

<p>The Hungarian Paul Erdös (1913–1996, pronounced as “Ar-dish”) was not only one of the strangest mathematicians of the 20th century, he was also among the most famous ones. He kept on publishing widely circulated papers up to a very high age, and every mathematician having the honor of being a co-author to Erdös is well respected.</p>

<p>Not everybody got a chance to co-author a paper with Erdös, so many people were content if they managed to publish a paper with somebody who had published a paper with Erdös. This gave rise to the so-called Erdös numbers. An author who has jointly published with Erdös had Erdös number 1. An author who had not published with Erdös but with somebody with Erdös number 1 obtained Erdös number 2, and so on. Today, nearly everybody wants to know what Erdös number he or she has. Your task is to write a program that computes Erdös numbers for a given set of scientists.</p>

### 입력 

 <p>The input file contains a sequence of scenarios, each scenario consisting of a paper database and a list of names. A scenario begins with the line “p n”, where p and n are natural numbers with 1 ≤ p ≤ 32000; 1 ≤ n ≤ 3000. Following this line are p lines containing descriptions of papers (this is the paper database). A paper is described by a line of the following form:</p>

<pre>LastName1, FirstName1, LastName2, Firstname2,...: TitleOfThePaper</pre>

<p>The names and the title may contain any ASCII characters between 32 and 126 except commas and colons. There will always be exactly one space character following each comma. The first name may be abbreviated, but the same name will always be written in the same way. In particular, Erdös’ name is always written as “Erdös, P. (Umlauts like ‘ö’,‘ä’,. . . are simply written as ‘o’,‘a’, . . . .)</p>

<p>Example:</p>

<pre>Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factors matrices.</pre>

<p>After the p papers follow n lines each containing exactly one name in the same format as in the paper database.</p>

<p>The line ‘0 0’ terminates the input.</p>

<p>No name will consist of more than 40 characters. No line in the input file contains more than 250 characters. In each scenario there will be at most 10 000 different authors.</p>

### 출력 

 <p>For every scenario first print the number of the scenario in the format shown in the sample output. Then print for every author name in the list of names their Erdös number based on the papers in the paper database of the scenario. The authors should be output in the order given in the input file. Authors that do not have any relation to Erdös via the papers have Erdös number infinity. Adhere to the format shown in the sample output.</p>


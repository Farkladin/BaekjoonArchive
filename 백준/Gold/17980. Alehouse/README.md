# [Gold IV] Alehouse - 17980 

[문제 링크](https://acmicpc.net/problem/17980) 

### 성능 요약

메모리: 2864 KB, 시간: 32 ms

### 분류

정렬, 스위핑

### 제출 일자

2026년 11월 26일 16:43:57

### 문제 설명

<p>Making friends can seem impossible, but going to the alehouse makes it easy — it is actually the only way to make friendships. Luckily, the alehouse is extremely good at its task: if two people are inside simultaneously, they instantly become friends. People even become friends if they meet each other in the door as one leaves and one enters the alehouse!</p>

<p>In Consistentville, each of its n residents goes to the alehouse exactly once each week, and always during the same milliseconds as the week before. This is convenient for everyone, since then nobody needs to befriend new people all the time, which can be quite exhausting.</p>

<p>You are contemplating a move to Consistentville in order to adopt their well-ordered lifestyle, and have decided that you want as many friends as possible. However, you don’t actually enjoy ale that much, so you decide to limit your weekly visit at the alehouse to at most k milliseconds. What is the maximum number of friends you can get?</p>

### 입력 

 <p>The first line of input contains two positive integers n (1 ≤ n ≤ 100 000), and k (0 ≤ k < 604 800 000). The next n lines describe at which millisecond each of the original residents of Consistentville enters and leaves the alehouse every week. Specifically, the i<sup>th</sup> line consists of two integers a<sub>i</sub> and b<sub>i</sub> (0 ≤ a<sub>i</sub> ≤ b<sub>i</sub> < 604 800 000) indicating that the i<sup>th</sup> resident enters the alehouse at millisecond a<sub>i</sub> and leaves the alehouse at millisecond b<sub>i</sub> each week.</p>

### 출력 

 <p>A single integer, the maximum number of friends you can get.</p>


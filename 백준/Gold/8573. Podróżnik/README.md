# [Gold V] Podróżnik - 8573 

[문제 링크](https://acmicpc.net/problem/8573) 

### 성능 요약

메모리: 2088 KB, 시간: 8 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2026년 11월 26일 16:43:57

### 문제 설명

<p>Podróżnik Bajtonson wrócił właśnie z kolejnej podróży w nieznane. Z oczywistych względów nie mógł wspomagać się mapą, więc notował jedynie, w którą stronę podróżuje. Dlatego zawsze po pokonaniu kilometra notował kierunek, w jakim się poruszał - <code>N</code>, <code>S</code>, <code>E</code> lub <code>W</code> (odpowiednio północ, południe, wschód lub zachód).</p>

<p>Jako że w notesie było niewiele miejsca, podróżnik korzystał ze skrótów np. <code>10 NSSW</code> oznaczało, że Bajtonson 10 razy powtórzył sekwencję "1 km na północ, 2 km na południe, 1 km na zachód". W miejscu, w którym kończył dany odcinek trasy (opisany skrótem), zaczynał następny.</p>

<p>Po powrocie do domu, podróżnik zapragnął narysować mapę swoich podróży. Zdecydował, że każdemu kilometrowi jego podróży będzie odpowiadał jeden centymetr na mapie. Teraz potrzebuje kupić odpowiedni arkusz papieru, nie jest jednak w stanie ocenić, jak dużego arkusza będzie potrzebował. Dlatego poprosił Ciebie, swojego asystenta, o napisanie programu, który przetworzy zapiski z podróży i wyznaczy wymiary najmniejszego (pod względem pola powierzchni) arkusza, na którym zmieści się trasa Bajtonsona.</p>

<p>Oczywiście - jak każda mapa - mapa Bajtonsona musi być prostokątem o bokach równoległych do osi północ-południe i wschód-zachód.</p>

### 입력 

 <p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą $n$ ($1 ≤ n ≤ 1\,000$). W $n$ następnych wierszach opisane są kolejne etapy podróży Bajtonsona. W $i$-tym z tych wierszy znajduje się liczba całkowita $k_i$ ($1 ≤ k_i ≤ 20\,000$) a po odstępie niepusty ciąg znaków złożony z liter <code>N</code>, <code>S</code>, <code>E</code> i <code>W</code>. Taki zapis oznacza, że w ramach $i$-tego etapu Bajtonson $k_i$ razy powtórzył podaną sekwencję kierunków. Liczba znaków <code>N</code>, <code>S</code>, <code>E</code> i <code>W</code> na wejściu nie przekroczy $1\,000\,000$.</p>

### 출력 

 <p>Twój program powinien wypisać na standardowe wyjście dwie liczby całkowite oddzielone pojedynczym odstępem: wysokość i szerokość najmniejszego arkusza, na którym zmieści się trasa podróżnika, wyrażone w centymetrach. Możesz założyć, że obie liczby będą nie większe niż $1\,000\,000\,000$.</p>


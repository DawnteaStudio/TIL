# [Bronze II] Late Larry - 34429 

[문제 링크](https://www.acmicpc.net/problem/34429) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학, 구현, 문자열, 사칙연산, 파싱

### 제출 일자

2026년 4월 7일 01:15:51

### 문제 설명

<p>Larry is a hard-working and honest programmer, who has been one of the most productive engineers in his company. His bosses are even looking to promote him... <strong>but</strong> there is a problem: Larry is always late. Larry's bosses recently told him that if he does not improve his promptness he will not be promoted.</p>

<p>Larry asks you to help him get to his appointments on time. He tells you that he never knows when to leave for meetings and appointments, though he admits he always knows how many minutes it will take to get to the meeting. Luckily he never has to travel more than $24$ hours from where he is for a meeting; however, if the meeting is far away, he may have to leave the day before to arrive at his meeting on time.</p>

### 입력 

 <ul>
	<li>
	<p>The first line contains the scheduled time of the meeting.</p>

	<p>The scheduled meeting time is in the format "$h$:$m$ $d$", where $h$ is the hour of the day ($1\leq h\leq 12$) and $m$ is the number of minutes ($0 \leq m < 60$). $m$ (an integer) is always given as two digits (i.e., left-padded with zeros), but $h$ (also an integer) is not left-padded with zeros if it is only one digit. Finally $d$ is either "AM" or "PM".</p>
	</li>
	<li>
	<p>The second line contains the time it takes Larry to arrive at the meeting. This time is an integer number of minutes $t$ ($1\leq t \leq 1440 = 24*60$).</p>
	</li>
</ul>

### 출력 

 <p>Output the time Larry will need to leave in order to make his appointment or meeting on time. The output should be in the format "$h$:$m$ $d$" (like the input), where $h$ is the hour of the day ($1\leq h\leq 12$) and $m$ is the number of minutes ($0 \leq m < 60$). $m$ (an integer) is always given as two digits (i.e.,\ left-padded with zeros) but $h$ (also an integer) is not left-padded with zeros. Finally $d$ should be "AM" or "PM".</p>


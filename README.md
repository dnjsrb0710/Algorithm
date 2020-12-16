# Algorithm


## COMP319 / 알고리즘 / 2020 / 1학기 / 장길진

## 과제 1
> #### 숫자들로 이루어진 입력 파일을 읽어서 숫자를 저장하고 최대값, 최소값, 평균을 출력하는 프로그램을 작성한다.
>>코드 :  [min_max_avg.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C1/min_max_avg.c)

<br>

## 과제 2
> #### 다음과 같이 주어진 [입출력 조건](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/hw2_v2.pdf)에 따라 삽입(insertion), 선택(selection), 거품(bubble) 정렬 알고리즘을 구현한다.
>>코드 :  [template_sort_int_simple.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/template_sort_int_simple.c) , [template_sort_chararray_simple.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/template_sort_chararray_simple.c) , [template_sort_string_simple.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/template_sort_string_simple.c) <br>
>>입력파일 : **text** - [input10.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/input10) , [input1234.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/input1234)  **arry** - [imagine](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/imagine) , [ihaveadream](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C2/ihaveadream) 

<br>

## 과제 3 
>[문제 설명](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C3/alg2020-hw3_200608_update%20(1).pdf) <br>
> 1. max heap 을 이용하여 오름차순 정렬을 구현한다.  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C3/hw3_1.c) <br>
> 2. min heap 을 이용하여 오름차순 정렬을 구현한다.  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C3/hw3_2.c) <br>
> 3. Median 을 찾기 위한 Heap 구현 및 이를 이용한 sort.  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C3/hw3_3.c)<br>
>> 입력파일 : [input](https://github.com/dnjsrb0710/Algorithm/tree/master/%EA%B3%BC%EC%A0%9C3/input)

<br>

## 과제 4
>[문제설명](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C4/alg2020-hw4%20(1).pdf) <br>
> <br>목적: 단어의 출현회수 세기. 공백으로 분할된 단어(word)들이 전체 파일에서 몇 번 있는지 수를 세고,
출현회수의 내림차순으로(큰 것에서 작은 것으로) 단어-출현회수를 저장한다.
입력: 텍스트 파일
출력: 텍스트 파일, 단어와 출현회수만 출력  <br><br>
> 코드 : [countword.c](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C4/countwords.c)<br>
> 입력파일 : [input](https://github.com/dnjsrb0710/Algorithm/tree/master/%EA%B3%BC%EC%A0%9C4/input)

<br>

## 과제 5
>[문제설명](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/alg2020-hw5%20(2).pdf)<br>
> 1. Longest common subsequence (LCS)  :  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/lcs.c)
> 2. Shortest water slit path  :  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/sws.c) , [코드 설명](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/sws.pdf.pdf)
> 3.  제한된 경로의 길이로 최대한 많은 점 방문하기(forward travelling salesperson) :  [code](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/fts.c)  , [코드 설명](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/fts.pdf)
>> 3번 과제 입력파일 : [input](https://github.com/dnjsrb0710/Algorithm/blob/master/%EA%B3%BC%EC%A0%9C5/hw5-3_ex1.txt)
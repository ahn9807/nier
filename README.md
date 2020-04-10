# 사용법
## XML 파일 작성법
현재 모두 7개의 태그가 주어집니다. 
### scene
XML파일의 시작을 의미합니다.
### automata
오토마타가 어떤 타입을 가지는지 명세합니다. **현재 DFA만 사용가능합니다** 
>type="dfa"
### internal
internal states 가 존재하면 기술합니다. 없어도 작동가능하나, 보다 확실히 하기 위해서 기술합니다. 
>value="array of strings"
### alphabet
오토마타에서 사용되어질 alphabet이 존재하면 기술합니다. 없어도 작동가능하나, 보다 확실히 하기 위해서 기술합니다. 
>value="array of strings"
### initial
오토마타에서 사용되어질 inital value를 명시하기 위해서 적어줍니다. DFA는 여러개의 initial 값이 주어지더라도, 맨 처음값을 기준으로 오토마타를 작동시킵니다. 
>value="array of strings"
### transition
오토마타에서 사용될 $\delta$함수를 정의합니다. 각 State가 어떤 식으로 전의될지 정의합니다. automata의 type이 dfa라면 set태그에 의해 기술된 전의는 output이 여러개라도 맨 처음의 state로 전의됩니다.
>transition
### set
set 태그는 기본적으로 여러개의 함수의 집합을 의미합니다. 주로 transition에서 전의되는 함수들의 관계는 set태그를 이용하여 기술됩니다. 
>set start="string" input="array of strings" output="array of strings"
### EXAMPLE
```
<scene>
	<automata type="dfa"/>
    <internal value="q0 q1 q2 q3 q4"/>
    <alphabet value="0 1"/>
    <initial value="q0"/>
    <transition>
        <set start="q0" input="0" output="q0"/>
        <set start="q0" input="1" output="q1"/>
        <set start="q1" input="0" output="q2"/>
        <set start="q1" input="1" output="q3"/>
        <set start="q2" input="0" output="q4"/>
        <set start="q2" input="1" output="q0"/>
        <set start="q3" input="0" output="q1"/>
        <set start="q3" input="1" output="q2"/>
        <set start="q4" input="0" output="q3"/>
        <set start="q4" input="1" output="q4"/>
    </transition>
    <final value="q0"/>
</scene>
```
## 프로그램 실행방법
### 설치법
git submodule을 설치하고 cmake로 make한뒤 컴파일하시면 됩니다.
### 사용법
1. nier file_path_to_xml 
>./nier ../../scene/hw1.xml
2. nier file_path_to_xml input_language
>./nier ../../scene/hw1.xml 100011
### 예상되는 결과
```
./nier ../../scene/hw1.xml 100011

DFA Automata
Internal States: q0 q1 q2 q3 q4
Input Alphabets: 0 1
delta function: {q0,(0)}->(q0)
delta function: {q0,(1)}->(q1)
delta function: {q1,(0)}->(q2)
delta function: {q1,(1)}->(q3)
delta function: {q2,(0)}->(q4)
delta function: {q2,(1)}->(q0)
delta function: {q3,(0)}->(q1)
delta function: {q3,(1)}->(q2)
delta function: {q4,(0)}->(q3)
delta function: {q4,(1)}->(q4)
Initial States: q0
Final States: q0
Result: Accepted
```
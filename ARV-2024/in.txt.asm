.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/GenLib.lib
ExitProcess PROTO:DWORD 
.stack 4096


 outnum PROTO : DWORD

 outstr PROTO : DWORD

 strcopy PROTO : DWORD, : DWORD

 lenght PROTO : DWORD, : DWORD

 strcmpp  PROTO : DWORD,  : DWORD, : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 sdword 0
		LTRL2 sdword 15
		LTRL3 sdword 2
		LTRL4 sdword 5
		LTRL5 sdword 1
		LTRL6 byte 'max(2, 5): ', 0
		LTRL7 sdword 4
		LTRL8 byte '4 or 2: ', 0
		LTRL9 sdword 6
		LTRL10 byte '4 and 6: ', 0
		LTRL11 sdword 3
		LTRL12 byte 'not 3: ', 0
		LTRL13 byte 'ded', 0
		LTRL14 byte 'deed', 0
		LTRL15 byte 'deb', 0
		LTRL16 byte 'strcmp(ded, ded): ', 0
		LTRL17 byte 'strcmp(ded, deed): ', 0
		LTRL18 byte 'strcmp(ded, deeb): ', 0
		LTRL19 byte '123456', 0
		LTRL20 byte 'lenght(123456): ', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		maxres sdword 0
		maina sdword 0
		mainc sdword 0
		mainstr dword ?
		mainaa sdword 0
		mainab sdword 0
		maincc sdword 0
		maincd sdword 0
		maince sdword 0
		mainstra dword ?
		mainstrb dword ?
		mainstrc dword ?
		mainstrd dword ?
		mainresaa sdword 0
.code

;------------- max --------------
max PROC,
	maxa : sdword, maxb : sdword  
; -------- save registers -------
push ebx
push edx
; -------------------------------
push LTRL1

pop ebx
mov maxres, ebx

mov edx, maxa
cmp edx, maxb

jg right1
jl wrong1
right1:
push maxa

pop ebx
mov maxres, ebx

jmp next1
wrong1:
push maxb

pop ebx
mov maxres, ebx

next1:
; ------ restore registers ------
pop edx
pop ebx
; -------------------------------
mov eax, maxres
ret
max ENDP
;---------------


;------------- MAIN --------------
main PROC
push LTRL2

pop ebx
mov maina, ebx


push maina
call outnum

push offset newline
call outstr


push LTRL4
push LTRL3
call max
push eax
push LTRL5
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov mainc, ebx

mov mainstr, offset LTRL6

push mainstr
call outstr


push mainc
call outnum

push offset newline
call outstr

push LTRL7

pop ebx
mov mainaa, ebx

push LTRL3

pop ebx
mov mainab, ebx

push mainaa
push mainab
pop ebx
pop eax
or eax, ebx
push eax

pop ebx
mov maincc, ebx


push offset LTRL8
call outstr


push maincc
call outnum

push offset newline
call outstr

push LTRL7
push LTRL9
pop ebx
pop eax
and eax, ebx
push eax

pop ebx
mov maincd, ebx


push offset LTRL10
call outstr


push maincd
call outnum

push offset newline
call outstr

push LTRL11
pop eax
not eax
push eax

pop ebx
mov maince, ebx


push offset LTRL12
call outstr


push maince
call outnum

push offset newline
call outstr

mov mainstra, offset LTRL13
mov mainstrb, offset LTRL13
mov mainstrc, offset LTRL14
mov mainstrd, offset LTRL15

push offset LTRL16
call outstr


push mainstrb
push mainstra
push offset buffer
call strcmpp
push eax

pop ebx
mov mainresaa, ebx


push mainresaa
call outnum

push offset newline
call outstr


push offset LTRL17
call outstr


push mainstrc
push mainstra
push offset buffer
call strcmpp
push eax

pop ebx
mov mainresaa, ebx


push mainresaa
call outnum

push offset newline
call outstr


push offset LTRL18
call outstr


push mainstrd
push mainstra
push offset buffer
call strcmpp
push eax

pop ebx
mov mainresaa, ebx


push mainresaa
call outnum

push offset newline
call outstr


push offset LTRL19
push offset buffer
call lenght
push eax

pop ebx
mov mainresaa, ebx


push offset LTRL20
call outstr


push mainresaa
call outnum

push offset newline
call outstr

push offset newline
call outstr

push 0
call ExitProcess
main ENDP
end main

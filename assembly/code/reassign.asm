%define newline 10

section	.text
   global _start     ;must be declared for linker (ld)
_start:             ;tell linker entry point
	
   ;writing the name 'Zara Ali'
   mov	edx,9       ;message length
   mov	ecx, name   ;message to write
   mov	ebx,1       ;file descriptor (stdout)
   mov	eax,4       ;system call number (sys_write)
   int	0x80        ;call kernel
	
   mov edx, 1
   mov ecx, 'A'
   mov ebx, 1
   mov eax, 4
   int 0x80

   ;mov rax, name_2
   ;mov	[name],  eax    ; Changed the name to Nuha Ali
	
   ;writing the name 'Nuha Ali'
   ;mov	rdx, 15       ;message length
   ;mov	rcx,name    ;message to write
   ;mov	rbx,1       ;file descriptor (stdout)
   ;mov	rax,4       ;system call number (sys_write)
   ;int	0x80        ;call kernel
	
   mov	eax,1       ;system call number (sys_exit)
   int	0x80        ;call kernel

section	.data
name db 'Zara Ali '
;name_2 db 'Nuha Anthony', 10

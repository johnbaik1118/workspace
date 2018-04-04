	.file	"test.c"
	.globl	g_iIndex
	.bss
	.align 4
	.type	g_iIndex, @object
	.size	g_iIndex, 4
g_iIndex:
	.zero	4
	.text
	.globl	increment
	.type	increment, @function
increment:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	g_iIndex(%rip), %eax
	addl	$1, %eax
	movl	%eax, g_iIndex(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	increment, .-increment
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
.L3:
	call	increment
	jmp	.L3
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

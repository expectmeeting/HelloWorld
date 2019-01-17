	.file	"multipy.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movq	$1, -24(%rbp)
	movq	$1, -32(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rsi, %rcx
	movl	$0, %ebx
	movq	-32(%rbp), %rsi
	movq	%rsi, %rax
	movl	$0, %edx
	movq	%rbx, %rdi
	imulq	%rax, %rdi
	movq	%rdx, %rsi
	imulq	%rcx, %rsi
	addq	%rdi, %rsi
	mulq	%rcx
	leaq	(%rsi,%rdx), %rcx
	movq	%rcx, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits

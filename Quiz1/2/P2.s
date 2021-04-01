	.file	"P2.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	cvtss2sd	-4(%rbp), %xmm0
	call	round@PLT
	movsd	%xmm0, -16(%rbp)
	cvtss2sd	-8(%rbp), %xmm0
	call	round@PLT
	addsd	-16(%rbp), %xmm0
	cvtsd2ss	%xmm0, %xmm0
	cvttss2si	%xmm0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

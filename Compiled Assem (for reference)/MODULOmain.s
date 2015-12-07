	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$1, %edi
	callq	_lfsr
	xorl	%edi, %edi
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	movl	%edi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_lfsr
	.align	4, 0x90
_lfsr:                                  ## @lfsr
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	$65536, %eax            ## imm = 0x10000
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	cltd
	movl	-16(%rbp), %edi         ## 4-byte Reload
	idivl	%edi
	cmpl	$0, %edx
	je	LBB1_2
## BB#1:
	movl	$65536, %eax            ## imm = 0x10000
	movl	-4(%rbp), %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-20(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	%edx, -24(%rbp)         ## 4-byte Spill
	jmp	LBB1_3
LBB1_2:
	movl	$65536, %eax            ## imm = 0x10000
	movl	-4(%rbp), %ecx
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-28(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	addl	$1, %edx
	movl	%edx, -24(%rbp)         ## 4-byte Spill
LBB1_3:
	movl	-24(%rbp), %eax         ## 4-byte Reload
	movl	%eax, -4(%rbp)
	movw	$-275, -6(%rbp)         ## imm = 0xFFFFFFFFFFFFFEED
	movl	$0, -12(%rbp)
LBB1_4:                                 ## =>This Inner Loop Header: Depth=1
	movzwl	-6(%rbp), %eax
	sarl	$0, %eax
	movzwl	-6(%rbp), %ecx
	sarl	$2, %ecx
	xorl	%ecx, %eax
	movzwl	-6(%rbp), %ecx
	sarl	$3, %ecx
	xorl	%ecx, %eax
	movzwl	-6(%rbp), %ecx
	sarl	$5, %ecx
	xorl	%ecx, %eax
	andl	$1, %eax
	movw	%ax, %dx
	movw	%dx, -8(%rbp)
	movzwl	-6(%rbp), %eax
	sarl	$1, %eax
	movzwl	-8(%rbp), %ecx
	shll	$15, %ecx
	orl	%ecx, %eax
	movw	%ax, %dx
	movw	%dx, -6(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
## BB#5:                                ##   in Loop: Header=BB1_4 Depth=1
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	LBB1_4
## BB#6:
	movzwl	-6(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols

	.file	"J.cpp"
	.text
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_.isra.0
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_.isra.0:
.LFB12706:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	16(%rdx), %rbx
	testq	%rbx, %rbx
	movq	%rcx, %rdi
	movq	%r8, %rsi
	jne	.L2
	jmp	.L15
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L10:
	movq	%rax, %rbx
.L2:
	movq	32(%rbx), %rcx
	movq	24(%rbx), %rax
	cmpq	%rcx, %rsi
	cmovl	16(%rbx), %rax
	setl	%r8b
	testq	%rax, %rax
	jne	.L10
	testb	%r8b, %r8b
	movq	%rbx, %r9
	jne	.L3
	cmpq	%rcx, %rsi
	jg	.L16
.L8:
	movq	%rdi, %rax
	movq	%rbx, (%rdi)
	movq	$0, 8(%rdi)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L15:
	leaq	8(%rdx), %rbx
.L3:
	cmpq	24(%rdx), %rbx
	je	.L17
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbx, %r9
	movq	32(%rax), %rcx
	movq	%rax, %rbx
	cmpq	%rcx, %rsi
	jle	.L8
.L16:
	movq	%rdi, %rax
	movq	$0, (%rdi)
	movq	%r9, 8(%rdi)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	movq	%rdi, %rax
	movq	$0, (%rdi)
	movq	%rbx, 8(%rdi)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_.isra.0
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_.isra.0:
.LFB12707:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	8(%rdx), %rax
	movq	%rcx, %rbp
	movq	%rdx, %rsi
	cmpq	%rax, %r8
	movq	%r8, %rbx
	movq	%r9, %rdi
	je	.L30
	cmpq	%r9, 32(%r8)
	jle	.L22
	cmpq	%r8, 24(%rdx)
	je	.L24
	movq	%r8, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpq	%rdi, 32(%rax)
	jge	.L20
	cmpq	$0, 24(%rax)
	je	.L28
.L24:
	movq	%rbx, %xmm0
	movq	%rbp, %rax
	punpcklqdq	%xmm0, %xmm0
	movups	%xmm0, 0(%rbp)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L22:
	jge	.L25
	cmpq	%r8, 32(%rdx)
	je	.L29
	movq	%r8, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpq	%rdi, 32(%rax)
	jle	.L20
	cmpq	$0, 24(%rbx)
	je	.L29
	movq	%rax, %xmm0
	punpcklqdq	%xmm0, %xmm0
	movups	%xmm0, 0(%rbp)
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L30:
	cmpq	$0, 40(%rdx)
	jne	.L31
.L20:
	movq	%rdi, %r8
	movq	%rsi, %rdx
	movq	%rbp, %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_.isra.0
.L18:
	movq	%rbp, %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	movq	%rbp, %rax
	movq	%r8, 0(%rbp)
	movq	$0, 8(%rcx)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L31:
	movq	32(%rdx), %rax
	cmpq	%r9, 32(%rax)
	jge	.L20
.L28:
	movq	%rax, 8(%rbp)
	movq	%rbp, %rax
	movq	$0, 0(%rbp)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L29:
	movq	$0, 0(%rbp)
	movq	%rbx, 8(%rbp)
	jmp	.L18
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOxEESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOxEESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOxEESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0:
.LFB12708:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rcx, %rsi
	movl	$48, %ecx
	movq	%r8, %rbp
	movq	%rdx, %rdi
	call	_Znwy
	leaq	32(%rsp), %rcx
	movq	%rdi, %r8
	movq	%rsi, %rdx
	movq	%rax, %rbx
	movq	0(%rbp), %rax
	movq	$0, 40(%rbx)
	movq	(%rax), %rbp
	movq	%rbp, 32(%rbx)
	movq	%rbp, %r9
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_.isra.0
	movq	40(%rsp), %r8
	movq	32(%rsp), %rax
	testq	%r8, %r8
	je	.L33
	leaq	8(%rsi), %r9
	testq	%rax, %rax
	movl	$1, %ecx
	je	.L38
.L34:
	movq	%rbx, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rsi)
	movq	%rbx, %rsi
	movq	%rsi, %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L33:
	movq	%rax, %rsi
	movl	$48, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
	movq	%rsi, %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L38:
	cmpq	%r9, %r8
	je	.L34
	xorl	%ecx, %ecx
	cmpq	32(%r8), %rbp
	setl	%cl
	jmp	.L34
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB12710:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	testq	%rcx, %rcx
	movq	%rcx, 112(%rsp)
	je	.L39
.L57:
	movq	112(%rsp), %rax
	movq	24(%rax), %r13
	testq	%r13, %r13
	je	.L41
.L56:
	movq	24(%r13), %r14
	testq	%r14, %r14
	je	.L42
.L55:
	movq	24(%r14), %r15
	testq	%r15, %r15
	je	.L43
.L54:
	movq	24(%r15), %rbx
	testq	%rbx, %rbx
	je	.L44
.L53:
	movq	24(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L45
.L52:
	movq	24(%rdi), %rbp
	testq	%rbp, %rbp
	je	.L46
.L51:
	movq	24(%rbp), %rsi
	testq	%rsi, %rsi
	je	.L47
.L50:
	movq	24(%rsi), %r12
	testq	%r12, %r12
	je	.L48
.L49:
	movq	24(%r12), %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%r12, %rcx
	movq	16(%r12), %r12
	movl	$48, %edx
	call	_ZdlPvy
	testq	%r12, %r12
	jne	.L49
.L48:
	movq	16(%rsi), %r12
	movl	$48, %edx
	movq	%rsi, %rcx
	call	_ZdlPvy
	testq	%r12, %r12
	je	.L47
	movq	%r12, %rsi
	jmp	.L50
.L45:
	movq	16(%rbx), %rsi
	movl	$48, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L44
	movq	%rsi, %rbx
	jmp	.L53
	.p2align 4,,10
	.p2align 3
.L46:
	movq	16(%rdi), %rsi
	movl	$48, %edx
	movq	%rdi, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L45
	movq	%rsi, %rdi
	jmp	.L52
.L44:
	movq	16(%r15), %rbx
	movl	$48, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L43
	movq	%rbx, %r15
	jmp	.L54
	.p2align 4,,10
	.p2align 3
.L47:
	movq	16(%rbp), %rsi
	movl	$48, %edx
	movq	%rbp, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L46
	movq	%rsi, %rbp
	jmp	.L51
.L43:
	movq	16(%r14), %rbx
	movl	$48, %edx
	movq	%r14, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L42
	movq	%rbx, %r14
	jmp	.L55
.L42:
	movq	16(%r13), %rbx
	movl	$48, %edx
	movq	%r13, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L41
	movq	%rbx, %r13
	jmp	.L56
.L41:
	movq	112(%rsp), %rax
	movl	$48, %edx
	movq	16(%rax), %rbx
	movq	%rax, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L39
	movq	%rbx, 112(%rsp)
	jmp	.L57
.L39:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z7mod_pownnn
	.def	_Z7mod_pownnn;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7mod_pownnn
_Z7mod_pownnn:
.LFB10682:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	movaps	%xmm6, 80(%rsp)
	.seh_savexmm	%xmm6, 80
	.seh_endprologue
	xorl	%esi, %esi
	movl	$1, %edi
	movq	8(%rcx), %rbx
	movq	(%rcx), %rcx
	movq	(%rdx), %r12
	movq	8(%rdx), %r13
	movdqa	(%r8), %xmm6
	leaq	64(%rsp), %r14
	movq	%rbx, 72(%rsp)
	leaq	48(%rsp), %rbp
	movq	%rcx, 64(%rsp)
	movq	%r14, %rcx
	movq	%rbp, %rdx
	movaps	%xmm6, 48(%rsp)
	call	__modti3
	movq	%r12, %rdx
	orq	%r13, %rdx
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %rbx
	je	.L94
	.p2align 4,,10
	.p2align 3
.L97:
	movq	%rax, %r15
	movq	%r12, %rax
	xorl	%ecx, %ecx
	andl	$1, %eax
	orq	%rcx, %rax
	je	.L96
	movq	%rbx, %rax
	movq	%r14, %rcx
	movaps	%xmm6, 48(%rsp)
	shrdq	$1, %r13, %r12
	imulq	%rdi, %rax
	sarq	%r13
	imulq	%r15, %rsi
	imulq	%r15, %rbx
	addq	%rax, %rsi
	movq	%rdi, %rax
	mulq	%r15
	addq	%rbx, %rbx
	addq	%rdx, %rsi
	movq	%rbp, %rdx
	movq	%rax, 64(%rsp)
	movq	%rsi, 72(%rsp)
	call	__umodti3
	movq	%r15, %rax
	movq	%r14, %rcx
	mulq	%r15
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rdi
	movq	40(%rsp), %rsi
	addq	%rdx, %rbx
	movq	%rbp, %rdx
	movq	%rax, 64(%rsp)
	movq	%rbx, 72(%rsp)
	call	__umodti3
	movq	%r12, %rdx
	orq	%r13, %rdx
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %rbx
	jne	.L97
.L94:
	movaps	%xmm0, 32(%rsp)
	movq	40(%rsp), %rdx
	movq	%rsi, %xmm1
	movq	%rdi, 32(%rsp)
	movaps	80(%rsp), %xmm6
	movq	%rdx, 40(%rsp)
	movdqa	32(%rsp), %xmm0
	punpcklqdq	%xmm1, %xmm0
	addq	$104, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
	.p2align 3
.L96:
	imulq	%r15, %rbx
	movq	%r15, %rax
	movq	%r14, %rcx
	movaps	%xmm6, 48(%rsp)
	mulq	%r15
	shrdq	$1, %r13, %r12
	sarq	%r13
	addq	%rbx, %rbx
	addq	%rdx, %rbx
	movq	%rbp, %rdx
	movq	%rax, 64(%rsp)
	movq	%rbx, 72(%rsp)
	call	__umodti3
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %rbx
	jmp	.L97
	.seh_endproc
	.p2align 4
	.globl	_Z2fan
	.def	_Z2fan;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2fan
_Z2fan:
.LFB10683:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	.seh_endprologue
	movl	$3, %eax
	movq	(%rdx), %rbp
	movq	8(%rdx), %rbx
	cmpq	%rbp, %rax
	movl	$0, %eax
	movq	%rcx, %r15
	movl	$0, 8(%rcx)
	leaq	8(%rcx), %r14
	sbbq	%rbx, %rax
	movq	$0, 16(%rcx)
	movq	%r14, 24(%rcx)
	movq	%r14, 32(%rcx)
	movq	$0, 40(%rcx)
	jge	.L105
	leaq	80(%rsp), %rax
	movl	$2, %r12d
	movl	$2, %esi
	movq	%rax, 56(%rsp)
	leaq	120(%rsp), %rax
	xorl	%edi, %edi
	movq	%rax, 64(%rsp)
	leaq	112(%rsp), %rax
	leaq	96(%rsp), %r13
	movq	%rax, 72(%rsp)
	.p2align 4,,10
	.p2align 3
.L104:
	movq	%rbp, 96(%rsp)
	movq	%rbx, 104(%rsp)
	movq	%rsi, 80(%rsp)
	movq	%rdi, 88(%rsp)
	.p2align 4,,10
	.p2align 3
.L130:
	movq	56(%rsp), %rdx
	movq	%r13, %rcx
	call	__modti3
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %rdx
	orq	%rdx, %rax
	jne	.L131
	movq	16(%r15), %rcx
	movq	%r12, 120(%rsp)
	movq	%r14, %rdx
	testq	%rcx, %rcx
	jne	.L108
	jmp	.L106
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L133:
	movq	%rcx, %rdx
	movq	%r10, %rcx
	testq	%rcx, %rcx
	je	.L132
.L108:
	cmpq	32(%rcx), %r12
	movq	16(%rcx), %r10
	movq	24(%rcx), %r8
	jle	.L133
	movq	%r8, %rcx
	testq	%rcx, %rcx
	jne	.L108
.L132:
	cmpq	%rdx, %r14
	je	.L106
	cmpq	32(%rdx), %r12
	jge	.L109
.L106:
	movq	64(%rsp), %rax
	movq	%r15, %rcx
	movq	72(%rsp), %r8
	movq	%rax, 112(%rsp)
.LEHB0:
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOxEESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	%rax, %rdx
.L109:
	addq	$1, 40(%rdx)
	movq	%r13, %rcx
	movq	%rbp, 96(%rsp)
	movq	56(%rsp), %rdx
	movq	%rbx, 104(%rsp)
	movq	%rsi, 80(%rsp)
	movq	%rdi, 88(%rsp)
	call	__divti3
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %rbx
	movq	%rax, %rbp
	movq	%rax, 96(%rsp)
	movq	%rbx, 104(%rsp)
	jmp	.L130
	.p2align 4,,10
	.p2align 3
.L131:
	addq	$1, %rsi
	adcq	$0, %rdi
	movq	%rsi, %rax
	addq	$1, %r12
	mulq	%rsi
	movq	%rdi, %rcx
	imulq	%rsi, %rcx
	addq	%rcx, %rcx
	addq	%rdx, %rcx
	cmpq	%rax, %rbp
	movq	%rcx, %rdx
	movq	%rbx, %rcx
	sbbq	%rdx, %rcx
	jge	.L104
.L105:
	movl	$1, %eax
	cmpq	%rbp, %rax
	movl	$0, %eax
	sbbq	%rbx, %rax
	jl	.L134
.L103:
	movq	%r15, %rax
	addq	$136, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L134:
	movq	16(%r15), %rax
	movq	%rbp, 112(%rsp)
	movq	%r14, %rdx
	testq	%rax, %rax
	jne	.L116
	jmp	.L114
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L136:
	movq	%rax, %rdx
	movq	%r8, %rax
	testq	%rax, %rax
	je	.L135
.L116:
	cmpq	32(%rax), %rbp
	movq	16(%rax), %r8
	movq	24(%rax), %rcx
	jle	.L136
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L116
.L135:
	cmpq	%rdx, %r14
	je	.L114
	cmpq	32(%rdx), %rbp
	jge	.L117
.L114:
	leaq	112(%rsp), %rax
	movq	%r15, %rcx
	leaq	120(%rsp), %r8
	movq	%rax, 120(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOxEESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
.LEHE0:
	movq	%rax, %rdx
.L117:
	addq	$1, 40(%rdx)
	jmp	.L103
.L124:
	movq	16(%r15), %rcx
	movq	%rax, %rbx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
.LEHB1:
	call	_Unwind_Resume
	nop
.LEHE1:
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10683:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10683-.LLSDACSB10683
.LLSDACSB10683:
	.uleb128 .LEHB0-.LFB10683
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L124-.LFB10683
	.uleb128 0
	.uleb128 .LEHB1-.LFB10683
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE10683:
	.text
	.seh_endproc
	.p2align 4
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB10708:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$312, %rsp
	.seh_stackalloc	312
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	$1, ans(%rip)
	leaq	176(%rsp), %rdx
.LEHB2:
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	184(%rsp), %rdx
	leaq	144(%rsp), %r12
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	192(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	200(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	184(%rsp), %rax
	leaq	208(%rsp), %rcx
	movq	%r12, %rdx
	movq	192(%rsp), %r14
	movq	%rax, 88(%rsp)
	movq	200(%rsp), %rax
	movq	%r14, %r15
	sarq	$63, %r15
	movq	%rax, 96(%rsp)
	movq	176(%rsp), %rax
	movq	%rax, 144(%rsp)
	sarq	$63, %rax
	movq	%rax, 152(%rsp)
	call	_Z2fan
.LEHE2:
	leaq	256(%rsp), %rax
	movq	%r12, %rdx
	movq	%r14, 144(%rsp)
	movq	%rax, %rcx
	movq	%rax, 104(%rsp)
	movq	%r15, 152(%rsp)
.LEHB3:
	call	_Z2fan
.LEHE3:
	movq	232(%rsp), %r14
	leaq	216(%rsp), %rax
	leaq	264(%rsp), %rbx
	movq	%rax, 80(%rsp)
	movq	%rbx, 64(%rsp)
	leaq	112(%rsp), %r13
	cmpq	%rax, %r14
	je	.L154
	.p2align 4,,10
	.p2align 3
.L138:
	movq	272(%rsp), %rdx
	movq	32(%r14), %rbp
	testq	%rdx, %rdx
	je	.L140
	movq	64(%rsp), %r9
	movq	%rdx, %rax
	jmp	.L142
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L187:
	movq	%r8, %rax
	testq	%rax, %rax
	je	.L186
.L142:
	cmpq	32(%rax), %rbp
	movq	16(%rax), %rcx
	movq	24(%rax), %r8
	jg	.L187
	movq	%rax, %r9
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L142
.L186:
	movq	64(%rsp), %rax
	cmpq	%rax, %r9
	je	.L140
	cmpq	32(%r9), %rbp
	jl	.L140
	movq	%rax, %r15
	jmp	.L144
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L189:
	movq	%rcx, %rdx
	testq	%rdx, %rdx
	je	.L188
.L144:
	cmpq	32(%rdx), %rbp
	movq	16(%rdx), %rax
	movq	24(%rdx), %rcx
	jg	.L189
	movq	%rdx, %r15
	movq	%rax, %rdx
	testq	%rdx, %rdx
	jne	.L144
.L188:
	movq	64(%rsp), %rax
	movq	40(%r14), %rbx
	cmpq	%rax, %r15
	je	.L145
	cmpq	32(%r15), %rbp
	jge	.L146
.L145:
	movl	$48, %ecx
	movq	%r15, 32(%rsp)
.LEHB4:
	call	_Znwy
	movq	32(%rsp), %r8
	movq	%rbp, 32(%rax)
	movq	%rbp, %r9
	movq	%rax, %r15
	movq	104(%rsp), %rdx
	movq	$0, 40(%rax)
	leaq	128(%rsp), %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_.isra.0
	movq	136(%rsp), %r8
	movq	128(%rsp), %rax
	testq	%r8, %r8
	je	.L147
	testq	%rax, %rax
	jne	.L166
	cmpq	%r8, 64(%rsp)
	jne	.L190
.L166:
	movl	$1, %ecx
.L148:
	movq	64(%rsp), %r9
	movq	%r15, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 296(%rsp)
.L146:
	movq	96(%rsp), %rax
	movq	%r12, %rcx
	imulq	40(%r15)
	movq	ans(%rip), %r15
	movq	%rbp, 144(%rsp)
	movq	$998244353, 112(%rsp)
	movq	$0, 120(%rsp)
	movq	%rax, %r8
	movq	88(%rsp), %rax
	movq	%rdx, %r9
	movq	%r15, %r11
	movq	%r15, 48(%rsp)
	imulq	%rbx
	cmpq	%r8, %rax
	movq	%rdx, %rbx
	sbbq	%r9, %rbx
	movq	%rax, %rbx
	movq	%rdx, %rax
	cmovge	%r8, %rbx
	movq	%r13, %rdx
	cmovge	%r9, %rax
	sarq	$63, %r11
	sarq	$63, %rbp
	movq	%r11, 56(%rsp)
	movq	%rbx, %rsi
	movq	%rax, %rdi
	movq	%rbp, 152(%rsp)
	call	__modti3
	movq	%rbx, %rdx
	movq	48(%rsp), %r10
	orq	%rdi, %rdx
	movaps	%xmm0, 32(%rsp)
	movq	56(%rsp), %r11
	movq	32(%rsp), %rax
	movq	40(%rsp), %r8
	je	.L150
	movl	$1, %ebp
	xorl	%ebx, %ebx
	movq	%r15, 72(%rsp)
	.p2align 4,,10
	.p2align 3
.L153:
	movq	%r8, %r15
	movq	%rsi, %r8
	movq	%rax, %r10
	andl	$1, %r8d
	xorl	%r9d, %r9d
	movq	%r8, %rax
	orq	%r9, %rax
	je	.L151
	movq	%r15, %rax
	movq	%r12, %rcx
	movq	%r10, 48(%rsp)
	shrdq	$1, %rdi, %rsi
	movq	$998244353, 112(%rsp)
	imulq	%r10, %rbx
	sarq	%rdi
	movq	$0, 120(%rsp)
	imulq	%rbp, %rax
	addq	%rax, %rbx
	movq	%rbp, %rax
	mulq	%r10
	addq	%rdx, %rbx
	movq	%r13, %rdx
	movq	%rax, 144(%rsp)
	movq	%rbx, 152(%rsp)
	call	__umodti3
	movq	48(%rsp), %r10
	movq	%r12, %rcx
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rbp
	movq	40(%rsp), %rbx
	imulq	%r10, %r15
	movq	%r10, %rax
	mulq	%r10
	addq	%r15, %r15
	addq	%rdx, %r15
	movq	%r13, %rdx
	movq	%rax, 144(%rsp)
	movq	%r15, 152(%rsp)
	call	__umodti3
	movq	%rsi, %rdx
	orq	%rdi, %rdx
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %r8
	jne	.L153
	movq	72(%rsp), %rax
	imulq	%rbp
	movq	%rax, %r10
	movq	%rdx, %r11
.L150:
	movq	%r13, %rdx
	movq	%r12, %rcx
	movq	%r10, 144(%rsp)
	movq	%r11, 152(%rsp)
	movq	$998244353, 112(%rsp)
	movq	$0, 120(%rsp)
	call	__modti3
	movq	%xmm0, ans(%rip)
.L140:
	movq	%r14, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %r14
	movq	80(%rsp), %rax
	cmpq	%rax, %r14
	jne	.L138
.L154:
	movq	ans(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSo9_M_insertIxEERSoT_
	movq	%rax, %rcx
	movq	(%rax), %rax
	movb	$10, 175(%rsp)
	movq	-24(%rax), %rax
	cmpq	$0, 16(%rcx,%rax)
	je	.L155
	leaq	175(%rsp), %rdx
	movl	$1, %r8d
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.L156:
	movq	272(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L160
.L157:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$48, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L157
.L160:
	movq	224(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L137
.L158:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$48, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L158
.L137:
	addq	$312, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
	.p2align 3
.L151:
	imulq	%r10, %r15
	movq	%r10, %rax
	movq	%r12, %rcx
	movq	$998244353, 112(%rsp)
	mulq	%r10
	shrdq	$1, %rdi, %rsi
	movq	$0, 120(%rsp)
	sarq	%rdi
	addq	%r15, %r15
	addq	%rdx, %r15
	movq	%r13, %rdx
	movq	%rax, 144(%rsp)
	movq	%r15, 152(%rsp)
	call	__umodti3
	movaps	%xmm0, 32(%rsp)
	movq	32(%rsp), %rax
	movq	40(%rsp), %r8
	jmp	.L153
	.p2align 4,,10
	.p2align 3
.L147:
	movq	%r15, %rcx
	movl	$48, %edx
	movq	%rax, 32(%rsp)
	call	_ZdlPvy
	movq	32(%rsp), %r15
	jmp	.L146
.L155:
	movl	$10, %edx
	call	_ZNSo3putEc
.LEHE4:
	jmp	.L156
.L190:
	xorl	%ecx, %ecx
	cmpq	32(%r8), %rbp
	setl	%cl
	jmp	.L148
.L168:
	movq	272(%rsp), %rcx
	movq	%rax, %rbx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
.L162:
	movq	224(%rsp), %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
.L167:
	movq	%rax, %rbx
	jmp	.L162
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10708:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10708-.LLSDACSB10708
.LLSDACSB10708:
	.uleb128 .LEHB2-.LFB10708
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB10708
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L167-.LFB10708
	.uleb128 0
	.uleb128 .LEHB4-.LFB10708
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L168-.LFB10708
	.uleb128 0
	.uleb128 .LEHB5-.LFB10708
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE10708:
	.text
	.seh_endproc
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10721:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	_(%rip), %rdx
	movq	$0, 232(%rcx)
	call	_ZNSi10_M_extractIxEERSiRT_
	jmp	.L198
	.p2align 4,,10
	.p2align 3
.L199:
	call	_Z5solvev
.L198:
	movq	_(%rip), %rax
	leaq	-1(%rax), %rdx
	testq	%rax, %rax
	movq	%rdx, _(%rip)
	jne	.L199
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.globl	ans
	.bss
	.align 8
ans:
	.space 8
	.globl	m
	.align 8
m:
	.space 8
	.globl	n
	.align 8
n:
	.space 8
	.globl	_
	.data
	.align 8
_:
	.quad	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.def	__divti3;	.scl	2;	.type	32;	.endef
	.def	__umodti3;	.scl	2;	.type	32;	.endef
	.def	__modti3;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSi10_M_extractIxEERSiRT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin

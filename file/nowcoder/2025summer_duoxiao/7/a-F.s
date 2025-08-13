	.file	"F.cpp"
	.text
	.section	.text$_ZSt3absx,"x"
	.linkonce discard
	.globl	_ZSt3absx
	.def	_ZSt3absx;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3absx
_ZSt3absx:
.LFB30:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	cqto
	xorq	%rdx, %rax
	subq	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3minIxERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3minIxERKT_S2_S2_
	.def	_ZSt3minIxERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3minIxERKT_S2_S2_
_ZSt3minIxERKT_S2_S2_:
.LFB3364:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	(%rax), %rdx
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jge	.L4
	movq	24(%rbp), %rax
	jmp	.L5
.L4:
	movq	16(%rbp), %rax
.L5:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
_ZL3mod:
	.quad	998244353
	.align 8
_ZL4MAXN:
	.quad	500005
	.align 8
_ZL5base1:
	.quad	131
	.align 8
_ZL5base2:
	.quad	127
	.globl	_
	.data
	.align 8
_:
	.quad	1
	.globl	n
	.bss
	.align 8
n:
	.space 8
	.globl	m
	.align 8
m:
	.space 8
	.globl	ans
	.align 8
ans:
	.space 8
	.globl	a
	.align 32
a:
	.space 4000040
	.globl	f
	.align 32
f:
	.space 4000040
	.text
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB10616:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$120, %rsp
	.seh_stackalloc	120
	leaq	112(%rsp), %rbp
	.seh_setframe	%rbp, 112
	.seh_endprologue
	leaq	n(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERx
	movl	$1, -4(%rbp)
	jmp	.L7
.L8:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERx
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L8
	movl	$1, -8(%rbp)
	jmp	.L9
.L14:
	movq	$0, -72(%rbp)
	movq	$1000000000, -80(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L10
.L11:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	addq	%rax, %rdx
	leaq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt3maxIxERKT_S2_S2_
	movq	(%rax), %rax
	movq	%rax, -72(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	addq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt3minIxERKT_S2_S2_
	movq	(%rax), %rax
	movq	%rax, -80(%rbp)
	addl	$1, -12(%rbp)
.L10:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L11
	movq	-72(%rbp), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, -56(%rbp)
	movl	$1, -16(%rbp)
	jmp	.L12
.L13:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rax
	subq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt3absx
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	a(%rip), %rdx
	movq	%rax, (%rcx,%rdx)
	addl	$1, -16(%rbp)
.L12:
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L13
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	movslq	%eax, %rbx
	movq	$40, -64(%rbp)
	leaq	-64(%rbp), %rax
	leaq	n(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSt3minIxERKT_S2_S2_
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	setle	%al
	testb	%al, %al
	jne	.L14
	movq	n(%rip), %rax
	cmpq	$40, %rax
	jg	.L15
	movl	$1, -20(%rbp)
	jmp	.L16
.L20:
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	.L17
.L19:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rax
	cmpq	%rax, %rcx
	je	.L18
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	call	_ZSt3absx
	movq	ans(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, ans(%rip)
	movq	ans(%rip), %rcx
	movabsq	$155014655926305585, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$23, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$998244353, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	movq	%rax, ans(%rip)
.L18:
	addl	$1, -24(%rbp)
.L17:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L19
	addl	$1, -20(%rbp)
.L16:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L20
	movq	ans(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEx
	movl	$10, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	.L6
.L15:
	movq	$0, -32(%rbp)
	movq	$0, -40(%rbp)
	movl	$1, -44(%rbp)
	jmp	.L22
.L25:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	a(%rip), %rax
	movq	(%rdx,%rax), %rax
	testq	%rax, %rax
	jne	.L23
	movq	ans(%rip), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, ans(%rip)
	addq	$1, -32(%rbp)
	jmp	.L24
.L23:
	movq	ans(%rip), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, ans(%rip)
	addq	$1, -40(%rbp)
.L24:
	movq	ans(%rip), %rcx
	movabsq	$155014655926305585, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rdx, %rax
	sarq	$23, %rax
	movq	%rcx, %rdx
	sarq	$63, %rdx
	subq	%rdx, %rax
	imulq	$998244353, %rax, %rdx
	movq	%rcx, %rax
	subq	%rdx, %rax
	movq	%rax, ans(%rip)
	addl	$1, -44(%rbp)
.L22:
	movl	-44(%rbp), %eax
	movslq	%eax, %rdx
	movq	n(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L25
	movq	ans(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEx
	movl	$10, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	nop
.L6:
	addq	$120, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10617:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movl	$0, %edx
	movq	.refptr._ZSt3cin(%rip), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo
	jmp	.L27
.L28:
	call	_Z5solvev
.L27:
	movq	_(%rip), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, _(%rip)
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	jne	.L28
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3maxIxERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3maxIxERKT_S2_S2_
	.def	_ZSt3maxIxERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3maxIxERKT_S2_S2_
_ZSt3maxIxERKT_S2_S2_:
.LFB11362:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rdx
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jge	.L31
	movq	24(%rbp), %rax
	jmp	.L32
.L31:
	movq	16(%rbp), %rax
.L32:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1ELx1000000000EEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1ELx1EEE:
	.byte	1
_ZSt12__is_ratio_vISt5ratioILx1000000000ELx1EEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIoEE:
	.byte	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
	.def	_ZNSirsERx;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEx;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo;	.scl	2;	.type	32;	.endef
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

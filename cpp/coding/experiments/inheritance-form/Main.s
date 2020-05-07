	.file	"Main.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZNK4Form5getIdEv,"axG",@progbits,_ZNK4Form5getIdEv,comdat
	.align 2
	.weak	_ZNK4Form5getIdEv
	.type	_ZNK4Form5getIdEv, @function
_ZNK4Form5getIdEv:
.LFB1493:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1493:
	.size	_ZNK4Form5getIdEv, .-_ZNK4Form5getIdEv
	.section	.text._ZNK4Form7getNameB5cxx11Ev,"axG",@progbits,_ZNK4Form7getNameB5cxx11Ev,comdat
	.align 2
	.weak	_ZNK4Form7getNameB5cxx11Ev
	.type	_ZNK4Form7getNameB5cxx11Ev, @function
_ZNK4Form7getNameB5cxx11Ev:
.LFB1495:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$16, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1495:
	.size	_ZNK4Form7getNameB5cxx11Ev, .-_ZNK4Form7getNameB5cxx11Ev
	.section	.rodata
.LC0:
	.string	"log:"
.LC1:
	.string	"|"
	.text
	.align 2
	.globl	_ZN4FormD2Ev
	.type	_ZN4FormD2Ev, @function
_ZN4FormD2Ev:
.LFB1498:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1498
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	leaq	16+_ZTV4Form(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN4FormD4EvE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK4Form5getIdEv
	movl	(%rax), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK4Form7getNameB5cxx11Ev
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-24(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1498:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1498:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1498-.LLSDACSB1498
.LLSDACSB1498:
.LLSDACSE1498:
	.text
	.size	_ZN4FormD2Ev, .-_ZN4FormD2Ev
	.globl	_ZN4FormD1Ev
	.set	_ZN4FormD1Ev,_ZN4FormD2Ev
	.align 2
	.globl	_ZN4FormD0Ev
	.type	_ZN4FormD0Ev, @function
_ZN4FormD0Ev:
.LFB1500:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4FormD1Ev
	movq	-8(%rbp), %rax
	movl	$48, %esi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1500:
	.size	_ZN4FormD0Ev, .-_ZN4FormD0Ev
	.align 2
	.globl	_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1502:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1502
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	leaq	16+_ZTV4Form(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-24(%rbp), %rax
	leaq	16(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE0:
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB1:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN4FormC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE1:
	jmp	.L10
.L9:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L10:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1502:
	.section	.gcc_except_table
.LLSDA1502:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1502-.LLSDACSB1502
.LLSDACSB1502:
	.uleb128 .LEHB0-.LFB1502
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1502
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L9-.LFB1502
	.uleb128 0
	.uleb128 .LEHB2-.LFB1502
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1502:
	.text
	.size	_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.globl	_ZN4FormC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.set	_ZN4FormC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.rodata
.LC2:
	.string	"ID:"
	.text
	.globl	_ZlsRKSoRK4Form
	.type	_ZlsRKSoRK4Form, @function
_ZlsRKSoRK4Form:
.LFB1504:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK4Form5getIdEv
	movl	(%rax), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK4Form7getNameB5cxx11Ev
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1504:
	.size	_ZlsRKSoRK4Form, .-_ZlsRKSoRK4Form
	.section	.text._ZN6SquareD2Ev,"axG",@progbits,_ZN6SquareD5Ev,comdat
	.align 2
	.weak	_ZN6SquareD2Ev
	.type	_ZN6SquareD2Ev, @function
_ZN6SquareD2Ev:
.LFB1506:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1506
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTV6Square(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN6SquareD4EvE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4FormD2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1506:
	.section	.gcc_except_table
.LLSDA1506:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1506-.LLSDACSB1506
.LLSDACSB1506:
.LLSDACSE1506:
	.section	.text._ZN6SquareD2Ev,"axG",@progbits,_ZN6SquareD5Ev,comdat
	.size	_ZN6SquareD2Ev, .-_ZN6SquareD2Ev
	.weak	_ZN6SquareD1Ev
	.set	_ZN6SquareD1Ev,_ZN6SquareD2Ev
	.section	.text._ZN6SquareD0Ev,"axG",@progbits,_ZN6SquareD5Ev,comdat
	.align 2
	.weak	_ZN6SquareD0Ev
	.type	_ZN6SquareD0Ev, @function
_ZN6SquareD0Ev:
.LFB1508:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6SquareD1Ev
	movq	-8(%rbp), %rax
	movl	$56, %esi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1508:
	.size	_ZN6SquareD0Ev, .-_ZN6SquareD0Ev
	.section	.text._ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi,"axG",@progbits,_ZN6SquareC5EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi,comdat
	.align 2
	.weak	_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.type	_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, @function
_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi:
.LFB1510:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1510
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movq	%rdx, -88(%rbp)
	movl	%ecx, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-72(%rbp), %rbx
	movq	-88(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB3:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE3:
	leaq	-64(%rbp), %rdx
	movl	-76(%rbp), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
.LEHB4:
	call	_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE4:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	16+_ZTV6Square(%rip), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-72(%rbp), %rax
	movl	-80(%rbp), %edx
	movl	%edx, 48(%rax)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB5:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN6SquareC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE5:
	jmp	.L20
.L18:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB6:
	call	_Unwind_Resume@PLT
.L19:
	movq	%rax, %rbx
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4FormD2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE6:
.L20:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1510:
	.section	.gcc_except_table
.LLSDA1510:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1510-.LLSDACSB1510
.LLSDACSB1510:
	.uleb128 .LEHB3-.LFB1510
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB1510
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L18-.LFB1510
	.uleb128 0
	.uleb128 .LEHB5-.LFB1510
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L19-.LFB1510
	.uleb128 0
	.uleb128 .LEHB6-.LFB1510
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE1510:
	.section	.text._ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi,"axG",@progbits,_ZN6SquareC5EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi,comdat
	.size	_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, .-_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.weak	_ZN6SquareC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.set	_ZN6SquareC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi,_ZN6SquareC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.section	.text._ZNK6Square7surfaceEv,"axG",@progbits,_ZNK6Square7surfaceEv,comdat
	.align 2
	.weak	_ZNK6Square7surfaceEv
	.type	_ZNK6Square7surfaceEv, @function
_ZNK6Square7surfaceEv:
.LFB1514:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	48(%rax), %edx
	movq	-8(%rbp), %rax
	movl	48(%rax), %eax
	imull	%edx, %eax
	cvtsi2ss	%eax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1514:
	.size	_ZNK6Square7surfaceEv, .-_ZNK6Square7surfaceEv
	.section	.text._ZN8TriangleD2Ev,"axG",@progbits,_ZN8TriangleD5Ev,comdat
	.align 2
	.weak	_ZN8TriangleD2Ev
	.type	_ZN8TriangleD2Ev, @function
_ZN8TriangleD2Ev:
.LFB1516:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1516
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTV8Triangle(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN8TriangleD4EvE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4FormD2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1516:
	.section	.gcc_except_table
.LLSDA1516:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1516-.LLSDACSB1516
.LLSDACSB1516:
.LLSDACSE1516:
	.section	.text._ZN8TriangleD2Ev,"axG",@progbits,_ZN8TriangleD5Ev,comdat
	.size	_ZN8TriangleD2Ev, .-_ZN8TriangleD2Ev
	.weak	_ZN8TriangleD1Ev
	.set	_ZN8TriangleD1Ev,_ZN8TriangleD2Ev
	.section	.text._ZN8TriangleD0Ev,"axG",@progbits,_ZN8TriangleD5Ev,comdat
	.align 2
	.weak	_ZN8TriangleD0Ev
	.type	_ZN8TriangleD0Ev, @function
_ZN8TriangleD0Ev:
.LFB1518:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN8TriangleD1Ev
	movq	-8(%rbp), %rax
	movl	$56, %esi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1518:
	.size	_ZN8TriangleD0Ev, .-_ZN8TriangleD0Ev
	.section	.text._ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii,"axG",@progbits,_ZN8TriangleC5EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii,comdat
	.align 2
	.weak	_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
	.type	_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii, @function
_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii:
.LFB1520:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1520
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movq	%rdx, -88(%rbp)
	movl	%ecx, -80(%rbp)
	movl	%r8d, -92(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-72(%rbp), %rbx
	movq	-88(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB7:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE7:
	leaq	-64(%rbp), %rdx
	movl	-76(%rbp), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
.LEHB8:
	call	_ZN4FormC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE8:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	16+_ZTV8Triangle(%rip), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-72(%rbp), %rax
	movl	-80(%rbp), %edx
	movl	%edx, 48(%rax)
	movq	-72(%rbp), %rax
	movl	-92(%rbp), %edx
	movl	%edx, 52(%rax)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB9:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZZN8TriangleC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiiE8__func__(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE9:
	jmp	.L31
.L29:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB10:
	call	_Unwind_Resume@PLT
.L30:
	movq	%rax, %rbx
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4FormD2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE10:
.L31:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L28
	call	__stack_chk_fail@PLT
.L28:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1520:
	.section	.gcc_except_table
.LLSDA1520:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1520-.LLSDACSB1520
.LLSDACSB1520:
	.uleb128 .LEHB7-.LFB1520
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB8-.LFB1520
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L29-.LFB1520
	.uleb128 0
	.uleb128 .LEHB9-.LFB1520
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L30-.LFB1520
	.uleb128 0
	.uleb128 .LEHB10-.LFB1520
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
.LLSDACSE1520:
	.section	.text._ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii,"axG",@progbits,_ZN8TriangleC5EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii,comdat
	.size	_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii, .-_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
	.weak	_ZN8TriangleC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
	.set	_ZN8TriangleC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii,_ZN8TriangleC2EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
	.section	.text._ZNK8Triangle7getBaseEv,"axG",@progbits,_ZNK8Triangle7getBaseEv,comdat
	.align 2
	.weak	_ZNK8Triangle7getBaseEv
	.type	_ZNK8Triangle7getBaseEv, @function
_ZNK8Triangle7getBaseEv:
.LFB1522:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$48, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1522:
	.size	_ZNK8Triangle7getBaseEv, .-_ZNK8Triangle7getBaseEv
	.section	.text._ZNK8Triangle9getHeigthEv,"axG",@progbits,_ZNK8Triangle9getHeigthEv,comdat
	.align 2
	.weak	_ZNK8Triangle9getHeigthEv
	.type	_ZNK8Triangle9getHeigthEv, @function
_ZNK8Triangle9getHeigthEv:
.LFB1524:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$52, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1524:
	.size	_ZNK8Triangle9getHeigthEv, .-_ZNK8Triangle9getHeigthEv
	.section	.text._ZNK8Triangle7surfaceEv,"axG",@progbits,_ZNK8Triangle7surfaceEv,comdat
	.align 2
	.weak	_ZNK8Triangle7surfaceEv
	.type	_ZNK8Triangle7surfaceEv, @function
_ZNK8Triangle7surfaceEv:
.LFB1526:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK8Triangle7getBaseEv
	movl	(%rax), %ebx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK8Triangle9getHeigthEv
	movl	(%rax), %eax
	imull	%ebx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cvtsi2ss	%eax, %xmm0
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1526:
	.size	_ZNK8Triangle7surfaceEv, .-_ZNK8Triangle7surfaceEv
	.section	.rodata
.LC3:
	.string	"square"
.LC4:
	.string	"triangle"
	.align 8
.LC5:
	.string	"Calling destructors (reverse order compared to constructors)"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1872:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1872
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$192, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	%edi, -196(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-80(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
.LEHB11:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE11:
	leaq	-80(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movl	$4, %ecx
	movl	$1, %esi
	movq	%rax, %rdi
.LEHB12:
	call	_ZN6SquareC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
.LEHE12:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
.LEHB13:
	call	_Z10print_formRK4Form
.LEHE13:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-176(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
.LEHB14:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE14:
	leaq	-176(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movl	$4, %r8d
	movl	$2, %ecx
	movl	$2, %esi
	movq	%rax, %rdi
.LEHB15:
	call	_ZN8TriangleC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
.LEHE15:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
.LEHB16:
	call	_Z10print_formRK4Form
.LEHE16:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-176(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
.LEHB17:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE17:
	leaq	-176(%rbp), %r12
	movl	$56, %edi
.LEHB18:
	call	_Znwm@PLT
.LEHE18:
	movq	%rax, %rbx
	movl	$6, %r8d
	movl	$2, %ecx
	movq	%r12, %rdx
	movl	$3, %esi
	movq	%rbx, %rdi
.LEHB19:
	call	_ZN8TriangleC1EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii
.LEHE19:
	movq	%rbx, -184(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	-184(%rbp), %rax
	movq	%rax, %rdi
.LEHB20:
	call	_Z10print_formRK4Form
.LEHE20:
	cmpq	$0, -184(%rbp)
	je	.L39
	cmpq	$0, -184(%rbp)
	je	.L40
	movq	-184(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	-184(%rbp), %rdx
	movq	%rdx, %rdi
	call	*%rax
.L40:
	movq	$0, -184(%rbp)
.L39:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-176(%rbp), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
.LEHB21:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE21:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
.LEHB22:
	call	_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE22:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movl	$0, %ebx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN8TriangleD1Ev
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6SquareD1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L53
	jmp	.L65
.L55:
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L43
.L54:
	movq	%rax, %rbx
.L43:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB23:
	call	_Unwind_Resume@PLT
.L58:
	movq	%rax, %rbx
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L45
.L57:
	movq	%rax, %rbx
.L45:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L46
.L62:
	movq	%rax, %r12
	movl	$56, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm@PLT
	movq	%r12, %rbx
	jmp	.L48
.L61:
	movq	%rax, %rbx
.L48:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L49
.L60:
	movq	%rax, %rbx
.L49:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L50
.L64:
	movq	%rax, %rbx
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L52
.L63:
	movq	%rax, %rbx
.L52:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L50
.L59:
	movq	%rax, %rbx
.L50:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN8TriangleD1Ev
	jmp	.L46
.L56:
	movq	%rax, %rbx
.L46:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6SquareD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE23:
.L65:
	call	__stack_chk_fail@PLT
.L53:
	addq	$192, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1872:
	.section	.gcc_except_table
.LLSDA1872:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1872-.LLSDACSB1872
.LLSDACSB1872:
	.uleb128 .LEHB11-.LFB1872
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L54-.LFB1872
	.uleb128 0
	.uleb128 .LEHB12-.LFB1872
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L55-.LFB1872
	.uleb128 0
	.uleb128 .LEHB13-.LFB1872
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L56-.LFB1872
	.uleb128 0
	.uleb128 .LEHB14-.LFB1872
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L57-.LFB1872
	.uleb128 0
	.uleb128 .LEHB15-.LFB1872
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L58-.LFB1872
	.uleb128 0
	.uleb128 .LEHB16-.LFB1872
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L59-.LFB1872
	.uleb128 0
	.uleb128 .LEHB17-.LFB1872
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L60-.LFB1872
	.uleb128 0
	.uleb128 .LEHB18-.LFB1872
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L61-.LFB1872
	.uleb128 0
	.uleb128 .LEHB19-.LFB1872
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L62-.LFB1872
	.uleb128 0
	.uleb128 .LEHB20-.LFB1872
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L59-.LFB1872
	.uleb128 0
	.uleb128 .LEHB21-.LFB1872
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L63-.LFB1872
	.uleb128 0
	.uleb128 .LEHB22-.LFB1872
	.uleb128 .LEHE22-.LEHB22
	.uleb128 .L64-.LFB1872
	.uleb128 0
	.uleb128 .LEHB23-.LFB1872
	.uleb128 .LEHE23-.LEHB23
	.uleb128 0
	.uleb128 0
.LLSDACSE1872:
	.text
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"Form:"
.LC7:
	.string	"Surface:"
	.text
	.globl	_Z10print_formRK4Form
	.type	_Z10print_formRK4Form, @function
_Z10print_formRK4Form:
.LFB1873:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	leaq	.LC6(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRKSoRK4Form
	leaq	.LC7(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rdi
	call	*%rax
	movq	%rbx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1873:
	.size	_Z10print_formRK4Form, .-_Z10print_formRK4Form
	.section	.rodata
.LC8:
	.string	"----"
.LC9:
	.string	"Info:"
.LC10:
	.string	"\t-"
.LC11:
	.string	"---"
	.text
	.globl	_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1874:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC8(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC9(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC10(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC11(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1874:
	.size	_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z4infoRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.weak	_ZTV8Triangle
	.section	.data.rel.ro.local._ZTV8Triangle,"awG",@progbits,_ZTV8Triangle,comdat
	.align 8
	.type	_ZTV8Triangle, @object
	.size	_ZTV8Triangle, 40
_ZTV8Triangle:
	.quad	0
	.quad	_ZTI8Triangle
	.quad	_ZN8TriangleD1Ev
	.quad	_ZN8TriangleD0Ev
	.quad	_ZNK8Triangle7surfaceEv
	.weak	_ZTV6Square
	.section	.data.rel.ro.local._ZTV6Square,"awG",@progbits,_ZTV6Square,comdat
	.align 8
	.type	_ZTV6Square, @object
	.size	_ZTV6Square, 40
_ZTV6Square:
	.quad	0
	.quad	_ZTI6Square
	.quad	_ZN6SquareD1Ev
	.quad	_ZN6SquareD0Ev
	.quad	_ZNK6Square7surfaceEv
	.weak	_ZTV4Form
	.section	.data.rel.ro._ZTV4Form,"awG",@progbits,_ZTV4Form,comdat
	.align 8
	.type	_ZTV4Form, @object
	.size	_ZTV4Form, 40
_ZTV4Form:
	.quad	0
	.quad	_ZTI4Form
	.quad	0
	.quad	0
	.quad	__cxa_pure_virtual
	.weak	_ZTI8Triangle
	.section	.data.rel.ro._ZTI8Triangle,"awG",@progbits,_ZTI8Triangle,comdat
	.align 8
	.type	_ZTI8Triangle, @object
	.size	_ZTI8Triangle, 24
_ZTI8Triangle:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS8Triangle
	.quad	_ZTI4Form
	.weak	_ZTS8Triangle
	.section	.rodata._ZTS8Triangle,"aG",@progbits,_ZTS8Triangle,comdat
	.align 8
	.type	_ZTS8Triangle, @object
	.size	_ZTS8Triangle, 10
_ZTS8Triangle:
	.string	"8Triangle"
	.weak	_ZTI6Square
	.section	.data.rel.ro._ZTI6Square,"awG",@progbits,_ZTI6Square,comdat
	.align 8
	.type	_ZTI6Square, @object
	.size	_ZTI6Square, 24
_ZTI6Square:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS6Square
	.quad	_ZTI4Form
	.weak	_ZTS6Square
	.section	.rodata._ZTS6Square,"aG",@progbits,_ZTS6Square,comdat
	.align 8
	.type	_ZTS6Square, @object
	.size	_ZTS6Square, 8
_ZTS6Square:
	.string	"6Square"
	.weak	_ZTI4Form
	.section	.data.rel.ro._ZTI4Form,"awG",@progbits,_ZTI4Form,comdat
	.align 8
	.type	_ZTI4Form, @object
	.size	_ZTI4Form, 16
_ZTI4Form:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS4Form
	.weak	_ZTS4Form
	.section	.rodata._ZTS4Form,"aG",@progbits,_ZTS4Form,comdat
	.type	_ZTS4Form, @object
	.size	_ZTS4Form, 6
_ZTS4Form:
	.string	"4Form"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2380:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L70
	cmpl	$65535, -8(%rbp)
	jne	.L70
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L70:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2380:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN4FormD2Ev, @function
_GLOBAL__sub_I__ZN4FormD2Ev:
.LFB2381:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2381:
	.size	_GLOBAL__sub_I__ZN4FormD2Ev, .-_GLOBAL__sub_I__ZN4FormD2Ev
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN4FormD2Ev
	.section	.rodata
	.type	_ZZN4FormD4EvE8__func__, @object
	.size	_ZZN4FormD4EvE8__func__, 6
_ZZN4FormD4EvE8__func__:
	.string	"~Form"
	.type	_ZZN4FormC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8__func__, @object
	.size	_ZZN4FormC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8__func__, 5
_ZZN4FormC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE8__func__:
	.string	"Form"
	.type	_ZZN6SquareC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE8__func__, @object
	.size	_ZZN6SquareC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE8__func__, 7
_ZZN6SquareC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE8__func__:
	.string	"Square"
	.align 8
	.type	_ZZN6SquareD4EvE8__func__, @object
	.size	_ZZN6SquareD4EvE8__func__, 8
_ZZN6SquareD4EvE8__func__:
	.string	"~Square"
	.align 8
	.type	_ZZN8TriangleC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiiE8__func__, @object
	.size	_ZZN8TriangleC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiiE8__func__, 9
_ZZN8TriangleC4EiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiiE8__func__:
	.string	"Triangle"
	.align 8
	.type	_ZZN8TriangleD4EvE8__func__, @object
	.size	_ZZN8TriangleD4EvE8__func__, 10
_ZZN8TriangleD4EvE8__func__:
	.string	"~Triangle"
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

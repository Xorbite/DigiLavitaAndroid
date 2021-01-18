/*
 * Copyright 2019 Google LLC

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

/*
 * This program prepares data definitions needed by assembly code
 * in driver.
 */
#pragma warning(disable:4146)
#pragma warning(disable:4013)
#include <stdio.h>
#include <stdlib.h>
#include <linux\kvm_host.h>
#include <arch\x86\kvm\vmx_def.h>
#include <arch\x86\kvm\svm_def.h>
#include <asm\kvm_emulate.h>
#include <intrin.h>

#define ASM_GEN_OFFSET(name, type, field) \
	printf("\t" #name "\tEQU 0%zxh\n", offsetof(type, field))

int main(void)
{
	_ReadWriteBarrier();
	printf("; This is generated by asmgen\n");
	printf("; Please make sure to rerun asmgen after updating\n");
	printf("; key data structures used by both assembly and C.\n\n");

	//struct vcpu_vmx
	printf("\n");
	ASM_GEN_OFFSET(VMX_TO_LAUNCHED, struct vcpu_vmx, __launched);
	ASM_GEN_OFFSET(VMX_TO_FAIL, struct vcpu_vmx, fail);
	ASM_GEN_OFFSET(VMX_TO_RSP, struct vcpu_vmx, host_rsp);
	ASM_GEN_OFFSET(VMX_TO_RAX, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RAX]);
	ASM_GEN_OFFSET(VMX_TO_RBX, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBX]);
	ASM_GEN_OFFSET(VMX_TO_RCX, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RCX]);
	ASM_GEN_OFFSET(VMX_TO_RDX, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDX]);
	ASM_GEN_OFFSET(VMX_TO_RSI, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RSI]);
	ASM_GEN_OFFSET(VMX_TO_RDI, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RDI]);
	ASM_GEN_OFFSET(VMX_TO_RBP, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_RBP]);
	ASM_GEN_OFFSET(VMX_TO_R8, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R8]);
	ASM_GEN_OFFSET(VMX_TO_R9, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R9]);
	ASM_GEN_OFFSET(VMX_TO_R10, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R10]);
	ASM_GEN_OFFSET(VMX_TO_R11, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R11]);
	ASM_GEN_OFFSET(VMX_TO_R12, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R12]);
	ASM_GEN_OFFSET(VMX_TO_R13, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R13]);
	ASM_GEN_OFFSET(VMX_TO_R14, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R14]);
	ASM_GEN_OFFSET(VMX_TO_R15, struct vcpu_vmx, vcpu.arch.regs[VCPU_REGS_R15]);
	ASM_GEN_OFFSET(VMX_TO_CR2, struct vcpu_vmx, vcpu.arch.cr2);

	//struct vcpu_svm
	ASM_GEN_OFFSET(SVM_TO_VMCB_PA, struct vcpu_svm, vmcb_pa);
	ASM_GEN_OFFSET(SVM_TO_RBX, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RBX]);
	ASM_GEN_OFFSET(SVM_TO_RCX, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RCX]);
	ASM_GEN_OFFSET(SVM_TO_RDX, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RDX]);
	ASM_GEN_OFFSET(SVM_TO_RSI, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RSI]);
	ASM_GEN_OFFSET(SVM_TO_RDI, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RDI]);
	ASM_GEN_OFFSET(SVM_TO_RBP, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_RBP]);
	ASM_GEN_OFFSET(SVM_TO_R8, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R8]);
	ASM_GEN_OFFSET(SVM_TO_R9, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R9]);
	ASM_GEN_OFFSET(SVM_TO_R10, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R10]);
	ASM_GEN_OFFSET(SVM_TO_R11, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R11]);
	ASM_GEN_OFFSET(SVM_TO_R12, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R12]);
	ASM_GEN_OFFSET(SVM_TO_R13, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R13]);
	ASM_GEN_OFFSET(SVM_TO_R14, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R14]);
	ASM_GEN_OFFSET(SVM_TO_R15, struct vcpu_svm, vcpu.arch.regs[VCPU_REGS_R15]);

	ASM_GEN_OFFSET(CXT_TO_DST, struct x86_emulate_ctxt, dst.val);
	ASM_GEN_OFFSET(CXT_TO_SRC, struct x86_emulate_ctxt, src.val);
	ASM_GEN_OFFSET(CXT_TO_SRC2, struct x86_emulate_ctxt, src2.val);
}